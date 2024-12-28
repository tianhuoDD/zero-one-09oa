package com.zeroone.star.project.j2.message.notification;

import com.zeroone.star.project.dto.j2.message.notification.DeleteMessageDTO;
import com.zeroone.star.project.dto.j2.message.notification.MsgInstantDTO;
import com.zeroone.star.project.query.j2.message.notification.MessageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.message.notification.MessageVO;

import java.util.List;

/**
 * 消息通知接口
 *
 */
public interface MsgServiceApis {
    /**
     * 修改消息状态
     * @param msgInstantDTO 消息对象
     * @return 消息对象
     */
    JsonVO<MsgInstantDTO>modifyMsgStatus(MsgInstantDTO msgInstantDTO);

    /**
     * 清空消息
     * @param xIds 消息实例的ID拼接成的字符串
     * @return 清空消息结果
     */
    JsonVO<Boolean>deleteAllMsg(String xIds);


    /**
     * 获取未读消息
     * @param query 查询参数，包含用户id等信息
     * @return 获取到的未读消息列表
     */
    JsonVO<List<MessageVO>> getUnreadMessages(MessageQuery query);

    /**
     * 删除消息
     * @param deleteMessageDTO 包含要删除的消息id
     * @return 删除操作的结果
     */
    JsonVO<Boolean> deleteMessage(DeleteMessageDTO deleteMessageDTO);
}
