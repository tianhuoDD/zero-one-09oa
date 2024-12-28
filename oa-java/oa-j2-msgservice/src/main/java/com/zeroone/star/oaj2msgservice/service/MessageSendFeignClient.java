package com.zeroone.star.oaj2msgservice.service;


import com.zeroone.star.project.dto.j2.message.service.MessagePhoneSendDTO;
import com.zeroone.star.project.dto.mail.MailDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.message.service.MessageSendMailVO;
import com.zeroone.star.project.vo.j2.message.service.MessageSendPhoneVO;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.PostMapping;

/**
 * 消息发送的feign远程调用接口
 * @author qingjiu
 */
@FeignClient(name = "oa-j2-msgservice")
public interface MessageSendFeignClient{
    @PostMapping("/sendSinglePhoneMessage")
    JsonVO<MessageSendPhoneVO> sendSinglePhoneMessage(MessagePhoneSendDTO messagePhoneSendDTO);

    @PostMapping("/sendBatchPhoneMessages")
    JsonVO<MessageSendPhoneVO> sendBatchPhoneMessages(MessagePhoneSendDTO messagePhoneSendDTO);

    @PostMapping("/sendMailMessage")
    JsonVO<MessageSendMailVO> sendMailMessage(MailDTO mailDTO);
}
