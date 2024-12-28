#pragma once


#ifndef _CAL_EVENT_REPM_DO_
#define _CAL_EVENT_REPM_DO_
#include "../../GlobalInclude.h"

/**
 * 重复日程信息实体类
 */
class cal_event_repmDO
{
	// 重复日程id
	CC_SYNTHESIZE(string, xid, xId);
	// 创建时间
	CC_SYNTHESIZE(string, xcreateTime, xCreateTime);
	// 日程序列
	CC_SYNTHESIZE(string, xsequence, xSequence);
	// 更新时间
	CC_SYNTHESIZE(string, xupdateTime, xUpdateTime);
	//分布因子
	CC_SYNTHESIZE(int, xdistributeFactor, xDistributeFactor);
	//是否提醒
	CC_SYNTHESIZE(int, xalarm, xAlarm);
	//提醒时间
	CC_SYNTHESIZE(string, xalarmTime, xAlarmTime);
	//日历id
	CC_SYNTHESIZE(string, xcalendarId, xCalendarId);
	//颜色
	CC_SYNTHESIZE(string, xcolor, xColor);
	//内容
	CC_SYNTHESIZE(string, xcomment, xComment);
	//内容表id
	CC_SYNTHESIZE(string, xcommentId, xCommentId);
	//创建人
	CC_SYNTHESIZE(string, xcreatePerson, xCreatePerson);
	//
	CC_SYNTHESIZE(int, xdaysOfDuration, xDaysOfDuration);
	//结束时间
	CC_SYNTHESIZE(string, xendTime, xEndTime);
	//事件类型
	CC_SYNTHESIZE(string, xeventType, xEventType);
	//是否全天
	CC_SYNTHESIZE(int, xisAllDayEvent, xIsAllDayEvent);
	//是否公开
	CC_SYNTHESIZE(int, xisPublic, xIsPublic);
	//
	CC_SYNTHESIZE(string, xlatitude, xLatitude);
	//地点
	CC_SYNTHESIZE(string, xlocationName, xLocationName);
	//
	CC_SYNTHESIZE(string, xlongitude, xLongitude);
	//
	CC_SYNTHESIZE(string, xrecurrenceExc, xRecurrenceExc);
	//重复方式
	CC_SYNTHESIZE(string, xrecurrenceRule, xRecurrenceRule);
	//重复开始时间
	CC_SYNTHESIZE(string, xrecurrenceStartTime, xRecurrenceStartTime);
	//重复状态
	CC_SYNTHESIZE(string, xrepeatStatus, xRepeatStatus);
	//
	CC_SYNTHESIZE(string, xsource, xSource);
	//日程开始时间
	CC_SYNTHESIZE(string, xstartTime, xStartTime);
	//日程目标类型
	CC_SYNTHESIZE(string, xtargetType, xTargetType);
	//标题
	CC_SYNTHESIZE(string, xtitle, xTitle);
	//更新人
	CC_SYNTHESIZE(string, xupdatePerson, xUpdatePerson);
	//提醒方式
	CC_SYNTHESIZE(string, xvalarmTime_config, xValarmTime_config);
	//总结
	CC_SYNTHESIZE(string, xvalarm_Summary, xValarm_Summary);
	//
	CC_SYNTHESIZE(string, xvalarm_description, xValarm_description);
	//
	CC_SYNTHESIZE(string, xvalarm_mailto, xValarm_mailto);



public:
	cal_event_repmDO() {
		xid = "";
		xcreateTime = "";
		xsequence = "";
		xupdateTime = "";
		xdistributeFactor = NULL;
		xalarm = 0;
		xalarmTime = "";
		xcalendarId = "";
		xcolor = "";
		xcomment = "";
		xcommentId = "";
		xcreatePerson = "";
		xdaysOfDuration = 0;
		xendTime = "";
		xeventType = "";
		xisAllDayEvent = 0;
		xisPublic = 0;
		xlatitude = "";
		xlocationName = "";
		xlongitude = "";
		xrecurrenceExc = "";
		xrecurrenceRule = "";
		xrecurrenceStartTime = "";
		xrepeatStatus = "";
		xsource = "";
		xstartTime = "";
		xtargetType = "";
		xtitle = "";
		xupdatePerson = "";
		xvalarmTime_config = "";
		xvalarm_Summary = "";
		xvalarm_description = "";
		xvalarm_mailto = "";


	}
};

#endif // !_CAL_EVENT_REPM_DO_