package com.zeroone.star.procmanager.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.procmanager.attachment.AttachmentDTO;
import com.zeroone.star.project.query.j4.procmanager.attachment.AttachmentQuery;


/**
 * 附件查询服务接口。
 */
public interface AttachmentQueryService {

    /**
     * 获取附件列表。
     *
     * @param condition 查询条件
     * @return 附件列表视图对象
     */
    PageDTO<AttachmentDTO> queryAll(AttachmentQuery condition);

    /**
     * 根据ID获取附件详情。
     *
     * @param id 附件ID
     * @return 附件详情
     */
    AttachmentDTO getById(int id);
}
