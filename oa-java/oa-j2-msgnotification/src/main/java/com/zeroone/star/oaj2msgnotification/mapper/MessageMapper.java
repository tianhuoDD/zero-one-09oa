package com.zeroone.star.oaj2msgnotification.mapper;


import com.zeroone.star.project.query.j2.message.notification.MessageQuery;
import com.zeroone.star.project.vo.j2.message.notification.MessageVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

@Mapper
public interface MessageMapper {

    /**
     * 获取未读消息
     * @param query
     * @return
     */
    List<MessageVO> findUnreadMessages(@Param("query") MessageQuery query);

    /**
     * 删除消息
     * @param xid
     * @return
     */
    int deleteMessage(@Param("xid") String xid);
}