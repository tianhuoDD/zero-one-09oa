package com.zeroone.star.filemanager.service;

import com.zeroone.star.filemanager.entity.FileRecycle;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.file.ReceivedFileDTO;
import com.zeroone.star.project.dto.j6.file.ReceivedUserDTO;
import com.zeroone.star.project.query.j6.file.ReceivedFileQuery;
import com.zeroone.star.project.query.j6.file.ReceivedUserQuery;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author j6
 * @since 2024-10-23
 */
public interface IFileRecycleService extends IService<FileRecycle> {
    PageDTO<ReceivedUserDTO> getReceivedUserList(ReceivedUserQuery query);


    PageDTO<ReceivedFileDTO> getReceivedFileList(ReceivedFileQuery query);
}
