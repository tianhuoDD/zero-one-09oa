package com.zeroone.star.oaj2msgnotification.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.oaj2msgnotification.entity.MsgInstant;
import com.zeroone.star.oaj2msgnotification.entity.MsgMessage;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface MsgNoteMapper extends BaseMapper<MsgMessage> {

}
