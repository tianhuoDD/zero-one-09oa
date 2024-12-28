package com.zeroone.star.filemanager.controller;
import cn.hutool.core.date.DateTime;
import com.zeroone.star.filemanager.service.*;
import com.zeroone.star.filemanager.service.IFileAttachmentSharelistService;
import com.zeroone.star.filemanager.service.IFileAttachmentSharelistService;
import com.zeroone.star.filemanager.service.IFileAttachmentSharelistService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.file.*;
import com.zeroone.star.project.j6.file.EnterpriseFileApis;
import com.zeroone.star.project.query.j6.file.*;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.file.FileContentVO;
import com.zeroone.star.project.vo.j6.file.FolderVO;
import com.zeroone.star.project.vo.j6.file.UploadVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.io.InputStreamSource;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Nonnull;
import javax.annotation.Resource;
import javax.annotation.Syntax;
import javax.validation.constraints.NotEmpty;
import java.time.LocalDateTime;

/**
 * @program: oa-java
 * @description: 企业网盘模块控制器
 * @author: Mr.Wang
 * @create: 2024-10-21 15:19
 **/
@RestController
@RequestMapping("enterprise-file")
@Api(tags = "企业网盘模块")
@Validated
public class EnterpriseFileController implements EnterpriseFileApis {

    @Autowired
    private IFileAttachmentSharelistService fileAttachmentSharelistService;
    @Autowired
    private IFileRecycleService fileRecycleService;

    @Resource
    private IFileFolderService fileFolderService;
    @Resource
    private IFileAttachmentService iFileAttachmentService;

    @ApiOperation(value = "删除文件")
    @DeleteMapping("remove-file/{xid}")
    @Override
    public JsonVO<Integer> removeFileAttachment(@PathVariable String xid) {

        int result = iFileAttachmentService.removeFileAttachment(xid);
        if(result != 0){
            //成功
            return JsonVO.success(result);
        }
        //失败
        return JsonVO.fail(result);
    }

    @ApiOperation("重命名文件")
    @PutMapping("modify-file")
    @Override
    public JsonVO<Boolean> modifyFileAttachmentName(FileAttachmentDTO fileAttachmentDTO) {

        Boolean result = iFileAttachmentService.updateFileAttachmentName(fileAttachmentDTO.getXid(), fileAttachmentDTO.getXname(),fileAttachmentDTO.getXfolder(),fileAttachmentDTO.getXlastUpdatePerson(),fileAttachmentDTO.getXextension());
        if(result){
            //成功
            return JsonVO.success(result);
        }else{
            //失败
            return JsonVO.fail(result);
        }
    }

    @ApiOperation("重命名目录")
    @PutMapping("modify-folder")
    @Override
    public JsonVO<Boolean> modifyFileFolderName(FileFolderDTO fileFolderDTO) {

        Boolean result = fileFolderService.updateFileFolderName(fileFolderDTO.getXid(),fileFolderDTO.getXname(),fileFolderDTO.getXsuperior());
        if(result){
            //成功
            return JsonVO.success(result);
        }else{
            //失败
            return JsonVO.fail(result);
        }
    }


    @ApiOperation("上传文件")
    @PostMapping("upload-file")
    @Override
    public JsonVO<UploadVO> uploadFile(@Validated UploadFileDTO uploadFileDTO) {
//        开始时间
        long startTime = System.currentTimeMillis();

        UploadVO uploadVO = iFileAttachmentService.uploadFile(uploadFileDTO);
        //结束时间
        long endTime = System.currentTimeMillis();
        //        耗时
        long duration = endTime - startTime;

        uploadVO.setSpent(duration);
        return JsonVO.success(uploadVO);
    }

    @ApiOperation("下载文件")
    @GetMapping(value = "download-file")
    @Override
    public JsonVO<String> downloadFile(@Validated DownloadFileDTO downloadFileDTO) {


        return JsonVO.success(iFileAttachmentService.downloadFile(downloadFileDTO));
    }

    @ApiOperation("分页查询共享用户列表")
    @GetMapping("/shared-users")
    @Override
    public JsonVO<PageDTO<ShareUserDTO>> queryShareUserList( ShareUserQuery query) {
        PageDTO<ShareUserDTO> page = fileAttachmentSharelistService.getShareUserList(query);
        return JsonVO.success(page);
    }

    @ApiOperation("分页查询指定共享用户的共享文件列表")
    @GetMapping("/shared-files")
    @Override
    public JsonVO<PageDTO<ShareFileDTO>> queryShareFileList( ShareFileQuery query) {
        PageDTO<ShareFileDTO> page = fileAttachmentSharelistService.getShareFilesOfUser(query);
        return JsonVO.success(page);
    }

    @Override
    @ApiOperation("发布可下载共享文件")
    @PostMapping("/share-download")
    public JsonVO<Boolean> downloadShareFile(DownLoadShareDTO downLoadShareDTO) {
        Boolean ok = fileAttachmentSharelistService.downLoadAbleFile(downLoadShareDTO);
        return JsonVO.success(ok);
    }


    @Override
    @ApiOperation("发送可编辑共享文件")
    @PostMapping("/send_edit")
    public JsonVO<Boolean> sendShareFile(SendEditShareDTO sendShareFileDTO) {
        Boolean ok = fileAttachmentSharelistService.editAbleFile(sendShareFileDTO);
        return JsonVO.success(ok);
    }

    @ApiOperation("添加目录")
    @PutMapping("fold-add")
    public JsonVO<Integer> addFolder(FileFolderDTO fileFolderDTO) {
        Integer flag = fileFolderService.insertFolder(fileFolderDTO);
        if (flag == -1){
            return JsonVO.fail(flag);
        }else{
            return JsonVO.success(flag);
        }
    }

    @ApiOperation("删除目录")
    @DeleteMapping("fold-rm/{xid}")
    public JsonVO<Integer> rmFolderById(@PathVariable("xid") String xId) {
        return JsonVO.success(fileFolderService.rmFolderById(xId));
    }

    @ApiOperation("查看目录内容（分页）")
    @GetMapping("fold-query")
    public JsonVO<FileContentVO> listFolder(FolderQuery folderQuery) {
        FileContentVO fileContentVO = new FileContentVO();
        fileContentVO.setFileFolders(fileFolderService.getPageFolder(folderQuery));
        fileContentVO.setFileAttachments(iFileAttachmentService.getPageAttachment(folderQuery));
        return JsonVO.success(fileContentVO);
    }

    @Override
    @ApiOperation("分页查询指定接收用户的接收文件列表")
    @PostMapping("/received/files")
    public JsonVO<PageDTO<ReceivedFileDTO>> queryReceivedFileList(@RequestBody ReceivedFileQuery query) {
        PageDTO<ReceivedFileDTO> page = fileRecycleService.getReceivedFileList(query);
        return JsonVO.success(page);
    }

    @Override
    @ApiOperation("分页查询接收用户列表")
    @PostMapping("/received/users")
    public JsonVO<PageDTO<ReceivedUserDTO>> queryReceivedUserList(@RequestBody ReceivedUserQuery query) {
        PageDTO<ReceivedUserDTO> page = fileRecycleService.getReceivedUserList(query);
        return JsonVO.success(page);
    }

}
