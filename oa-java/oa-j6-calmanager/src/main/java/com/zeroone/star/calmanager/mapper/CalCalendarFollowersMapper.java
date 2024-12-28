package com.zeroone.star.calmanager.mapper;

import com.zeroone.star.calmanager.entity.CalCalendarFollowers;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author lee
 * @since 2024-10-23
 */
@Mapper
public interface CalCalendarFollowersMapper extends BaseMapper<CalCalendarFollowers> {
    @Select("SELECT EXISTS(SELECT 1 FROM cal_calendar_followers WHERE CALENDAR_XID = #{calendarId})")
    boolean existsByCalendarIdAndTarget(@Param("calendarId") String calendarId);

/*    @Select("SELECT EXISTS(SELECT 1 FROM cal_calendar_followers WHERE CALENDAR_XID = #{calendarId} AND xfollowers = #{target})")
    boolean existsByCalendarIdAndTarget(@Param("calendarId") String calendarId, @Param("target") String target);*/
}