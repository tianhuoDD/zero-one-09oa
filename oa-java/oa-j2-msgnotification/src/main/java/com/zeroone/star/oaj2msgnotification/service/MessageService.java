
package com.zeroone.star.oaj2msgnotification.service;


import com.zeroone.star.project.dto.j2.message.notification.DeleteMessageDTO;
import com.zeroone.star.project.query.j2.message.notification.MessageQuery;
import com.zeroone.star.project.vo.j2.message.notification.MessageVO;

import java.util.List;

public interface MessageService {
    /**
     * 获取未读消息
     * @param query 查询参数
     * @return 未读消息列表
     */
    List<MessageVO> getUnreadMessages(MessageQuery query);

    /**
     * 删除消息
     * @param dto 删除参数
     * @return 是否删除成功
     */
    boolean deleteMessage(DeleteMessageDTO dto);
}


