package com.zeroone.star.project.j2.message.notification;

import com.zeroone.star.project.dto.j2.message.notification.MsgInstantDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * 消息通知接口
 *
 */
public interface MsgNotificationApis {
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
}
