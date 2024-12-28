package com.zeroone.star.calmanager.service.impl;

import com.alibaba.nacos.shaded.org.checkerframework.checker.units.qual.C;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import cn.hutool.log.Log;
import com.alibaba.nacos.shaded.org.checkerframework.checker.units.qual.C;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.github.xiaoymin.knife4j.spring.annotations.EnableKnife4j;
import com.zeroone.star.calmanager.entity.CalCalendar;
import com.zeroone.star.calmanager.entity.CalEvent;
import com.zeroone.star.calmanager.entity.CalEventRepm;
import com.zeroone.star.calmanager.mapper.CalCalendarMapper;
import com.zeroone.star.calmanager.mapper.CalEventMapper;
import com.zeroone.star.calmanager.mapper.CalEventRepmMapper;
import com.zeroone.star.calmanager.service.ICalEventService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j6.calendar.EventDetailDTO;
import com.zeroone.star.project.dto.j6.calendar.InOneDayEventsDTO;
import com.zeroone.star.project.query.j6.calendar.EventsListQuery;
import com.zeroone.star.project.vo.j6.calendar.EventsListVO;
import org.mapstruct.Mapper;
import org.springframework.beans.BeanUtils;
import com.zeroone.star.project.dto.j6.calendar.CalendarEventDTO;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import javax.transaction.xa.Xid;
import java.time.*;
import java.time.format.DateTimeFormatter;
import java.util.*;
@Mapper(componentModel = "spring")
interface MsEventMapper{
    EventDetailDTO calEventToEventDetailDto(CalEvent calEvent);
    CalEvent eventDetailDtoToCalEvent(EventDetailDTO eventDetailDTO);
}


/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author lee
 * @since 2024-10-23
 */
@Service
public class CalEventServiceImpl extends ServiceImpl<CalEventMapper, CalEvent> implements ICalEventService {
    @Resource
    MsEventMapper msEventMapper;
    /**
     *根据日程id查询日程详情
     * @param id 日程id
     * @return 日程详情dto
     */
    @Override
    public EventDetailDTO queryEventDetails(String id) {
        //根据id查询
        CalEvent calEvent = baseMapper.selectById(id);
        if(calEvent != null){
            //如果查询结果不为空
            return msEventMapper.calEventToEventDetailDto(calEvent);
        }
        //利用全局异常捕获器向前端反馈id错误
        throw new RuntimeException("id错误，未查询到日程信息");
    }
    /**
     * 修改日程详细信息
     * @param detailDTO 日程详细信息
     * @return 该日程id
     */
    @Override
    public String updateEventDetails(EventDetailDTO detailDTO) {
        //将dto对象转为do对象，方便mapper层修改数据库
        CalEvent calEvent = msEventMapper.eventDetailDtoToCalEvent(detailDTO);
        //更新updatetime字段
        calEvent.setXupdateTime(LocalDateTime.now());
        //更新XdaysOfDuration字段
        LocalDate startTime = detailDTO.getXstartTime().toLocalDate();
        LocalDate endTime = detailDTO.getXendTime().toLocalDate();
        if(detailDTO.getXisAllDayEvent()){
            //如果是全天事件
            calEvent.setXdaysOfDuration((int) ChronoUnit.DAYS.between(startTime,endTime)+1);
        }else {
            //如果不是全天事件 就需要判断是否跨越一天
            if(!startTime.equals(endTime)) {
                //如果事件跨越了一天
                calEvent.setXdaysOfDuration((int) ChronoUnit.DAYS.between(startTime,endTime)+1);
            }else {
                //如果事件没有跨越一天
                calEvent.setXdaysOfDuration(0);
            }
        }
        //更新 startTimeStr endTimeStr 字段
        calEvent.setXstartTimeStr(detailDTO.getXstartTime().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
        calEvent.setXendTimeStr(detailDTO.getXendTime().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
        //TODO:修改calevent的字段信息（updateperson）
        //根据id更新数据库
        int flag = baseMapper.updateById(calEvent);
        if(flag == 0){
            //id错误没有修改数据
            throw new RuntimeException("id异常，本次操作没有修改数据");
        }
        //返回日程的id
        return detailDTO.getXid();
    }

    /**
     * 获取日程列表
     * @param query 查询参数
     * @return 日程列表
     */
    @Override
    //TODO : 感觉逻辑太复杂 应该会有优化的空间  后续可以优化
    public EventsListVO queryEventsList(EventsListQuery query) {
        //构建查询条件
        QueryWrapper<CalEvent> queryWrapper  = new QueryWrapper<>();
        //查询条件为 时间位于starttime和endtime之间，且日历id也要属于calendarids
        queryWrapper.between("xstartTime",query.getStartTime(),query.getEndTime()).in("xcalendarId",query.getCalendarIds());
        //挑选出满足条件的日程
        List<CalEvent> calEvents = baseMapper.selectList(queryWrapper);
        //新建wholeDayEvents用来存放持续时间超过一天的日程
        List<EventDetailDTO> wholeDayEvents = new ArrayList<>();
        //新建inOneDayEventsDTOList用来存放在一天之内的日程,并且对其初始化
        List<InOneDayEventsDTO> inOneDayEventsDTOList = initOneDayEvents(query);
        //通过得到日程的XdaysOfDuration字段来判断日程持续时间是否超过一天
        for (CalEvent calEvent : calEvents) {
            if(calEvent.getXdaysOfDuration() >= 1){
                //如果日程持续时间超过一天 则存放到wholeDayEvents列表中
                EventDetailDTO detailDTO = msEventMapper.calEventToEventDetailDto(calEvent);
                wholeDayEvents.add(detailDTO);
            }else {
                //如果日程持续时间没有超过一天 则存放到inOneDayEventsDTOList中日程所处的那一天的列表中
                for (InOneDayEventsDTO eventsDTO : inOneDayEventsDTOList) {
                    if(eventsDTO.getEventDate().equals(calEvent.getXendTime().toLocalDate())){
                        List<EventDetailDTO> inOneDayEvents = eventsDTO.getInOneDayEvents();
                        inOneDayEvents.add(msEventMapper.calEventToEventDetailDto(calEvent));
                        break;
                    }
                }
            }
        }
        //创建vo
        EventsListVO eventsListVO = new EventsListVO();
        eventsListVO.setWholeDayEvents(wholeDayEvents);
        eventsListVO.setInOneDayEvents(inOneDayEventsDTOList);
        return eventsListVO;
    }

    /**
     * 一天日程列表的初始化
     * @param query 主要是为了得到startTime 和endTime 方便初始化
     * @return 初始化后的列表
     */
    private List<InOneDayEventsDTO> initOneDayEvents(EventsListQuery query) {
        List<InOneDayEventsDTO> inOneDayEventsDTOList = new ArrayList<>();
        //将开始和结束时间转换为localDate
        LocalDate stratDate = query.getStartTime().toLocalDate();
        LocalDate endDate = query.getEndTime().toLocalDate();
        //位于开始和结束时间之内的每一天都要创建一个InOneDayEventsDTO对象
        for(LocalDate date = stratDate ; date.isBefore(endDate.plusDays(1));date = date.plusDays(1)){
            InOneDayEventsDTO eventsDTO = new InOneDayEventsDTO();
            //设置当天的日期值（后续需要通过这个日期来对应存放日程）
            eventsDTO.setEventDate(date);
            //初始化一个日程列表
            eventsDTO.setInOneDayEvents(new ArrayList<>());
            inOneDayEventsDTOList.add(eventsDTO);
        }
        return inOneDayEventsDTOList;
    }
    @Autowired
    private  CalEventMapper calEventMapper;
   @Autowired
    private CalEventRepmMapper calEventRepmMapper;
   @Autowired
   private CalCalendarMapper calendarMapper ;
    /**
     * 根据类型删除日程
     * @param xid
     * @param type
     * @return
     */
    @Override
    public String removeByIdandType(String xid, Integer type) {

        if(type==0)
        { //查询到当前的日程的实体类
            CalEvent calEvent=calEventMapper.selectById(xid);
            if(calEvent==null)
            {
                throw new RuntimeException("未查询到该日程");
            }
            calEventMapper.deleteById(xid);
            return calEvent.getXid();
        }else if(type==1)//删除当前日程和之后的重复日程。
        {
            //查询到当前的日程的实体类
            CalEvent   calEvent=calEventMapper.selectById(xid);
            if(calEvent==null)
            {
                throw new RuntimeException("未查询到该日程");
            }
             //构建删除条件
            QueryWrapper<CalEvent> queryWrapper = Wrappers.query();
            queryWrapper.eq("xrepeatMasterId", calEvent.getXrepeatMasterId())
                    .ge("xstartTime", calEvent.getXstartTime());
         calEventMapper.delete(queryWrapper);
            return calEvent.getXid();
        }else{//type==2 删除全部重复日程
             //查询到当前的日程的实体类
            CalEvent  calEvent=calEventMapper.selectById(xid);
            if(calEvent==null)
            {
                throw new RuntimeException("未查询到该日程");
            }
            QueryWrapper<CalEvent> queryWrapper = Wrappers.query();
            queryWrapper.eq("xrepeatMasterId", calEvent.getXrepeatMasterId());
         int i=   calEventMapper.delete(queryWrapper);
            calEventRepmMapper.deleteById(calEvent.getXrepeatMasterId());
            if(i==0){//未查询到日程
                throw new RuntimeException("删除失败，未查询到该日程");
            }
            return calEvent.getXid();
        }
    }
    /**
     * 添加日程
     * @param calendarEventDTO
     * @return
     */
    @Override
    public String addCalEvent(CalendarEventDTO calendarEventDTO) {
        CalEvent calEvent =new CalEvent();
        BeanUtils.copyProperties(calendarEventDTO,calEvent);
        //todo 后续需要完善 ，调用日历接口为日程部分字段赋值。
//       CalCalendar calendar= calendarMapper.selectById(calendarEventDTO.getXcalendarId());
//       if(calendar==null)
//       {
//           throw new RuntimeException("日历不存在");
//       }
        //使用dateToLocalDateTime函数将 data换成localtime类型
        //对calEvent进行赋值
        calEvent.setXstartTime(dateToLocalDateTime(calendarEventDTO.getXstartTime()));
        calEvent.setXstartTimeStr(calEvent.getXstartTime().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
        calEvent.setXendTime(dateToLocalDateTime(calendarEventDTO.getXendTime()));
        calEvent.setXendTimeStr(calEvent.getXendTime().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
        calEvent.setXcreateTime(LocalDateTime.now());
        calEvent.setXupdateTime(LocalDateTime.now());
        //生成xid
        calEvent.setXid(generateUUID());
        //生成使用  generateXSequence() 函数生成xsequence字段的时间戳加上xid
        calEvent.setXvalarmtimeConfig(calendarEventDTO.getXvalarmTime_config());
        calEvent.setXvalarmSummary(calendarEventDTO.getXvalarm_Summary());
        calEvent.setXvalarmDescription(calendarEventDTO.getXvalarm_description());
        calEvent.setXsequence(generatetimestampPart()+calEvent.getXid());
        calEvent.setXisAllDayEvent(calendarEventDTO.isXisAllDayEvent());
        calEvent.setXalarm(calendarEventDTO.isXalarm());
        calEvent.setXeventType("CAL_EVENT");
        calEvent.setXalarmAlready(false);
        //设置了提醒时间
        if(calEvent.getXalarm())
        {
            //设置提醒时间
          calEvent.setXalarmTime(AlarmTime(calEvent.getXstartTime(),calEvent.getXvalarmtimeConfig()));
        }
            int i=  calEventMapper.insert(calEvent);
        if(i==0)
        {
            throw new RuntimeException("添加失败");
        }
        return calEvent.getXid();
    }

    /**
     * 添加日程时 data 类型转成localdatetime
     * @param date
     * @return
     */
    public static LocalDateTime dateToLocalDateTime(Date date) {
        if (date == null) {
            return null;
        }
        Instant instant = date.toInstant();
        return instant.atZone(ZoneId.systemDefault()).toLocalDateTime();
    }

    /**
     * 添加日程时 根据时间生成唯一标识
     * @return
     */
    public static String generatetimestampPart() {
        // 生成时间戳部分
        LocalDateTime now = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyyMMddHHmmssSSS");
        String timestampPart = now.format(formatter);
        return timestampPart ;
    }

    /**
     * 添加日程时 生成uuid
     * @return
     */
    public static String generateUUID() {
        // 生成 UUID 部分
        UUID uuid = UUID.randomUUID();
        String uuidPart = uuid.toString();
        return uuidPart;
    }
    /**
     * 添加日程时 获取指定月份的所有特定周几的日期。
     * @param dateTime 用于确定年份和月份的日期时间
     * @param dayOfWeek 指定的周几
     * @return 包含该月所有指定周几日期的列表
     */
    public static List<LocalDateTime> getSpecificDaysInMonth(LocalDateTime dateTime, DayOfWeek dayOfWeek) {
        // 创建一个列表来存储所有的指定周几
        List<LocalDateTime> specificDays = new ArrayList<>();
        // 将LocalDateTime转换为LocalDate
        LocalDate date = dateTime.toLocalDate();
        // 获取当月的第一天
        LocalDate firstDayOfMonth = date.withDayOfMonth(1);
        // 获取当月的最后一天
        LocalDate lastDayOfMonth = date.withDayOfMonth(date.lengthOfMonth());
        // 从当月的第一天开始遍历到当月的最后一天
        for (LocalDate day = firstDayOfMonth; !day.isAfter(lastDayOfMonth); day = day.plusDays(1)) {
            // 检查这一天是否是指定的周几
            if (day.getDayOfWeek() == dayOfWeek) {
                // 如果是指定的周几，则将其转换为LocalDateTime并添加到列表中
                LocalDateTime specificDay = LocalDateTime.of(day, dateTime.toLocalTime());
                specificDays.add(specificDay);
            }
        }
        return specificDays;
    }
    /**
     * 添加日程时，通过配置字符串，写出提醒时间
     * @param dateTime
     * @param config
     * @return
     */
    public static LocalDateTime AlarmTime(LocalDateTime dateTime, String config) {
        String[] parts = config.split(",");
        if (parts.length != 4) {
            throw new IllegalArgumentException("注意配置提醒时间字符串格式");
        }
        int dayOffset = Integer.parseInt(parts[0]);
        int hourOffset = Integer.parseInt(parts[1]);
        int minuteOffset = Integer.parseInt(parts[2]);
        int secondOffset = Integer.parseInt(parts[3]);
        return dateTime.plusDays(dayOffset)
                .plusHours(hourOffset)
                .plusMinutes(minuteOffset)
                .plusSeconds(secondOffset);
    }
}
