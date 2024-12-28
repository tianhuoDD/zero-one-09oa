#pragma once
#ifndef _CAL_EVENTDO_H_
#define _CAL_EVENTDO_H_
#include "../DoInclude.h"
class cal_eventDO {
	//日志id
	CC_SYNTHESIZE(string, xid, xId);
	// 创建时间
	CC_SYNTHESIZE(string, xcreatetime, xCreateTime);

	CC_SYNTHESIZE(string, xsequence, xSequence);
	// 更新时间
	CC_SYNTHESIZE(string, xupdatetime, xUpdateTime);

	CC_SYNTHESIZE(int, xdistributeFactor, xDistributeFactor);
	//是否提醒
	CC_SYNTHESIZE(int, xalarm, xAlarm);
	//已经提醒几次
	CC_SYNTHESIZE(int, xalarmAlready, xAlarmAlready);
	//
	CC_SYNTHESIZE(string, xalarmTime, xAlarmTime);
	//
	CC_SYNTHESIZE(string, xbundle, xBundle);
	//所属日历id
	CC_SYNTHESIZE(string, xcalendarId, xCalendarId);
	// 颜色
	CC_SYNTHESIZE(string, xcolor, xColor);
	//日志内容
	CC_SYNTHESIZE(string, xcomment, xComment);
	//内容id
	CC_SYNTHESIZE(string, xcommentId, xCommentId);
	//创建者
	CC_SYNTHESIZE(string, xcreatePerson, xCreatePerson);
	//持续天数
	CC_SYNTHESIZE(int, xdaysOfDuration, xDaysOfDuration);
	//结束时间
	CC_SYNTHESIZE(string, xendTime, xEndTime);
	// 日志类型
	CC_SYNTHESIZE(string, xeventType, xEventType);
	// 是否全天
	CC_SYNTHESIZE(int, xisAllDayEvent, xIsAllDayEvent);
	// 是否公开
	CC_SYNTHESIZE(int, xisPublic, xIsPublic);
	//
	CC_SYNTHESIZE(string, xlatitude, xLatitude);
	// 地点
	CC_SYNTHESIZE(string, xlocationName, xLocationName);
	// 
	CC_SYNTHESIZE(string, xlongitude, xLongitude);
	// 
	CC_SYNTHESIZE(string, xrecurrenceExc, xRecurrenceExc);
	//提醒规则
	CC_SYNTHESIZE(string, xrecurrenceRule, xRecurrenceRule);
	// 
	CC_SYNTHESIZE(string, xrepeatMasterId, xRepeatMasterId);
	// 
	CC_SYNTHESIZE(string, xsource, xSource);
	// 开始时间
	CC_SYNTHESIZE(string, xstartTime, xStartTime);
	// 
	CC_SYNTHESIZE(string, xtargetType, xTargetType);
	//日志标题
	CC_SYNTHESIZE(string, xtitle, xTitle);
	// 更新人
	CC_SYNTHESIZE(string, xupdatePerson, xUpdatePerson);
	// 提醒规则（提前几分钟）
	CC_SYNTHESIZE(string, xvalarmTime_config, xValarmTime_config);
	// 
	CC_SYNTHESIZE(string, xvalarm_Summary, xValarm_Summary);
	// 
	CC_SYNTHESIZE(string, xvalarm_description, xValarm_description);

	CC_SYNTHESIZE(string, xvalarm_mailto, xValarm_mailto);
	//重复方式*
	CC_SYNTHESIZE(string, xrepeat, xRepeat);
	//重复结束时间*
	CC_SYNTHESIZE(string, xrepeatUnitDate, xRepeatUnitDate);
	

public:
	cal_eventDO() {
		xid = "2fe6315f-2d53-406e-a605-bf48895e4d7b";
		xcreatetime = "2024-10-20 12:03:34";
		xsequence = "202410201203342fe6315f-2d53-406e-a605-bf48895e4d7b";
		xupdatetime = "2024-10-20 12:03:34";
		xdistributeFactor = 0;
		xalarm = 0;
		xalarmAlready = 0;
		xalarmTime = "2024-10-20 12:03:34";
		xbundle = "null";
		xcalendarId = "601faa3f-d65f-41b2-85cf-738b065261da";
		xcolor = "#f75f59";
		xcomment = "hhh";
		xcommentId = "null";
		xcreatePerson = "xadmin";
		xdaysOfDuration = 0;
		xendTime = "2024-10-20 12:03:34";
		xeventType = "CAL_EVENT";
		xisAllDayEvent = 0;
		xisPublic =0 ;
		xlatitude = "null";
		xlocationName = "labrary";
		xlongitude = "null";
		xrecurrenceExc = "null";
		xrecurrenceRule = "FREQ=DAILY;UNTIL=20241024T160000Z";
		xrepeatMasterId = "6477b5cc-ab18-4b5b-b664-e5a0f36d123d";
		xsource = "PERSONAL";
		xstartTime = "2024-10-23 18:00:00";
		xtargetType = "PERSON";
		xtitle = "event1";
		xupdatePerson = "xadmin";
		xvalarmTime_config = "0,0,-30,0";
		xvalarm_Summary = "";
		xvalarm_description = "null";
		xvalarm_mailto = "null";
		xrepeat = "";
		xrepeatUnitDate = "";
	};
};


#endif