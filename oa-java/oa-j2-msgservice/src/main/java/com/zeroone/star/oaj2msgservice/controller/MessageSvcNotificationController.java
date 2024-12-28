package com.zeroone.star.oaj2msgservice.controller;

import com.zeroone.star.oaj2msgservice.service.WebsocketService;
import com.zeroone.star.project.dto.j2.message.service.MessageNotifyServiceDTO;
import com.zeroone.star.project.j2.message.service.MessageNotificationServiceApi;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
/*
 *   消息通知服务模块（包含在消息服务中）
 *
 */
@RestController
@Api(tags = "消息通知服务")
@RequestMapping("/message-note")
public class MessageSvcNotificationController implements MessageNotificationServiceApi {

    @Autowired
    private WebsocketService websocketService;

    @ApiOperation("处理系统通知")
    @PostMapping("/sys-msg")
    public JsonVO<String> sysmsg(MessageNotifyServiceDTO message) {
        websocketService.sendMessage(message);
        return JsonVO.success("消息发布成功");
    }
}