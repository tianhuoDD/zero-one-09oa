package com.zeroone.star.filemanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.filemanager.entity.FileAttachment;
import com.zeroone.star.filemanager.service.impl.FileAttachmentServiceImpl;
import com.zeroone.star.project.dto.j6.file.DownloadFileDTO;
import com.zeroone.star.project.dto.j6.file.UploadFileDTO;
import com.zeroone.star.project.query.j6.file.FolderQuery;
import com.zeroone.star.project.vo.j6.file.FileAttachmentVO;
import com.zeroone.star.project.dto.j6.file.FileAttachmentDTO;
import com.zeroone.star.project.vo.j6.file.UploadVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author j6
 * @since 2024-10-23
 */
public interface IFileAttachmentService extends IService<FileAttachment> {
    /**
     * 重命名文件
     * @param xid
     * @param new_xname
     * @param xfolder
     * @param xlastUpdatePerson
     * @return
     */
    public boolean updateFileAttachmentName(String xid,String new_xname,String xfolder,String xlastUpdatePerson,String xextension);
    /**
     * 分页查询指定目录内的文件
     * @return
     */
    List<FileAttachmentVO> getPageAttachment(FolderQuery folderQuery);

    /**
     * 删除文件
     * @param xid
     * @return
     */
    public int removeFileAttachment(String xid);

    /**
     * 上传文件
     * @param uploadFileDTO
     * @return
     */
    UploadVO uploadFile(UploadFileDTO uploadFileDTO);

    /**
     * 下载文件
     * @param downloadFileDTO
     * @return
     */
    String downloadFile(DownloadFileDTO downloadFileDTO);

}
