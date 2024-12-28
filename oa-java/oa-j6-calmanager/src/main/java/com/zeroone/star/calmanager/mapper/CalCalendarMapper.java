package com.zeroone.star.calmanager.mapper;

import com.zeroone.star.calmanager.entity.*;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j6.calendar.CalendarDTO;
import com.zeroone.star.project.dto.j6.calendar.InsertCalendarDTO;
import org.apache.ibatis.annotations.Delete;import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.*;

import java.util.Calendar;
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
public interface CalCalendarMapper extends BaseMapper<CalCalendar> {
    // 这里可以添加自定义的查询方法，例如根据xisPublic字段查询公开日历
    List<CalCalendar> selectPublicCalendars();

 @Delete("DELETE FROM cal_calendar WHERE xid = #{xid}")
    boolean deleteById(@Param("xid") String xid);

    @Select("SELECT xdistinguishedName FROM org_unit WHERE xid = #{xid}")
    String selectUnitDistinguishedNameById(@Param("xid") String organizationId);

    @Select("SELECT xdistinguishedName FROM org_person WHERE xid = #{xid}")
    String selectPersonDistinguishedNameById(@Param("xid") String personId);


    @Select("SELECT xdistinguishedName FROM org_person WHERE xname = #{managerName}")
    String selectDistinguishedNameByName(@Param("managerName") String managerName);

    @Insert("INSERT INTO cal_calendar_manageablepersonlist (CALENDAR_XID, xmanageablePersonList, xorderColumn) " +
            "VALUES (#{calendarXid}, #{xmanageablePersonList}, #{xorderColumn})")
    boolean insertManager(CalCalendarManageablepersonlist manageablePerson);

    @Select("SELECT xdistinguishedName FROM org_person WHERE xid = #{personId}")
    String selectDistinguishedNameById(@Param("personId") String personId);

    @Select("SELECT xdistinguishedName FROM org_unit WHERE xid = #{unitId}")
    String selectDistinguishedNameByUnitId(@Param("unitId") String unitId);

    @Select("SELECT xdistinguishedName FROM org_group WHERE xid = #{groupId}")
    String selectDistinguishedNameByGroupId(@Param("groupId") String groupId);

    @Insert("INSERT INTO cal_calendar_viewablepersonlist (CALENDAR_XID, xviewablePersonList, xorderColumn) " +
            "VALUES (#{calendarXid}, #{xviewablePersonList}, #{xorderColumn})")
    boolean insertViewablePerson(CalCalendarViewablepersonlist viewablePerson);

    @Insert("INSERT INTO cal_calendar_viewableunitlist (CALENDAR_XID, xviewableUnitList, xorderColumn) " +
            "VALUES (#{calendarXid}, #{xviewableUnitList}, #{xorderColumn})")
    boolean insertViewableUnit(CalCalendarViewableunitlist viewableUnit);

    @Insert("INSERT INTO cal_calendar_viewablegrouplist (CALENDAR_XID, xviewableGroupList, xorderColumn) " +
            "VALUES (#{calendarXid}, #{xviewableGroupList}, #{xorderColumn})")
    boolean insertViewableGroup(CalCalendarViewablegrouplist viewableGroup);

    @Insert("INSERT INTO cal_calendar_publishablepersonlist (CALENDAR_XID, xpublishablePersonList, xorderColumn) " +
            "VALUES (#{calendarXid}, #{xpublishablePersonList}, #{xorderColumn})")
    boolean insertPublishablePerson(CalCalendarPublishablepersonlist publishablePerson);

    @Insert("INSERT INTO cal_calendar_publishableunitlist (CALENDAR_XID, xpublishableUnitList, xorderColumn) " +
            "VALUES (#{calendarXid}, #{xpublishableUnitList}, #{xorderColumn})")
    boolean insertPublishableUnit(CalCalendarPublishableunitlist publishableUnit);

    @Insert("INSERT INTO cal_calendar_publishablegrouplist (CALENDAR_XID, xpublishableGroupList, xorderColumn) " +
            "VALUES (#{calendarXid}, #{xpublishableGroupList}, #{xorderColumn})")
    boolean insertPublishableGroup(CalCalendarPublishablegrouplist publishableGroup);

    @Delete("DELETE FROM cal_calendar_viewablepersonlist WHERE CALENDAR_XID = #{calendarId}")
    int deleteViewablePersonsByCalendarId(@Param("calendarId") String calendarId);

    @Delete("DELETE FROM cal_calendar_viewableunitlist WHERE CALENDAR_XID = #{calendarId}")
    int deleteViewableUnitsByCalendarId(@Param("calendarId") String calendarId);

    @Delete("DELETE FROM cal_calendar_viewablegrouplist WHERE CALENDAR_XID = #{calendarId}")
    int deleteViewableGroupsByCalendarId(@Param("calendarId") String calendarId);

    @Delete("DELETE FROM cal_calendar_publishablepersonlist WHERE CALENDAR_XID = #{calendarId}")
    int deletePublishablePersonsByCalendarId(@Param("calendarId") String calendarId);

    @Delete("DELETE FROM cal_calendar_publishableunitlist WHERE CALENDAR_XID = #{calendarId}")
    int deletePublishableUnitsByCalendarId(@Param("calendarId") String calendarId);

    @Delete("DELETE FROM cal_calendar_publishablegrouplist WHERE CALENDAR_XID = #{calendarId}")
    int deletePublishableGroupsByCalendarId(@Param("calendarId") String calendarId);

    @Delete("DELETE FROM cal_calendar_manageablepersonlist WHERE CALENDAR_XID = #{calendarId}")
    int deleteManageablePersonsByCalendarId(@Param("calendarId") String calendarId);
}
