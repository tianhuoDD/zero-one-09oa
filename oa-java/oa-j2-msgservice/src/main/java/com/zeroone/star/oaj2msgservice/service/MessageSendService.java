package com.zeroone.star.oaj2msgservice.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.oaj2msgservice.entity.MessageSendDO;
import com.zeroone.star.project.dto.j2.message.service.MessagePhoneSendDTO;
import com.zeroone.star.project.dto.mail.MailDTO;

/**
 * 消息发送服务类
 * @author qingjiu
 */
public interface MessageSendService extends IService<MessageSendDO> {
    /**
     * 保存消息发送记录到数据库
     * @param mailDTO 邮件信息
     * @return
     */
    boolean save(MailDTO mailDTO);

    /**
     * 保存单条短信发送记录到数据库
     * @param messagePhoneSendDTO
     * @return
     */
    boolean saveSinglePhone(MessagePhoneSendDTO messagePhoneSendDTO);

    boolean saveBatchPhone(MessagePhoneSendDTO messagePhoneSendDTO);
}
