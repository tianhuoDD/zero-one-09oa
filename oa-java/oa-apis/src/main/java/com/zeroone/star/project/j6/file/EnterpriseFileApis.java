package com.zeroone.star.project.j6.file;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.file.*;
import com.zeroone.star.project.query.j6.file.*;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.file.FileContentVO;
import com.zeroone.star.project.vo.j6.file.FolderVO;
import com.zeroone.star.project.vo.j6.file.UploadVO;
import org.springframework.core.io.InputStreamSource;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

/**
 * @program: oa-java
 * @description: 企业网盘相关接口声明
 * @author: Mr.Wang
 * @create: 2024-10-21 14:34
 **/
public interface EnterpriseFileApis {

    JsonVO<Integer> removeFileAttachment(String xid);

    JsonVO<Boolean> modifyFileAttachmentName(FileAttachmentDTO fileAttachmentDTO);
    /**
     * 修改文件夹名称
     * @param fileFolderDTO
     * @return
     */
    JsonVO<Boolean> modifyFileFolderName(FileFolderDTO fileFolderDTO);

    /**
     * 上传文件
     * @param uploadFileDTO
     * @return
     */
    JsonVO<UploadVO> uploadFile(UploadFileDTO uploadFileDTO);

    /**
     * 下载文件
     * @param downloadFileDTO
     * @return
     */
    JsonVO<String> downloadFile(DownloadFileDTO downloadFileDTO);

    /**
     * 获取共享用户列表（分页）
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<ShareUserDTO>> queryShareUserList(ShareUserQuery query);

    /**
     * 获取指定共享用户共享文件列表（分页）
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<ShareFileDTO>> queryShareFileList(ShareFileQuery query);

    /**
     * 发布可下载的共享文件，指定用户可下载
     * @param downLoadShareDTO 下载共享文件参数，例如文件id，共享用户id列表
     * @return 是否发布成功
     */
    JsonVO<Boolean> downloadShareFile(DownLoadShareDTO downLoadShareDTO);

    /**
     * 发布共享文件, 其他用户可编辑
     * @param sendShareFileDTO 发送共享文件参数，例如文件id，共享用户id列表
     * @return 是否发布成功
     */
    JsonVO<Boolean> sendShareFile(SendEditShareDTO sendShareFileDTO);

    /**
     * 新增目录
     * @param fileFolderDTO 新增目录参数
     * @return 是否删新增成功
     */
    JsonVO<Integer> addFolder(FileFolderDTO fileFolderDTO);

    /**
     * 删除目录
     * @param xId 删除条件
     * @return 是否删除成功
     */
    JsonVO<Integer> rmFolderById(String xId);

    /**
     * 分页查询目录内容
     * @param folderQuery 查询条件
     * @return 查询结果
     */
    JsonVO<FileContentVO> listFolder(FolderQuery folderQuery);
    /**
     * 获取指定接收用户的接收文件列表（分页）
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<ReceivedFileDTO>> queryReceivedFileList(ReceivedFileQuery query);

    /**
     * 获取接收用户列表（分页）
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<ReceivedUserDTO>> queryReceivedUserList( ReceivedUserQuery query);

}
