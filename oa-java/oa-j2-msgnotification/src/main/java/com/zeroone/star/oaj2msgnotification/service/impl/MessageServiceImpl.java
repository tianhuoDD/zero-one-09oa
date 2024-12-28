package com.zeroone.star.oaj2msgnotification.service.impl;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.zeroone.star.oaj2msgnotification.mapper.MessageMapper;
import com.zeroone.star.oaj2msgnotification.service.MessageService;
import com.zeroone.star.project.dto.j2.message.notification.DeleteMessageDTO;
import com.zeroone.star.project.query.j2.message.notification.MessageQuery;
import com.zeroone.star.project.vo.j2.message.notification.MessageVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * @Author: hjm
 * @Date: 2024/10/28/21:20
 * @Description: 消息实现类
 */
@Service
public class MessageServiceImpl implements MessageService {

    @Autowired
    private MessageMapper messageMapper;

    /**
     * 获取未读消息
     * @param query 查询参数
     * @return
     */
    @Override
    public List<MessageVO> getUnreadMessages(MessageQuery query) {
        // 从数据库获取未读消息（这里假设xconsumed=0表示未读）
        List<MessageVO> unreadMessages = messageMapper.findUnreadMessages(query);


        return unreadMessages;
    }

    /**
     * 删除消息
     * @param dto 删除参数
     * @return
     */
    @Override
    public boolean deleteMessage(DeleteMessageDTO dto) {
        // 从数据库删除消息
        int deleteCount = messageMapper.deleteMessage(dto.getXid());

        return deleteCount > 0;
    }

    ///**
    // * 发送未读消息到客户端
    // * @param query
    // * @throws JsonProcessingException
    // */
    //public void sendUnreadMessagesToClients(MessageQuery query) throws JsonProcessingException {
    //    List<MessageVO> unreadMessages = messageMapper.findUnreadMessages(query);
    //
    //    // 这里假设你有一个特定的WebSocket主题来发送未读消息
    //    String destination = "/topic/unreadMessages";
    //
    //    // 将消息转换为适合WebSocket发送的格式，这里简单使用消息列表的JSON表示
    //    // 实际应用中，你可能需要更复杂的序列化逻辑
    //    String messageJson = new ObjectMapper().writeValueAsString(unreadMessages);
    //
    //    // 发送消息到WebSocket客户端
    //    messagingTemplate.convertAndSend(destination, messageJson);
    //}
}