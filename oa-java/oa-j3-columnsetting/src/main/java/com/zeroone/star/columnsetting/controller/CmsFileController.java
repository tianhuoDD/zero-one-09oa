package com.zeroone.star.columnsetting.controller;


import com.zeroone.star.columnsetting.entity.CmsFile;
import com.zeroone.star.columnsetting.service.ICmsFileService;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.j3.resourcefile.ResourcefileApis;
import com.zeroone.star.project.j3.resourcefile.dto.CmsFileDTO;
import com.zeroone.star.project.j3.resourcefile.vo.CmsFileVO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.IOException;
import java.util.List;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author lfh59 and trigger
 * @since 2024-10-26
 */
@RestController
@RequestMapping("/resourcefile/")
@Api(tags = "附件操作")
public class CmsFileController implements ResourcefileApis {

    @Resource
    private ICmsFileService CmsFileService;

    @Resource
    private FastDfsClientComponent dfsClientComponent;

    @Value("${fastdfs.nginx-servers}")
    private String url;

    /**
     * 获得附件列表
     *
     * @return
     */
    @ApiOperation(value = "获得附件列表")
    @GetMapping("/list/{appId}")
    @Override
    public JsonVO<List<CmsFileVO>> queryFlieAttachmentList(@PathVariable("appId") String xappId) {
        System.out.println(xappId);
        return JsonVO.success(CmsFileService.getAttachmentList(xappId));
    }

    /**
     * 获得附件详情
     *
     * @param xid
     * @return
     */
    @ApiOperation(value = "获得附件详情")
    @GetMapping("/detail/{id}")
    @Override
    public JsonVO<CmsFileVO> queryAttachmentDetail(@PathVariable("id") String xid) {
        System.out.println(xid);
        return JsonVO.success(CmsFileService.getAttachmentDetail(xid));
    }

    /**
     * 新增附件
     *
     * @param file
     * @return
     */
    @ApiOperation(value = "新增附件")
    @PostMapping("/insert")
    @Override
    public JsonVO<Integer> addfile(@RequestParam("file") MultipartFile file,
                                   @RequestParam("username") String username,
                                   @RequestParam("appId") String appId) {
        System.out.println("上传的文件名: " +file.getOriginalFilename());
        String extName = getFileExtension(file.getOriginalFilename());
        byte[] fileContent;
        try {
            fileContent = file.getBytes();
            FastDfsFileInfo fileInfo = dfsClientComponent.uploadFile(fileContent, extName);
            String filePath = "/" + fileInfo.getGroup() + "/" + fileInfo.getStorageId();

            CmsFileDTO cmsFileDTO = parseFileToCmsFileDTO(file,username,appId);
            cmsFileDTO.setXdata(filePath);
            Integer ans = CmsFileService.insertfile(cmsFileDTO,username,appId);
            return JsonVO.success(ans);
        } catch (IOException e) {
            System.out.println("文件读取失败: " + e.getMessage());
            return JsonVO.create(0, -1, "文件读取失败: " + e.getMessage()); // 返回失败状态
        } catch (Exception e) {
            System.out.println("文件上传失败: " + e.getMessage());
            return JsonVO.create(0, -1, "文件上传失败: " + e.getMessage()); // 返回失败状态
        }
    }
    private CmsFileDTO parseFileToCmsFileDTO(MultipartFile file,String username,String appId) throws IOException {
        CmsFileDTO cmsFileDTO = new CmsFileDTO();
        cmsFileDTO.setXfileName(file.getOriginalFilename());
        cmsFileDTO.setXlength(file.getSize());
        cmsFileDTO.setXdescription("Uploaded file: " + file.getOriginalFilename());
        cmsFileDTO.setXalias(file.getOriginalFilename().substring(0, file.getOriginalFilename().lastIndexOf(".")));
        cmsFileDTO.setXsequence("1");
        cmsFileDTO.setXappId(appId);
        cmsFileDTO.setXlastUpdatePerson(username);
        cmsFileDTO.setXdistributeFactor(1);
        cmsFileDTO.setXfileName(file.getName());
        return cmsFileDTO;
    }
    private String getFileExtension(String fileName) {
        if (fileName.lastIndexOf(".") > 0) {
            return fileName.substring(fileName.lastIndexOf(".") + 1);
        }
        return "";
    }

    /**
     * 删除附件
     *
     * @param xid
     * @return
     */
    @ApiOperation(value = "删除附件")
    @DeleteMapping("/delete")
    public JsonVO<Integer> removefile( String xid) {
        if (xid == null) {
            return JsonVO.fail(null);
        }
        CmsFile cmsfile = CmsFileService.getById(xid);
        String xdata = cmsfile.getXdata();

        // 去掉开头的斜杠
        if (xdata.startsWith("/")) {
            xdata = xdata.substring(1);
        }

        // 找到第一个斜杠的位置
        int firstSlashIndex = xdata.indexOf('/');

        // 分割路径
        String group = xdata.substring(0, firstSlashIndex);
        String storageId = xdata.substring(firstSlashIndex + 1);

        int i = 0;
        try {
            i = dfsClientComponent.deleteFile(FastDfsFileInfo.builder().group(group).storageId(storageId).build());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

        if (i != 0) {
            return JsonVO.fail(i);
        }
        Integer ans = CmsFileService.deletefile(xid);
        return JsonVO.success(ans);
    }

    /**
     * 修改附件
     *
     * @param cmsFileDTO
     * @return
     */
    @ApiOperation(value = "修改附件")
    @PutMapping("/update")
    @Override
    public JsonVO<Integer> modifyfile(CmsFileDTO cmsFileDTO) {
        //获取对象
        CmsFile cmsFile = CmsFileService.getById(cmsFileDTO.getXid());
        int i = 0;
        String[] split = cmsFile.getXdata().split("/");
        String group = split[1];
        String groupAndStorage = cmsFile.getXdata().substring(cmsFile.getXdata().indexOf("/") + 1);
        String storageId = groupAndStorage.substring(groupAndStorage.indexOf("/") + 1);

        System.out.println(group);
        System.out.println(storageId);
        //删除旧文件
        try {
            i = dfsClientComponent.deleteFile(FastDfsFileInfo.builder().group(group).storageId(storageId).build());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

        if (i != 0) {
            return JsonVO.fail(i);
        }
        //获取文件名
        String filename = cmsFileDTO.getFile().getOriginalFilename();
        assert filename != null;
        String suffix = filename.substring(filename.lastIndexOf(".") + 1);
        FastDfsFileInfo fastDfsFileInfo;
        //上传新文件
        try {
             fastDfsFileInfo = dfsClientComponent.uploadFile(cmsFileDTO.getFile().getBytes(), suffix);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        //xdata存储group+fileName
        cmsFileDTO.setXdata("/" + fastDfsFileInfo.getGroup()+"/"+fastDfsFileInfo.getStorageId());
        //更新数据库
        Integer ans = CmsFileService.updatefile(cmsFileDTO);
        return JsonVO.success(ans);
    }

    @ApiOperation(value = "Test上传附件")
    @PostMapping("/upload")
    public JsonVO<String> upload(MultipartFile file) throws Exception {
        String filename = file.getOriginalFilename();
        assert filename != null;
        String suffix = filename.substring(filename.lastIndexOf(".") + 1);
        FastDfsFileInfo fastDfsFileInfo = dfsClientComponent.uploadFile(file.getBytes(), suffix);
        if (fastDfsFileInfo != null) {
            return JsonVO.success(dfsClientComponent.fetchUrl(fastDfsFileInfo, url, true));
        }
        return JsonVO.fail("上传失败");
    }
}

