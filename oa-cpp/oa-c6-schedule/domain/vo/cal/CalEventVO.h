#pragma once
#ifndef _CALEVENTVO_H_
#define _CALEVENTVO_H_

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

//定义一个用于获取日程信息的传输数据模型（即单条数据字段）


class CalEventVO :public oatpp::DTO
{
	DTO_INIT(CalEventVO, DTO);
	//日程所属日历
	API_DTO_FIELD(String, calendarId, ZH_WORDS_GETTER("calender.event.xcalendarId"), true, "601faa3f-d65f-41b2-85cf-738b065261da");
	
	//日程标题
	API_DTO_FIELD(String, calEventTitle, ZH_WORDS_GETTER("calender.event.xtitle"), true, ZH_WORDS_GETTER("calender.default.default_title"));
	
	//日程开始时间
	API_DTO_FIELD(String, calStartTime, ZH_WORDS_GETTER("calender.event.xstartTime"), true, "2024-10-23 18:00:00");
	
	//日程结束时间
	API_DTO_FIELD(String, calEndTime, ZH_WORDS_GETTER("calender.event.xendTime"), true, "2024-10-23 19:00:00");
	
	//日程显示颜色
	API_DTO_FIELD(String, color, ZH_WORDS_GETTER("calender.event.xcolor"), true, "#f75f59");
	
	//日程内容
	API_DTO_FIELD(String, comment, ZH_WORDS_GETTER("calender.event.xcomment"), true, ZH_WORDS_GETTER("calender.default.default_comment"));
	
	//日程地点
	API_DTO_FIELD(String, location, ZH_WORDS_GETTER("calender.event.xlocation"), true, ZH_WORDS_GETTER("calender.default.default_location"));
	
	//提醒时间
	//API_DTO_FIELD(String, valarmTime_config, ZH_WORDS_GETTER("calender.event.xvalarmTime_config"), true, "2024-10-23 17:30:00");
	
	//重复规则（每天、每月、每年...）
	API_DTO_FIELD(String, recurrenceRule, ZH_WORDS_GETTER("calender.event.xrecurrenceRule"), true, "FREQ=DAILY;UNTIL=20241024T160000Z");
	
	//是否全天
	API_DTO_FIELD(Int32, isAllDayEvent, ZH_WORDS_GETTER("calender.event.xisAllDayEvent"), true, 1);
	

};

#include OATPP_CODEGEN_END(DTO)
#endif
