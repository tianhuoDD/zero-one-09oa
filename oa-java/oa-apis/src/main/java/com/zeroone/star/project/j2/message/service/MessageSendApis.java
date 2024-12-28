package com.zeroone.star.project.j2.message.service;


import com.zeroone.star.project.dto.j2.message.service.MessagePhoneSendDTO;
import com.zeroone.star.project.dto.mail.MailDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.message.service.MessageSendMailVO;
import com.zeroone.star.project.vo.j2.message.service.MessageSendPhoneVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;

import javax.validation.Valid;

/**
 * 消息发送apis
 * @author qingjiu
 */
@Api(tags = "消息发送apis")
public interface MessageSendApis {

    /**
     * 发送单条短信消息
     * @param messagePhoneSendDTO
     * @return
     */
    @ApiOperation("发送单条短信消息")
    JsonVO<MessageSendPhoneVO> sendSinglePhoneMessage(@Valid MessagePhoneSendDTO messagePhoneSendDTO);

    /**
     * 批量发送短信消息
     * @param messagePhoneSendDTO
     * @return
     */
    @ApiOperation(value = "批量发送短信消息", notes = "根据提供的数据对象发送多条短信")
    JsonVO<MessageSendPhoneVO> sendBatchPhoneMessages(@Valid MessagePhoneSendDTO messagePhoneSendDTO);


    /**
     * 发送单条(多条)邮件消息
     * @param mailDTO
     * @return
     */
    @ApiOperation("发送单条(多条)邮件消息")
    JsonVO<MessageSendMailVO> sendMailMessage(@Valid MailDTO mailDTO);
}
