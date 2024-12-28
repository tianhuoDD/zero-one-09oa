package com.zeroone.star.calmanager.service;

import com.zeroone.star.calmanager.entity.CalCalendar;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.calendar.CalendarDTO;
import com.zeroone.star.project.query.j6.calendar.CalendarPageQuery;
import com.zeroone.star.project.vo.j6.calendar.CalenderAssembleVO;
import org.apache.ibatis.annotations.Param;
import org.mapstruct.Mapper;import com.zeroone.star.project.dto.j6.calendar.InsertCalendarDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.dto.j6.calendar.CalendarDTO;
import com.zeroone.star.project.dto.j6.calendar.CalendarInfoDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.calendar.CalendarInfoVO;
import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author lee
 * @since 2024-10-23
 */
public interface ICalCalendarService extends IService<CalCalendar> { /**
  * 查询日历广场日历
  * @param calendarPageQuery
  * @return
  */
   PageDTO<CalendarDTO> listPublicCalendars(CalendarPageQuery calendarPageQuery);;

    /**
     * 新增日历
     * @param insertCalendarDTO
     * @return
     */
    boolean insertCalendar(InsertCalendarDTO insertCalendarDTO);

    /**
     * 校验 xid 是否唯一
     * @param xname
     * @return
     */
    boolean isXnameUnique(String xname);

    /**
     * 删除日历
     * @param xid
     * @return
     */
    boolean deleteCalendar(String xid);
    public List<CalendarInfoVO> queryCalendarInfo();
    public CalendarInfoVO queryCalendarInfo(String xid);
    public Boolean modifyCalendarInfo(CalendarDTO calendarDTO);

    /**
     * 删除日历子表记录
     * @param xid
     * @return
     */
    boolean deleteCalendarSubRecords(String xid);
}
