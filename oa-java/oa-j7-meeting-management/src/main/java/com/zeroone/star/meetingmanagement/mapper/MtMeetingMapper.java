package com.zeroone.star.meetingmanagement.mapper;

import com.zeroone.star.meetingmanagement.entity.MtMeeting;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.time.LocalDateTime;
import java.time.LocalTime;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author ydp
 * @since 2024-10-21
 */
@Mapper
public interface MtMeetingMapper extends BaseMapper<MtMeeting> {
    @Select("select xactualCompletedTime from mt_meeting where xid = #{meetingId}")
    LocalTime getActualCompletedTime(String meetingId);

}
