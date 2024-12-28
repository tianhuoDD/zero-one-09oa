package com.zeroone.star.calmanager.service;

import com.zeroone.star.calmanager.entity.CalCalendarFollowers;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.cpp.SampleDTO;
import com.zeroone.star.project.dto.j6.calendar.ActionFollowCalendarDTO;
import com.zeroone.star.project.vo.j6.calendar.ActionFollowCalendarVO;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
interface MsICalCalendarFollowMapper{
ActionFollowCalendarDTO actionFollowCalendarDTO( SampleDTO sampleDTO );


}
/**
 * <p>
 *  服务类
 * </p>
 *
 * @author lee
 * @since 2024-10-23
 */
public interface ICalCalendarFollowersService extends IService<CalCalendarFollowers> {


    ActionFollowCalendarVO followCalendar(String calendarId,String userId);
    ActionFollowCalendarVO unfollowCalendar(String calendarId,String userId);

}

