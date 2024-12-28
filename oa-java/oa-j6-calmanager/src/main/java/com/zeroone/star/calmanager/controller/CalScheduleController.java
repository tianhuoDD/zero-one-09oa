package com.zeroone.star.calmanager.controller;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.zeroone.star.calmanager.service.ICalCalendarService;
import com.zeroone.star.calmanager.service.impl.CalCalendarServiceImpl;
import com.zeroone.star.calmanager.service.ICalEventService;
import com.zeroone.star.calmanager.entity.CalCalendar;
import com.zeroone.star.calmanager.service.ICalCalendarFollowersService;
import com.alibaba.cloud.commons.lang.StringUtils;
import com.zeroone.star.calmanager.service.ICalCalendarService;
import com.zeroone.star.calmanager.service.impl.CalCalendarServiceImpl;
import com.zeroone.star.calmanager.service.ICalEventService;
import com.zeroone.star.calmanager.entity.CalCalendar;
import com.zeroone.star.calmanager.service.ICalCalendarService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.calendar.ActionFollowCalendarDTO;
import com.zeroone.star.project.dto.j6.calendar.CalendarEventDTO;
import com.zeroone.star.project.dto.j6.calendar.CalenderAssembleDTO;
import com.zeroone.star.project.dto.j6.calendar.EventDetailDTO;
import com.zeroone.star.project.dto.j6.calendar.*;
import com.zeroone.star.project.j6.calendar.CalScheduleApis;
import com.zeroone.star.project.query.j6.calendar.CalendarPageQuery;
import com.zeroone.star.project.query.j6.calendar.CalendarQuery;
import com.zeroone.star.project.query.j6.calendar.EventsListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.calendar.ActionFollowCalendarVO;
import com.zeroone.star.project.vo.j6.calendar.CalendarInfoVO;
import com.zeroone.star.project.vo.j6.calendar.CalenderAssembleVO;
import com.zeroone.star.project.vo.j6.calendar.EventsListVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotEmpty;
import javax.servlet.http.HttpServletRequest;
import javax.annotation.Resource;
import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.Min;
import java.util.List;

/**
 * @program: oa-java
 * @description: 日程安排控制器
 * @author: Mr.Wang
 * @create: 2024-10-21 15:13
 **/
@RestController
@RequestMapping("cal-schedule")
@Api(tags = "日程安排模块")
@Validated
public class CalScheduleController implements CalScheduleApis {

    @Resource
    private ICalEventService calEventService;
    @Autowired
    private ICalCalendarService iCalCalendarService;

    @Autowired
    private ICalCalendarFollowersService iCalCalendarFollowersService;
    @Resource
    ICalCalendarService calCalendarService;
    @Autowired
    private HttpServletRequest request;

  @ApiOperation("添加日程")
  @PostMapping("addevent")
    public JsonVO<String> AddCalenderEvent(CalendarEventDTO calendarEventDTO) {
      System.out.println(calendarEventDTO);
      return JsonVO.success(calEventService.addCalEvent(calendarEventDTO));
    }


    @DeleteMapping("single/{xid}/{type}")
    @ApiOperation(value = "根据id和类型删除当前日程")
    public JsonVO<String> DeleteCalenderEvent(@PathVariable String xid,
                                              @PathVariable Integer type) {

        return JsonVO.success(calEventService.removeByIdandType(xid,type));
    }



    @ApiOperation("关注日历")
    @PutMapping("Action-Follow")
    @Override
    public JsonVO<ActionFollowCalendarVO> followCalendar(@Validated ActionFollowCalendarDTO dto) {

        return JsonVO.success(iCalCalendarFollowersService.followCalendar(dto.getCalendarId(), dto.getUserId()));
    }


    @ApiOperation("取消关注日历")
    @PutMapping("Action-UnFollow")
    @Override
    public JsonVO<ActionFollowCalendarVO> unfollowCalendar(@Validated ActionFollowCalendarDTO dto) {
        return JsonVO.success(iCalCalendarFollowersService.unfollowCalendar(dto.getCalendarId(), dto.getUserId()));
    }


    @Override
    @GetMapping("event-details")
    @ApiOperation("根据id查询日程详情")
    public JsonVO<EventDetailDTO> queryEventDetails(String id) {
        return JsonVO.success(calEventService.queryEventDetails(id));
    }

    @Override
    @GetMapping("event-list")
    @ApiOperation("查询日程列表")
    public JsonVO<EventsListVO> queryEventsList(EventsListQuery query) {
        System.out.println(query.toString());
        return JsonVO.success(calEventService.queryEventsList(query));
    }

    @Override
    @PutMapping("event-details")
    @ApiOperation("修改日程详情")
    public JsonVO<String> updateEventDetails(@RequestBody EventDetailDTO detailDTO) {
        System.out.println(detailDTO.toString());
        return JsonVO.success(calEventService.updateEventDetails(detailDTO));
    }




    @GetMapping("get-calenderAssembleList")
    @ApiOperation("查询日历广场日历（分页）")
    public JsonVO<PageDTO<CalendarDTO>> queryCalenderAssemble(@Validated  CalendarPageQuery calendarPageQuery) {
        return JsonVO.success(iCalCalendarService.listPublicCalendars(calendarPageQuery));
    }

    @Override
    @PostMapping("insert-calendar")
    @ApiOperation("新建日历")
    public JsonVO<Boolean> insertCalendar(@ApiParam(value = "新建日历信息", required = true)
                                          @RequestBody InsertCalendarDTO insertCalendarDTO) {
        try {
            boolean result = iCalCalendarService.insertCalendar(insertCalendarDTO);
            if (result) {
                return JsonVO.success(true);
            } else {
                return JsonVO.create(false, 500, "新建日历失败，可能是由于数据库错误或日历名称已存在");
            }
        } catch (IllegalArgumentException e) {
            return JsonVO.create(false, 400, e.getMessage()); // 返回自定义的参数错误信息
        } catch (Exception e) {
            return JsonVO.create(false, 500, "新建日历时发生未知错误: " + e.getMessage());
        }
    }

    @Override
    @PostMapping("delete-calendar")
    @ApiOperation("删除日历")
    public JsonVO<Boolean> deleteCalendar(
            @ApiParam(value = "日历 ID", required = true)
            @RequestParam String xid) {  // 使用 @RequestParam 明确声明请求参数
        // 检查 xid 是否有效
        if (StringUtils.isBlank(xid)) {
            return JsonVO.create(false, 400, "无效的 xid");
        }

        // 删除相关的子表记录
        boolean deleteSubTablesResult = iCalCalendarService.deleteCalendarSubRecords(xid);
        if (!deleteSubTablesResult) {
            return JsonVO.create(false, 500, "删除子表记录失败");
        }

        // 调用 MyBatis-Plus 提供的 removeById 方法删除主表记录
        boolean result = iCalCalendarService.deleteCalendar(xid);
        if (result) {
            return JsonVO.success(true); // 删除成功
        } else {
            return JsonVO.create(false, 404, "删除失败，日历不存在");
        }
    }

    @ApiOperation("查询日历信息")
    @GetMapping("query-calendar")
    @Override
    public JsonVO<CalendarInfoVO> queryCalendarInfo(String xid) {
        return JsonVO.success(calCalendarService.queryCalendarInfo(xid));
    }

    @ApiOperation("查询日历列表")
    @GetMapping("query-calendars")
    @Override
    public JsonVO<List<CalendarInfoVO>> queryCalendarInfo() {
        return JsonVO.success(calCalendarService.queryCalendarInfo());
    }

    @ApiOperation("修改日历信息")
    @PutMapping("modify-calendar")
    @Override
    public JsonVO<Boolean> modifyCalendarInfo(CalendarDTO calendarDTO) {
        return JsonVO.success(calCalendarService.modifyCalendarInfo(calendarDTO));
    }
}
