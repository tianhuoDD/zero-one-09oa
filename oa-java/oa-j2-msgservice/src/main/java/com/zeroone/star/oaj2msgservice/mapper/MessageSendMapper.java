package com.zeroone.star.oaj2msgservice.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.oaj2msgservice.entity.MessageSendDO;
import org.apache.ibatis.annotations.Mapper;


/**
 * 消息发送Mapper
 * @author qingjiu
 */
@Mapper
public interface MessageSendMapper extends BaseMapper<MessageSendDO> {
    /**
     * 插入发送的邮件信息到数据库
     * @param messageSendDO 邮件信息
     */
    boolean insertDO(MessageSendDO messageSendDO);

}
