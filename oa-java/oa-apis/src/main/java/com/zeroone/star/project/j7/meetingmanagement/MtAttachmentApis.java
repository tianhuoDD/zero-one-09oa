package com.zeroone.star.project.j7.meetingmanagement;

import com.zeroone.star.project.dto.meetingmangement.AttachmentDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface MtAttachmentApis {
    /**
     * 上传会议文件
     */
    JsonVO<String> addFile(AttachmentDTO attachmentDTO);
}
