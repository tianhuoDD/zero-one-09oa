package com.zeroone.star.filemanager.service.impl;

import cn.hutool.core.date.DateTime;
import com.alibaba.nacos.api.naming.pojo.healthcheck.impl.Http;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.filemanager.entity.FileAttachment;
import com.zeroone.star.filemanager.mapper.FileAttachmentMapper;
import com.zeroone.star.filemanager.service.IFileAttachmentService;
import com.zeroone.star.project.dto.j6.file.DownloadFileDTO;
import com.zeroone.star.project.dto.j6.file.UploadFileDTO;
import com.zeroone.star.project.query.j6.file.FolderQuery;
import com.zeroone.star.project.vo.j6.file.FileAttachmentVO;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j6.file.FileAttachmentDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.file.UploadVO;
import lombok.SneakyThrows;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.*;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.nio.charset.StandardCharsets;
import java.util.Optional;
import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

import javax.annotation.Resource;
import java.time.LocalDateTime;

@Mapper(componentModel = "spring")
interface UploadFileMapper{

    FileAttachment FileDTO2FileDO(FileAttachmentDTO fileAttachmentDTO);

}
/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author j6
 * @since 2024-10-23
 */


@Service
public class FileAttachmentServiceImpl extends ServiceImpl<FileAttachmentMapper, FileAttachment> implements IFileAttachmentService {
    @Resource
    FileAttachmentMapper fileAttachmentMapper;
    @Override
    public List<FileAttachmentVO> getPageAttachment(FolderQuery folderQuery) {
// 1.准备分页条件
        Page<FileAttachment> page = new Page<>(folderQuery.getPageIndex(), folderQuery.getPageSize());

// 1.2.排序条件
//        page.addOrder(new Page.OrderItem("xid", true));

// 2.分页查询
        // 2.1.创建查询条件 Wrapper
        QueryWrapper<FileAttachment> queryWrapper = new QueryWrapper<>();
//        2.2.查询
        if(folderQuery.getXid() != null){
            queryWrapper.eq("xfolder", folderQuery.getXid());
        }else{
            queryWrapper.eq("xfolder", "");
        }
        Page<FileAttachment> p = fileAttachmentMapper.selectPage(page,queryWrapper);

// 3.解析
        List<FileAttachment> records = p.getRecords();

// 4.复制属性到VO
        List<FileAttachmentVO> fileAttachmentVOs = new ArrayList<>();
        for (FileAttachment record : records) {
            FileAttachmentVO vo = BeanUtil.copyProperties(record, FileAttachmentVO.class);
            fileAttachmentVOs.add(vo);
        }
        return fileAttachmentVOs;
    }

    @Resource
    FastDfsClientComponent dfsClient;
    @Resource
    UserHolder userHolder;

    @Value("${fastdfs.nginx-servers}")
    private String fileServiceUrl;

    @Resource
    private UploadFileMapper uploadFileMapper;

    /**
     * 上传文件
     * @param uploadFileDTO
     * @return
     */

    @SneakyThrows
    @Override
    public UploadVO uploadFile(UploadFileDTO uploadFileDTO) {
        FileAttachmentDTO fileAttachmentDTO = new FileAttachmentDTO();
        //封装当先用户名
        try {
            String username = userHolder.getCurrentUser().getUsername();
            fileAttachmentDTO.setXperson(username);
            fileAttachmentDTO.setXlastUpdatePerson(username);
        } catch (NullPointerException e) {
            throw new RuntimeException("未登录");
        }
        //文件对象
        MultipartFile file = uploadFileDTO.getFile();
        //        获取文件信息
        String originalFilename = file.getOriginalFilename();
//        后缀名
        String suffix = originalFilename.substring(originalFilename.lastIndexOf(".") + 1);
//        文件大小
        long size = file.getSize();
//        dto数据封装
        fileAttachmentDTO.setXcreateTime(LocalDateTime.now());
        fileAttachmentDTO.setXupdateTime(LocalDateTime.now());
        fileAttachmentDTO.setXlastUpdateTime(LocalDateTime.now());
        fileAttachmentDTO.setXlength(size);
        fileAttachmentDTO.setXname(originalFilename);
        fileAttachmentDTO.setXextension(suffix);
        fileAttachmentDTO.setXdeepPath(false);
        if (uploadFileDTO.getXfolder().equals("null")){
            fileAttachmentDTO.setXfolder("");
        }else {
            fileAttachmentDTO.setXfolder(uploadFileDTO.getXfolder());
        }
        //获取文件字节对象
        byte[] fileBytes = file.getBytes();
        //上传文件
        FastDfsFileInfo fastDfsFileInfo = dfsClient.uploadFile(fileBytes, fileAttachmentDTO.getXextension());
        if (fastDfsFileInfo==null){
          throw new RuntimeException("上传失败");
        }
        //封装文件存储ID
        fileAttachmentDTO.setXstorage(fastDfsFileInfo.getStorageId());
        //封装文件排序
        fileAttachmentDTO.setXsequence(DateTime.now().toString("yyyyMMddHHmmss"));
        //TODO 加密
        fileAttachmentDTO.setXencryptKey("");

        //转换
        FileAttachment fileAttachment = uploadFileMapper.FileDTO2FileDO(fileAttachmentDTO);
        //插入数据
          baseMapper.insert(fileAttachment);
        String url = dfsClient.fetchUrl(fastDfsFileInfo, fileServiceUrl, true);
        //vo数据封装
        UploadVO uploadVO = new UploadVO();
        uploadVO.setId(fileAttachment.getXid());
        uploadVO.setDate(new DateTime());
        uploadVO.setSize(file.getSize());
        uploadVO.setUrl(url);
        return uploadVO;
    }

    /**
     * 下载文件
     * @param downloadFileDTO
     * @return
     */
    @SneakyThrows
    @Override
    public String downloadFile(DownloadFileDTO downloadFileDTO) {

        //返回下载链接
        return dfsClient.fetchUrl(FastDfsFileInfo.builder().group(downloadFileDTO.getGroup()).storageId(downloadFileDTO.getStorageId()).build(), fileServiceUrl, true);


        /**

            //通过文件存储id获取文件信息
        FileAttachment fileAttachment = baseMapper.selectOne(new QueryWrapper<FileAttachment>().eq("xstorage", storageId));

        assert fileAttachment!=null;
        //下载文件
        byte[] bytes = dfsClient.downloadFile(FastDfsFileInfo.builder().group(group).storageId(storageId).build());
        FastDfsFileInfo built = FastDfsFileInfo.builder().group(group).storageId(storageId).build();
        HttpHeaders httpHeaders = new HttpHeaders();
        //根据文件名动态获取MediaType
        Optional<MediaType> mediaType = MediaTypeFactory.getMediaType(fileAttachment.getXname());
        //设置文件名
        String filename=DateTime.now().toString("yyyyMMddHHmmss")+"."+fileAttachment.getXextension();

        httpHeaders.setContentDispositionFormData("attachment",filename);

        if (mediaType.isPresent()){
            //获取并写入mediaType
            httpHeaders.setContentType(mediaType.get());
        }else {
            httpHeaders.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        }
        return new ResponseEntity<>(bytes, httpHeaders, HttpStatus.OK);
         */
    }

    /**
     * 重命名文件
     * @param xid
     * @param new_xname
     * @param xfolder
     * @param xlastUpdatePerson
     * @return
     */
    @Override
    public boolean updateFileAttachmentName(String xid, String new_xname,String xfolder,String xlastUpdatePerson,String xextension) {
        if (fileAttachmentMapper.selectById(xid) == null) {
            return false;  // 文件不存在
        }


        QueryWrapper<FileAttachment> nameCheckWrapper = new QueryWrapper<>();
        if (xfolder == null) {
            nameCheckWrapper.isNull("xfolder");
        } else {
            nameCheckWrapper.eq("xfolder", xfolder);
        }

        int index = new_xname.indexOf(".");
        if (index == -1) {
            return false;
        } else{
            new_xname = new_xname.substring(0, index); // 取“.”前的部分
        }
        nameCheckWrapper.eq("xname", new_xname+"."+xextension);
        Long count = fileAttachmentMapper.selectCount(nameCheckWrapper);
        nameCheckWrapper.ne("xid", xid);  // 排除当前文件
        if (count > 0) {
            return false;  // 新名称已存在，操作失败
        }


        FileAttachment fileAttachment = new FileAttachment();
        fileAttachment.setXname(new_xname);
        fileAttachment.setXlastUpdatePerson(xlastUpdatePerson);
        fileAttachment.setXextension(xextension);

        LocalDateTime data = LocalDateTime.now();
        fileAttachment.setXlastUpdateTime(data);

        QueryWrapper<FileAttachment> wq = new QueryWrapper<>();
        wq.eq("xid", xid);
        return this.fileAttachmentMapper.update(fileAttachment, wq) > 0;
    }

    /**
     * 删除文件
     * @param xid
     * @return
     */
    @Override
    public int removeFileAttachment(String xid) {
        return fileAttachmentMapper.deleteById(xid);
    }
}
