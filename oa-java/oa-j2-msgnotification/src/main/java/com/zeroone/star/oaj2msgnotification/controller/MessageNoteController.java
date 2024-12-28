package com.zeroone.star.oaj2msgnotification.controller;

import com.zeroone.star.oaj2msgnotification.service.IMsgNoteService;
import com.zeroone.star.oaj2msgnotification.service.MessageService;
import com.zeroone.star.project.dto.j2.message.notification.DeleteMessageDTO;
import com.zeroone.star.project.dto.j2.message.notification.MsgInstantDTO;
import com.zeroone.star.project.j2.message.notification.MsgServiceApis;
import com.zeroone.star.project.query.j2.message.notification.MessageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.message.notification.MessageVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * 消息通知接口(合并以后)
 *
 */
@RestController
@RequestMapping("msg-notification")
@Api(tags = "消息通知")
public class MessageNoteController implements MsgServiceApis {
    @Resource
    private IMsgNoteService msgNoteService;
    @Resource
    private MessageService messageService;
    /**
     * 修改消息状态
     * @param msgInstantDTO 消息对象
     * @return 修改消息后的消息对象
     */
    @ApiOperation(value = "修改消息状态",notes = "根据消息状态和ID改变消息状态")
    @PutMapping("modify-status")
    @Override
    public JsonVO<MsgInstantDTO> modifyMsgStatus(MsgInstantDTO msgInstantDTO) {
         return msgNoteService.modifyStatus(msgInstantDTO);
    }

    /**
     * 清空消息
     * @param xIds 消息实例的ID拼接成的字符串
     * @return 清空消息结果
     */
    @ApiOperation(value = "清空消息", notes = "根据消息ID清空消息，xIds应为所有消息ID拼接成的字符串")
    @DeleteMapping("delete/all/{xIds}")
    @Override
    public JsonVO<Boolean> deleteAllMsg(
            @ApiParam(value = "拼接的消息ID字符串，多个ID以逗号分隔", required = true)
            @PathVariable String xIds) {
        return msgNoteService.deleteAllMsg(xIds);
    }
    /**
     * 获取未读消息列表
     * @param query 查询参数，包含用户id等信息
     * @return
     */
    @ApiOperation(value = "获取未读消息",notes = "根据查询条件获取用户未读消息列表")
    @GetMapping("unread")
    @Override
    public JsonVO<List<MessageVO>> getUnreadMessages(MessageQuery query) {
        // 调用服务层方法获取未读消息列表
        List<MessageVO> unreadMessages = messageService.getUnreadMessages(query);
        // 检查是否有未读消息
        if (unreadMessages == null || unreadMessages.isEmpty()) {
            // 没有未读消息，返回失败的响应
            return JsonVO.create(unreadMessages,10000,"暂时无未读消息");
        } else {
            // 有未读消息，返回成功的响应
            return JsonVO.success(unreadMessages);
        }
    }

    /**
     * 删除消息
     * @param deleteMessageDTO 包含要删除的消息id
     * @return
     */
    @ApiOperation(value = "删除消息",notes = "根据删除条件删除指定的消息记录")
    @DeleteMapping("delete")
    @Override
    public JsonVO<Boolean> deleteMessage(DeleteMessageDTO deleteMessageDTO) {
        // 调用服务层方法删除消息
        boolean result = messageService.deleteMessage(deleteMessageDTO);
        return JsonVO.success(result);
    }
}
