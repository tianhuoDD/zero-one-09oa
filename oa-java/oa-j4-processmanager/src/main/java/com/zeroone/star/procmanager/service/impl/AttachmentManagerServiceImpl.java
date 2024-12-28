package com.zeroone.star.procmanager.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.procmanager.entity.PpEFile;
import com.zeroone.star.procmanager.service.AttachmentManagerService;
import com.zeroone.star.procmanager.service.FileService;
import com.zeroone.star.procmanager.source.AttachmentSource;
import com.zeroone.star.procmanager.utils.DfsUtils;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j4.procmanager.attachment.AttachmentDTO;
import com.zeroone.star.project.vo.JsonVO;
import lombok.RequiredArgsConstructor;
import org.springframework.messaging.Message;
import org.springframework.messaging.support.MessageBuilder;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.*;

@Service
@RequiredArgsConstructor
public class AttachmentManagerServiceImpl implements AttachmentManagerService {
    private final static Set<String> allowedSuffixes = new HashSet<>();
    static {
        allowedSuffixes.add("pdf");
        allowedSuffixes.add("jpg");
        allowedSuffixes.add("jepg");
        allowedSuffixes.add("doc");
        allowedSuffixes.add("docx");
        allowedSuffixes.add("png");
        allowedSuffixes.add("txt");
        allowedSuffixes.add("xlsx");
    }
    private final static long maxFileLength = 4194304 ; //假设允许最大的文件大小为4m

    private final FileService fileService;

    private final FastDfsClientComponent fastDfsClient;

    private final AttachmentSource attachmentSource;

    private final UserHolder userHolder;

    /**
     * 新增附件
     *
     * @param multipartFile
     * @return com.zeroone.star.project.vo.JsonVO<java.lang.String>
     * @author 夜寻
     * @create 2024/10/21
     **/

    @Override
    public JsonVO<String> saveAttachment(String applicationId,MultipartFile multipartFile,String attachmentId) {
        //获取文件名
        String filename = multipartFile.getOriginalFilename();
        //获取文件的后缀
        String suffix = null;
        if (filename != null) {
            suffix = filename.substring(filename.lastIndexOf('.')+1);
        }
        //获取文件大小(单位 B )
        long fileLength = multipartFile.getSize();
        //判断文件类型以及大小是否合法
        if(!allowedSuffixes.contains(suffix)){
            //文件类型不合法，返回错误信息
            return JsonVO.fail("不符合上传类型!!!");
        }
        if (fileLength > maxFileLength){
            //文件大小不合法，返回错误信息
            return JsonVO.fail("文件过大!!!");
        }

        //判断是否有同名附件
        PpEFile sameNameFile = fileService.lambdaQuery().eq(PpEFile::getXname, filename).one();
        if(sameNameFile != null){
            //已有同名文件，返回错误信息
            return JsonVO.fail("已存在该附件!!!");
        }


        PpEFile file = concreteFile(filename, fileLength,attachmentId,applicationId);
        if(attachmentId != null){
            //若附件已经存在，则更新数据库即可
            Boolean isSuccess = updateFile(file);
            if(!isSuccess) return JsonVO.fail("上传数据库失败");
        }else {
            //附件不存在，将file存入数据库
            boolean isSuccess = fileService.save(file);
            if(!isSuccess) return JsonVO.fail("存入数据库失败");
        }

        //将上传文件交给消息队列处理
        try {
            //构建消息
            Message<byte[]> message = MessageBuilder
                    .withPayload(multipartFile.getBytes())
                    .setHeader("suffix",suffix)
                    .setHeader("xid",file.getXid())
                    .build();
            attachmentSource
                    .attachmentUploadOutput()
                    .send(message);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        return JsonVO.success("上传成功");
    }
    /**
     * 更新附件信息
     *
     * @param attachmentDTO
     * @return com.zeroone.star.project.vo.JsonVO<java.lang.String>
     * @author 夜寻
     * @create 2024/10/21
     **/

    @Override
    public JsonVO<String> updateAttachment(AttachmentDTO attachmentDTO) {
        //构建file
        PpEFile file = new PpEFile();
        BeanUtil.copyProperties(attachmentDTO,file);
        file.setXlastUpdateTime(LocalDateTime.now());
        file.setXupdateTime(LocalDateTime.now());
        //TODO 获取修改附件的人名
        file.setXlastUpdatePerson(null);
        try {
            file.setXlastUpdatePerson(userHolder.getCurrentUser().getUsername());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

        //修改数据库数据
        Boolean isSuccess = updateFile(file);

        //返回响应数据
        return isSuccess ? JsonVO.success("修改成功") : JsonVO.fail("修改失败");
    }

    /**
     * 删除附件
     *
     * @param xids
     * @return com.zeroone.star.project.vo.JsonVO<java.lang.String>
     * @author 夜寻
     * @create 2024/10/21
     **/

    @Override
    public JsonVO<String> removeAttachment(String xids) {

        if(StrUtil.isBlank(xids)){
            return JsonVO.fail("参数为空");
        }

        //分割字符串为一个个id
        List<String> ids = Arrays.asList(xids.split(","));

        //查询需要删除的附件的信息
        List<PpEFile> deleteList = fileService.lambdaQuery()
                        .select(PpEFile::getXid,PpEFile::getXurl)
                        .in(PpEFile::getXid,ids)
                        .list();

        for (PpEFile file : deleteList) {
            //"http://" + nginx + "/" + fileGroup + "/" + remoteFileName + "?token=" + token + "&ts=" + ts;
            String groupAndRemoteFileName = DfsUtils.getGroupAndRemoteFileName(file.getXurl());
            String fileGroup =  groupAndRemoteFileName.substring(0,groupAndRemoteFileName.indexOf("/"));
            String remoteFileName = groupAndRemoteFileName.substring(groupAndRemoteFileName.indexOf("/")+1);
            //从dfs中删除文件
            Integer i = DfsUtils.deleteFromDfs(fileGroup, remoteFileName, fastDfsClient);
            //从数据库中删除数据
            boolean isSuccess = fileService.remove(new QueryWrapper<PpEFile>().eq("xid", file.getXid()));

            if(i != 0 || !isSuccess){
                JsonVO.fail("文件: " + file.getXid() + "删除失败，删除操作终止！");
            }
        }
        return JsonVO.success("所选文件已成功删除");
    }


    /**
     * 根据生成File对象
     *
     * @param filename
     * @param fileLength
     * @param attachmentId
     * @param applicationId
     * @return com.zeroone.star.procmanager.entity.File
     * @author 夜寻
     * @create 2024/10/21
     **/

    private PpEFile concreteFile(String filename,long fileLength,String attachmentId,String applicationId){
        PpEFile file = new PpEFile();

        file.setXid(attachmentId);
        file.setXfileName(filename);
        file.setXlength(fileLength);
        file.setXname(filename);
        //TODO 获取更新附件的人名
        file.setXlastUpdatePerson(null);
        try {
            file.setXlastUpdatePerson(userHolder.getCurrentUser().getUsername());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        file.setXupdateTime(LocalDateTime.now());
        file.setXlastUpdateTime(LocalDateTime.now());
        String length = calculateFileLength(fileLength);
        file.setXdescription(filename + " " + length);

        //若附件已经存在，只是修改文件，则下列属性无需修改
        if(attachmentId == null){
            String xid = UUID.randomUUID().toString();
            file.setXid(xid);
            file.setXcreateTime(LocalDateTime.now());
            file.setXsequence(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss"))+xid);
            //TODO 完成distributeFactor的赋值
            file.setXdistributeFactor(null);
            file.setXalias(null);
            file.setXapplication(applicationId);
        }

        return file;
    }

    /**
     *  计算文件适合的单位进行展示
     * @param fileLength
     * @return java.lang.String
     * @author 夜寻
     * @create 2024/10/21
     **/

    private String calculateFileLength(long fileLength){
        double length;
        if(fileLength < 1024){
            return fileLength + " " + "B" ;
        }
        length = (double) fileLength / 1024 ;

        if(length < 1024){
            return String.format("%.2f", (length)) + " " + "K" ;
        }

        return  String.format("%.2f", (length / 1024)) + " " + "m";
    }

    /**
     * 修改数据库数据
     *
     * @param file
     * @return java.lang.Boolean
     * @author 夜寻
     * @create 2024/10/22
     **/

    private Boolean updateFile(PpEFile file){
        boolean isSuccess = fileService
                .lambdaUpdate()
                .set(file.getXname() != null, PpEFile::getXname, file.getXname())
                .set(file.getXdescription() != null, PpEFile::getXdescription, file.getXdescription())
                .set(file.getXlength() != null, PpEFile::getXlength, file.getXlength())
                .set(file.getXalias() != null, PpEFile::getXalias, file.getXalias())
                .set(file.getXfileName() != null, PpEFile::getXfileName, file.getXfileName())
                .set(file.getXlastUpdateTime() != null, PpEFile::getXlastUpdateTime, file.getXlastUpdateTime())
                .set(file.getXupdateTime() != null, PpEFile::getXupdateTime, file.getXupdateTime())
                .set(file.getXlastUpdatePerson() != null, PpEFile::getXlastUpdatePerson, file.getXlastUpdatePerson())
                .set(file.getXurl() != null,PpEFile::getXurl,file.getXurl())
                .eq(PpEFile::getXid,file.getXid())
                .update();
        return isSuccess;
    }

}
