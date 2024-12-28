package com.zeroone.star.project.j4.procmanager.attachment;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.procmanager.attachment.AttachmentDTO;
import com.zeroone.star.project.query.j4.procmanager.attachment.AttachmentQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.procmanager.attachment.AttachmentVO;


/**
 * 附件API接口。
 */
public interface AttachmentQueryApis {
    /**
     * 获取附件列表。
     *
     * @param condition 查询条件
     * @return 附件列表视图对象
     */
    JsonVO<PageDTO<AttachmentDTO>> queryAll(AttachmentQuery condition);

    /**
     * 获取附件详情
     *
     * @param id 附件ID
     * @return 附件详情
     */
    JsonVO<AttachmentDTO> queryById(int id);
}

