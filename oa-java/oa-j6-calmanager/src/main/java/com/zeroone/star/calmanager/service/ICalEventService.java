package com.zeroone.star.calmanager.service;

import com.zeroone.star.calmanager.entity.CalEvent;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j6.calendar.CalendarEventDTO;
import com.zeroone.star.project.dto.j6.calendar.EventDetailDTO;
import com.zeroone.star.project.query.j6.calendar.EventsListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.calendar.EventsListVO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author lee
 * @since 2024-10-23
 */
public interface ICalEventService extends IService<CalEvent> {
    /**
     *根据日程id查询日程详情
     * @param id 日程id
     * @return 日程详情dto
     */
    EventDetailDTO queryEventDetails(String id);
    /**
     * 修改日程详细信息
     * @param detailDTO 日程详细信息
     * @return 该日程id
     */
    String updateEventDetails(EventDetailDTO detailDTO);
    /**
     * 根据类型删除日程
     * @param xid
     * @param type
     * @return
     */
    String removeByIdandType(String xid, Integer type);

    /**
     * 添加日程
     * @param calendarEventDTO
     * @return
     */
    String addCalEvent(CalendarEventDTO calendarEventDTO);
    /**
     * 获取日程列表
     * @param query 查询参数
     * @return 日程列表
     */
    EventsListVO queryEventsList(EventsListQuery query);
}
