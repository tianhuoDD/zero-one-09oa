package com.zeroone.star.filemanager.service;

import com.zeroone.star.filemanager.entity.FileAttachmentSharelist;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.file.ShareFileDTO;
import com.zeroone.star.project.dto.j6.file.ShareUserDTO;
import com.zeroone.star.project.query.j6.file.ShareFileQuery;
import com.zeroone.star.project.query.j6.file.ShareUserQuery;
import com.zeroone.star.project.dto.j6.file.DownLoadShareDTO;
import com.zeroone.star.project.dto.j6.file.SendEditShareDTO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author j6
 * @since 2024-10-23
 */
public interface IFileAttachmentSharelistService extends IService<FileAttachmentSharelist> {
    /**
     * 获取共享用户列表（分页）
     *
     * @param query 查询条件
     * @return 分页的共享用户列表
     */
    PageDTO<ShareUserDTO> getShareUserList(ShareUserQuery query);

    /**
     * 获取指定共享用户的共享文件列表（分页）
     *
     * @param query 查询条件
     * @return 分页的共享文件列表
     */
    PageDTO<ShareFileDTO> getShareFilesOfUser(ShareFileQuery query);

    Boolean downLoadAbleFile(DownLoadShareDTO downLoadShareDTO);

    Boolean editAbleFile(SendEditShareDTO sendShareFileDTO);
}
