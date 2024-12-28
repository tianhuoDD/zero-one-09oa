package com.zeroone.star.systemhome.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.project.dto.j1.systemhome.SchedulePreviewDTO;
import com.zeroone.star.systemhome.entity.OrgGroupPersonlist;
import com.zeroone.star.systemhome.entity.cal_event.*;
import com.zeroone.star.systemhome.mapper.*;
import com.zeroone.star.systemhome.service.SchedulePreviewService;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsSchedulePreviewMapper{
    /**
     * 将calEvent转换成SchedulePreviewDTO
     * @param  calEvent 日程事件
     * @return 转换结果
     */
    SchedulePreviewDTO calEvent2SchedulePreviewDTO(CalEvent calEvent);

    /**
     * 将calEventRepm转换成SchedulePreviewDTO
     * @param  calEventRepm 日程事件
     * @return 转换结果
     */
    SchedulePreviewDTO calEventRepm2SchedulePreviewDTO(CalEventRepm calEventRepm);
}
/**
 * @author 李云毅
 * @version 1.0.0
 * 2024/10/26
 */
@Service
public class SchedulePreviewServiceImpl implements SchedulePreviewService {

    //非重复事件
    @Resource
    CalEventMapper calEventMapper;
    @Resource
    CalEventParticipantsMapper calEventParticipantsMapper;
    @Resource
    CalEventViewablepersonlistMapper calEventViewablepersonlistMapper;
    @Resource
    CalEventViewablegrouplistMapper calEventViewablegrouplistMapper;
    @Resource
    CalEventViewableunitlistMapper calEventViewableunitlistMapper;

    //重复事件
    @Resource
    CalEventRepmMapper calEventRepmMapper;
    @Resource
    CalEventRepmParticipantsMapper calEventRepmParticipantsMapper;
    @Resource
    CalEventRepmViewablepersonlistMapper calEventRepmViewablepersonlistMapper;
    @Resource
    CalEventRepmViewablegrouplistMapper calEventRepmViewablegrouplistMapper;
    @Resource
    CalEventRepmViewableunitlistMapper calEventRepmViewableunitlistMapper;

    @Resource
    MsSchedulePreviewMapper msSchedulePreviewMapper;

    @Resource
    OrgGroupPersonlistMapper orgGroupPersonlistMapper;
    @Resource
    OrgGroupUnitlistMapper orgGroupUnitlistMapper;


    @Override
    public List<SchedulePreviewDTO> listSchedulePreview(Date chooseDate, String person) {
        //返回的dto
        List<SchedulePreviewDTO> schedulePreviewDTOList = new ArrayList<>();

        //非重复日程
        //根据person查询相关日程id
        List<String> idList = selectIdList(person);
        //筛选出list中符合当天的条件的日程 遍历idList
        idList.forEach(i -> {
            CalEvent calEvent = filterCalEvent(i, chooseDate);
            //不为空 将结果转换为dto并加入到schedulePreviewDTOList
            if (calEvent != null) {
                SchedulePreviewDTO dto = msSchedulePreviewMapper.calEvent2SchedulePreviewDTO(calEvent);
                schedulePreviewDTOList.add(dto);
            }
        });

        //重复日程
        //根据person查询相关日程id（重复）
        List<String> idListRepm = selectIdListRepm(person);
        //筛选出list中符合当天的条件的日程 遍历idListRepm
        idListRepm.forEach(i -> {
            CalEventRepm calEventRepm = filterCalEventRepm(i, chooseDate);
            if (calEventRepm != null) {
                schedulePreviewDTOList.add(msSchedulePreviewMapper.calEventRepm2SchedulePreviewDTO(calEventRepm));
            }
        });

        return schedulePreviewDTOList;
    }

    /**
     * 根据person查询相关日程id（非重复）
     * @param person 用户名称
     * @return 查询结果
     */
    private List<String> selectIdList(String person) {
        List<String> idList = new ArrayList<>();
        //查询自己创建的日程的id
        QueryWrapper<CalEvent> wrapper = new QueryWrapper<>();
        wrapper.select("xid").eq("xcreatePerson", person);
        calEventMapper.selectList(wrapper).forEach(i -> {
            idList.add(i.getXid());
        });
        //查询参与的日程id
        QueryWrapper<CalEventParticipants> wrapper1 = new QueryWrapper<>();
        wrapper1.select("CALENDAR_EVENT_XID").like("xparticipants",person);
        calEventParticipantsMapper.selectList(wrapper1).forEach(i -> {
            idList.add(i.getCalendarEventXid());
        });
        //查询viewable的日程id
        QueryWrapper<CalEventViewablepersonlist> wrapper2 = new QueryWrapper<>();
        wrapper2.select("CALENDAR_EVENT_XID").like("xviewablePersonList",person);
        calEventViewablepersonlistMapper.selectList(wrapper2).forEach(i -> {
            idList.add(i.getCalendarEventXid());
        });
        //查询组织相关的日程id



        //查询群组相关的日程id
        //用户所在的group
        List<String> groupList = getGroupList(person);
        groupList.forEach(i -> {
            QueryWrapper<CalEventViewablegrouplist> wrapper3 = new QueryWrapper<>();
            wrapper.select("CALENDAR_EVENT_XID").like("xviewableGroupList",i);
            CalEventViewablegrouplist selectedOne = calEventViewablegrouplistMapper.selectOne(wrapper3);
            if (selectedOne != null) {
                idList.add(selectedOne.getCalendarEventXid());
            }
        });

        return idList;
    }

    /**
     * 根据person查询相关日程id（重复）
     * @param person 用户名称
     * @return 查询结果
     */
    private List<String> selectIdListRepm(String person) {
        List<String> idlist = new ArrayList<>();
        //查询自己创建的日程的id
        QueryWrapper<CalEventRepm> wrapper5 = new QueryWrapper<>();
        wrapper5.select("xid").eq("xcreatePerson",person);
        calEventRepmMapper.selectList(wrapper5).forEach(i -> {
            idlist.add(i.getXid());
        });
        //查询参与的日程id
        QueryWrapper<CalEventRepmParticipants> wrapper6 = new QueryWrapper<>();
        wrapper6.select("CALENDAR_EVENTREPEATMASTER_XID").like("xparticipants",person);
        calEventRepmParticipantsMapper.selectList(wrapper6).forEach(i -> {
            idlist.add(i.getCalendarEventrepeatmasterXid());
        });
        //查询viewable的日程id
        QueryWrapper<CalEventRepmViewablepersonlist> wrapper7 = new QueryWrapper<>();
        wrapper7.select("CALENDAR_EVENTREPEATMASTER_XID").like("xviewablePersonList",person);
        calEventRepmViewablepersonlistMapper.selectList(wrapper7).forEach(i -> {
            idlist.add(i.getCalendarEventrepeatmasterXid());
        });
        //查询组织相关的日程id

        //查询群组相关的日程id
        List<String> groupList = getGroupList(person);
        groupList.forEach(i -> {
            QueryWrapper<CalEventRepmViewablegrouplist> wrapper3 = new QueryWrapper<>();
            wrapper3.select("CALENDAR_EVENTREPEATMASTER_XID").like("xviewableGroupList",person);
            CalEventRepmViewablegrouplist selectedOne = calEventRepmViewablegrouplistMapper.selectOne(wrapper3);
            if (selectedOne != null) {
                idlist.add(selectedOne.getCalendarEventrepeatmasterXid());
            }
        });

        return idlist;
    }

    /**
     * 筛选出list中符合当天的条件的日程（重复）
     * @param s id
     * @param chooseDate 日期
     * @return 查询结果
     */
    private CalEventRepm filterCalEventRepm(String s,Date chooseDate){
        QueryWrapper<CalEventRepm> wrapper4 = new QueryWrapper<>();
        wrapper4.select("xid","xsource","xtitle","xeventType")
                .eq("xalarm",true)
                .le("xalarmTime",chooseDate)
                .ge("xendTime",chooseDate)
                .le("xstartTime", chooseDate)
                .eq("xid",s);
        return calEventRepmMapper.selectOne(wrapper4);
    }

    /**
     * 筛选出list中符合当天的条件的日程（非重复）
     * @param s id
     * @param chooseDate 日期
     * @return 查询结果
     */
    private CalEvent filterCalEvent(String s,Date chooseDate){
        QueryWrapper<CalEvent> wrapper3 = new QueryWrapper<>();
        wrapper3.select("xid","xsource","xtitle","xeventType")
                .eq("xalarm",true)
                .eq("xalarmAlready",true)
                .le("xalarmTime",chooseDate)
                .ge("xendTime",chooseDate)
                .le("xstartTime", chooseDate)
                .eq("xid",s);
        return calEventMapper.selectOne(wrapper3);
    }

    /**
     * 获取person所在的组
     * @param person 用户名称
     * @return 查询结果
     */
    private List<String> getGroupList(String person) {
        QueryWrapper<OrgGroupPersonlist> wrapper = new QueryWrapper<>();
        wrapper.select("GROUP_XID").like("xpersonList",person);
        List<String> list = new ArrayList<>();
        orgGroupPersonlistMapper.selectList(wrapper).forEach(i -> {
            list.add(i.getGroupXid());
        });
        return list;
    }

}
