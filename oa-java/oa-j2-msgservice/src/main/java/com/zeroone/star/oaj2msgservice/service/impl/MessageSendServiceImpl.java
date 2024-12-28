package com.zeroone.star.oaj2msgservice.service.impl;

import com.baomidou.mybatisplus.core.toolkit.IdWorker;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oaj2msgservice.entity.MessageSendDO;
import com.zeroone.star.oaj2msgservice.mapper.MessageSendMapper;
import com.zeroone.star.oaj2msgservice.service.MessageSendService;
import com.zeroone.star.project.dto.j2.message.service.MessagePhoneSendDTO;
import com.zeroone.star.project.dto.mail.MailDTO;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.UUID;

/**
 * 消息发送服务
 * @author qingjiu
 */
@Service
public class MessageSendServiceImpl extends ServiceImpl<MessageSendMapper, MessageSendDO> implements MessageSendService {


    @Value("${spring.mail.username}")
    private String username;

    @Value("${aliyun.sms.phoneName}")
    private String phoneName;

    @Resource
    private MessageSendMapper messageSendMapper;

    /**
     * 保存发送的邮件信息
     * @param mailDTO 邮件信息
     * @return
     */
    @Override
    public boolean save(MailDTO mailDTO) {
        MessageSendDO messageSendDO = new MessageSendDO();
        messageSendDO.setXcreateTime(LocalDateTime.now());
        messageSendDO.setXupdateTime(LocalDateTime.now());
        messageSendDO.setXbody(mailDTO.getText());
        messageSendDO.setXtitle(mailDTO.getSubject());
        messageSendDO.setXtype("mail");
        messageSendDO.setXconsumed(true);
        messageSendDO.setXconsumer(mailDTO.getTo());
        messageSendDO.setXperson(username);
        // 使用 MyBatis-Plus 提供的 IdWorker 生成雪花 ID
        // 生成 Long 类型的雪花 ID
        Long generatedId = IdWorker.getId();
        // 转换为 String 类型并设置
        messageSendDO.setXid(generatedId.toString());
        String sequence = LocalDateTime.now() + "-" + generatedId;
        messageSendDO.setXsequence(sequence);
        return messageSendMapper.insertDO(messageSendDO);

    }

    /**
     * 保存单条发送的短信信息
     * @param messagePhoneSendDTO
     * @return
     */
    @Override
    public boolean saveSinglePhone(MessagePhoneSendDTO messagePhoneSendDTO) {
        String person = messagePhoneSendDTO.getXpersons().get(0);
        MessageSendDO messageSendDO = new MessageSendDO();
        messageSendDO.setXcreateTime(LocalDateTime.now());
        messageSendDO.setXupdateTime(LocalDateTime.now());
        messageSendDO.setXbody(messagePhoneSendDTO.getXbody());
        messageSendDO.setXtitle("发给" + person +  "的短信内容");
        messageSendDO.setXtype("sms");
        messageSendDO.setXperson(phoneName);
        messageSendDO.setXconsumed(true);
        messageSendDO.setXconsumer(person);
        // 使用 MyBatis-Plus 提供的 IdWorker 生成雪花 ID
        // 生成 Long 类型的雪花 ID
        Long generatedId = IdWorker.getId();
        // 转换为 String 类型并设置
        messageSendDO.setXid(generatedId.toString());
        String sequence = LocalDateTime.now() + "-" + generatedId;
        messageSendDO.setXsequence(sequence);
        return messageSendMapper.insertDO(messageSendDO);
    }

    @Override
    public boolean saveBatchPhone(MessagePhoneSendDTO messagePhoneSendDTO) {
        MessageSendDO messageSendDO = new MessageSendDO();
        String consumers = String.join(",", messagePhoneSendDTO.getXpersons());
        messageSendDO.setXperson(phoneName);
        messageSendDO.setXtitle("发给" + consumers +  "的短信内容");
        messageSendDO.setXtype("sms");
        messageSendDO.setXconsumed(true);
        messageSendDO.setXconsumer(consumers);
        messageSendDO.setXcreateTime(LocalDateTime.now());
        messageSendDO.setXupdateTime(LocalDateTime.now());
        messageSendDO.setXbody(messagePhoneSendDTO.getXbody());
        // 使用 MyBatis-Plus 提供的 IdWorker 生成雪花 ID
        // 生成 Long 类型的雪花 ID
        Long generatedId = IdWorker.getId();
        // 转换为 String 类型并设置
        messageSendDO.setXid(generatedId.toString());
        String sequence = LocalDateTime.now() + "-" + generatedId;
        messageSendDO.setXsequence(sequence);
        return messageSendMapper.insertDO(messageSendDO);
    }
}
