package com.zeroone.star.project.j6.calendar;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.calendar.ActionFollowCalendarDTO;
import com.zeroone.star.project.dto.j6.calendar.CalendarEventDTO;
import com.zeroone.star.project.dto.j6.calendar.CalenderAssembleDTO;
import com.zeroone.star.project.dto.j6.calendar.EventDetailDTO;
import com.zeroone.star.project.dto.j6.calendar.*;
import com.zeroone.star.project.query.j6.calendar.CalendarPageQuery;
import com.zeroone.star.project.query.j6.calendar.CalendarQuery;
import com.zeroone.star.project.query.j6.calendar.EventsListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.calendar.ActionFollowCalendarVO;
import com.zeroone.star.project.vo.j6.calendar.CalendarInfoVO;
import com.zeroone.star.project.vo.j6.calendar.CalenderAssembleVO;
import com.zeroone.star.project.vo.j6.calendar.EventsListVO;
import org.springframework.validation.annotation.Validated;

import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import java.util.List;

/**
 * @program: oa-java
 * @description: 日程安排模块相关接口声明
 * @author: Mr.Wang
 * @create: 2024-10-21 14:58
 **/
public interface CalScheduleApis {

    /**
     * 添加日程
     *
     * @param calendarEventDTO
     * @return 添加日程的id
     */

    JsonVO<String> AddCalenderEvent(CalendarEventDTO calendarEventDTO);

    /**
     * 删除日程
     *
     * @param xid,type type为0 表示为删除当前日程   1 表示删除当前和之后的重复日程      2 表示删除全部（包括之前）重复日程
     * @return 所删除日程的id
     */
    JsonVO<String> DeleteCalenderEvent(String xid, @Validated @Min(value = 0, message = "type最小值为0") @Max(value = 2, message = "type最大值为2") Integer type);

    /**
     * @param要关注的日历的信息
     * @return日历状态
     */
    JsonVO<ActionFollowCalendarVO> followCalendar(ActionFollowCalendarDTO dto);

    JsonVO<ActionFollowCalendarVO> unfollowCalendar(ActionFollowCalendarDTO dto);

    /**
     * 获取日程详情
     *
     * @param id 日程id
     * @return 日程详细信息
     */
    JsonVO<EventDetailDTO> queryEventDetails(String id);

    /**
     * 获取日程列表
     *
     * @param query 查询参数
     * @return 日程列表
     */
    JsonVO<EventsListVO> queryEventsList(EventsListQuery query);

    /**
     * 修改日程详细信息
     *
     * @param detailDTO 日程详细信息
     * @return 该日程id
     */
    JsonVO<String> updateEventDetails(EventDetailDTO detailDTO);

    /**
     * 查询日历广场日历（分页）
     * @param calendarPageQuery
     * @return
     */
    //TODO    JsonVO<CalenderAssembleVO> queryCalenderAssemble(CalenderAssembleDTO calenderAssembleDTO);
    //JsonVO<CalenderAssembleVO> queryCalenderAssemble(CalenderAssembleDTO calenderAssembleDTO);修改为以下
    JsonVO<PageDTO<CalendarDTO>> queryCalenderAssemble(CalendarPageQuery calendarPageQuery);

    /**
     * 创建日历
     *
     * @param insertCalendarDTO 新建日历详细信息
     * @return
     */
    JsonVO<Boolean> insertCalendar(InsertCalendarDTO insertCalendarDTO);

    /**
     * 删除日历
     *
     * @param xid 要删除的日历id
     * @return
     */
    JsonVO<Boolean> deleteCalendar(String xid);

    /**
     * 获取日历信息
     *
     * @param id
     * @return
     */
    JsonVO<CalendarInfoVO> queryCalendarInfo(String id);

    /**
     * 获取日历列表
     *
     * @return
     */
    JsonVO<List<CalendarInfoVO>> queryCalendarInfo();

    /**
     * 修改日历信息
     * @param calendarDTO
     * @return
     */
    JsonVO<Boolean> modifyCalendarInfo(CalendarDTO calendarDTO);
}

