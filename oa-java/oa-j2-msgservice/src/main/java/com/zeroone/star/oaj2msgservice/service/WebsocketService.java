package com.zeroone.star.oaj2msgservice.service;

import cn.hutool.json.JSONUtil;
import com.zeroone.star.project.dto.j2.message.service.MessageNotifyServiceDTO;
import io.swagger.annotations.Api;
import lombok.extern.slf4j.Slf4j;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.cloud.stream.messaging.Sink;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Service;

import javax.websocket.*;
import javax.websocket.server.ServerEndpoint;
import java.io.IOException;
import java.time.Instant;
import java.util.List;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;

@Service
@Slf4j
@ServerEndpoint("/ws")
@Api(tags = "websocket相关(相当于接口)")
public class WebsocketService {
    /**
     * 保存连接对象
     */
    private final static ConcurrentHashMap<String, Session> SESSION_POOL = new ConcurrentHashMap<>();

    public static RedisService redisService;


    @OnOpen
    //登录消息服务
    public void onOpen(Session session) throws IOException {
        //判断客户端对象是否存在
        if (SESSION_POOL.containsKey(session.getQueryString())) {
            CloseReason reason = new CloseReason(CloseReason.CloseCodes.CANNOT_ACCEPT, "ID冲突，连接拒绝");
            session.getUserProperties().put("reason", reason);
            session.close();
            return;
        }
        //将客户端记录到Map中
        SESSION_POOL.put(session.getQueryString(), session);
        System.out.println("客户端（" + session.getQueryString() + "）：开启连接");

        //将redis中的系统通知同步到当前的客户端
        //unsend_messages id msgcnt
        try {
            List<String> list = redisService.sysMessage(session.getQueryString());
            if (!list.isEmpty()) {
                for (String msg : list) {
                    session.getBasicRemote().sendText(JSONUtil.toJsonStr(msg));
                }
                System.out.println("redis同步完成");
                redisService.deleteMessage(session.getQueryString());
            }
        } catch (Exception e) {
            System.out.println("同步失败：" + e.getMessage());
        }
    }

    @OnMessage
    public String onMessage(String text, Session session) throws IOException {
        //解析消息 => ID::消息内容
        String[] msgArr = text.split("::", 2);
        //群发消息 ID=all表示群发
        if ("all".equalsIgnoreCase(msgArr[0])) {
            for (Session one : SESSION_POOL.values()) {
                //排除自己
                if (session == one) {
                    continue;
                }
                //发送消息
                one.getBasicRemote().sendText(msgArr[1]);
            }
        }
        //指定发送
        else {
            Session target = SESSION_POOL.get(msgArr[0]);
            if (target != null) {
                target.getBasicRemote().sendText(msgArr[1]);
            }
        }
        return session.getQueryString() + ":消息发送成功";
    }

    @OnClose
    //退出消息服务
    public void onClose(Session session) {
        //处理拒绝连接session关闭对象
        Object obj = session.getUserProperties().get("reason");
        if (obj instanceof CloseReason) {
            CloseReason reason = (CloseReason) obj;
            if (reason.getCloseCode() == CloseReason.CloseCodes.CANNOT_ACCEPT) {
                System.out.println("拒绝客户端（" + session.getQueryString() + "）：关闭连接");
                return;
            }
        }
        //将session对象从map中移除
        SESSION_POOL.remove(session.getQueryString());
        System.out.println("客户端（" + session.getQueryString() + "）：关闭连接");
    }

    @OnError
    public void onError(Session session, Throwable throwable) {
        System.out.println("客户端（" + session.getQueryString() + "）错误信息：" + throwable.getMessage());
    }

    /**
     * 将消息中间件中的消息通知给客户端
     * 注意：如果客户端不在线，需要处理将未发送通知存储到未发送列表
     * @param message
     */
    @StreamListener(Sink.INPUT)
    public void sendMessage(MessageNotifyServiceDTO message){
        String id=message.getClientId();
        String msg=message.getMessage();
        //群发消息 ID=all表示群发
        if ("all".equalsIgnoreCase(id)) {
            for (Session one : SESSION_POOL.values()) {
                //发送消息
                try {
                    one.getBasicRemote().sendText(JSONUtil.toJsonStr(msg));
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        //指定发送
        else {
            Session target = SESSION_POOL.get(id);
            //如果客户端上线，直接发送给客户端
            if (target != null&&target.isOpen()) {
                try {
                    target.getBasicRemote().sendText(JSONUtil.toJsonStr(msg));
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }else{
                //如果客户端未上线，则存入redis的未发送队列中(List实现)
                redisService.addUnsendMessage(id,msg);
            }
        }
    }

    @Scheduled(fixedRate = 6000) //每分钟从缓存拉取一次消息
    public void CheckAndSendNotification(){
        Long currentTime= Instant.now().getEpochSecond();//当前时间戳（秒）
        //获取当前所有需要发送的定时消息
        Set<String> ids=SESSION_POOL.keySet();
        for(String id:ids){
            try{
                Set<MessageNotifyServiceDTO> messages = redisService.getMessagesToSend(id,currentTime);
                for (MessageNotifyServiceDTO msg : messages) {
                    //发送消息
                    sendMessage(msg);
                    //删除已经发送的消息
                    redisService.removeMessage(msg);
                    System.out.println("进行定时消息通知");
                }
            }catch (Exception e){
                System.out.println("定时任务结束");
            }
        }
    }
}
