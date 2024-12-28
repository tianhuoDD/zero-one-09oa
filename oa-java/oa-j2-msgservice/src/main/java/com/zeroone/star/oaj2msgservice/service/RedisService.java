package com.zeroone.star.oaj2msgservice.service;

import com.zeroone.star.project.constant.RedisConstant;
import com.zeroone.star.project.dto.j2.message.service.MessageNotifyServiceDTO;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.Set;

@Service
public class RedisService {

    @Resource
    private RedisTemplate<String, MessageNotifyServiceDTO> redisTemplate;

    @Resource
    private RedisTemplate<String, String> redisTemplate1;

    //添加定时消息到 Redis，score为消息的发送时间戳
    //根据时间顺序获取即将到期的消息
    //schedule_message msgcnt time
    public void addMessage(MessageNotifyServiceDTO msg, long timestamp) {
        redisTemplate.opsForZSet().add(RedisConstant.SCHEDULED_MESSAGES_KEY+msg.getClientId(), msg, timestamp);
    }

    //获取所有在当前时间前需要发送的消息
    public Set<MessageNotifyServiceDTO> getMessagesToSend(String clientId,long currentTime) {
        return redisTemplate.opsForZSet().rangeByScore(RedisConstant.SCHEDULED_MESSAGES_KEY+clientId, 0, currentTime);
    }

    //从Redis中删除已发送的消息
    public void removeMessage(MessageNotifyServiceDTO msg) {
        redisTemplate.opsForZSet().remove(RedisConstant.SCHEDULED_MESSAGES_KEY+msg.getClientId(), msg);
    }
    //同步信息
    public List<String> sysMessage(String id){
        List<String> list = redisTemplate1.opsForList().range(RedisConstant.UNSEND_MESSAGES_KEY + id, 0, -1);
        return list;
    }
    //删除已发送的通知
    public void deleteMessage(String id){
        redisTemplate1.opsForList().leftPop(RedisConstant.UNSEND_MESSAGES_KEY + id);
    }
    //如果客户端未上线，则存入redis的未发送队列中(List实现)
    public void addUnsendMessage(String id,String msg){
        redisTemplate1.opsForList().rightPush(RedisConstant.UNSEND_MESSAGES_KEY + id, msg);
    }
}