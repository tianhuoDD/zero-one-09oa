package com.zeroone.star.meetingmanagement.service;

import com.zeroone.star.meetingmanagement.entity.MtAttachment;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.meetingmangement.AttachmentDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author caifeng
 * @since 2024-10-24
 */
public interface IMtAttachmentService extends IService<MtAttachment> {
    JsonVO<String> upload(AttachmentDTO attachmentDTO);
}
