#pragma once

#ifndef _CALEVENTSVO_H_
#define _CALEVENTSVO_H_



//此vo用于接收查询到的日志列表，即多条日志


#include "../../GlobalInclude.h"
#include "../../../../lib-oatpp/include/oatpp/core/macro/codegen.hpp"
#include "../../../../lib-oatpp/include/oatpp/core/Types.hpp"
#include OATPP_CODEGEN_BEGIN(DTO)

//定义一个用于获取日程信息的传输数据模型（即单条数据字段）
class CalEventsVO :public oatpp::DTO
{
	DTO_INIT(CalEventsVO, DTO);
	//日程id（主键）
	API_DTO_FIELD(String, calEventId, ZH_WORDS_GETTER("calender.event.xid"), true, "2fe6315f-2d53-406e-a605-bf48895e4d7b");
	//日程标题
	API_DTO_FIELD(String, calEventTitle, ZH_WORDS_GETTER("calender.event.xtitle"), true, ZH_WORDS_GETTER("cal.default.default_title"));

	//日程开始时间
	API_DTO_FIELD(String, calStartTime, ZH_WORDS_GETTER("calender.event.xstartTime"), true, "2024-10-23 18:00:00");

	//日程结束时间
	API_DTO_FIELD(String, calEndTime, ZH_WORDS_GETTER("calender.event.xendTime"), true, "2024-10-23 19:00:00");

	//日程显示颜色
	API_DTO_FIELD(String, color, ZH_WORDS_GETTER("calender.event.xcolor"), true, "#f75f59");

	//日程地点
	API_DTO_FIELD(String, location, ZH_WORDS_GETTER("calender.event.xlocation"), true, ZH_WORDS_GETTER("cal.default.default_location"));

	//提醒时间
	//API_DTO_FIELD(String, valarmTime_config, ZH_WORDS_GETTER("calender.event.xvalarmTime_config"), true, "2024-10-23 17:30:00");

	//是否全天
	API_DTO_FIELD(Int32, isAllDayEvent, ZH_WORDS_GETTER("calender.event.xisAllDayEvent"), true, 1);
};



//定义一个用于获取日程信息集合的对象(即放在集合中一次性全传)
//这个对象是基于上面的日志对象的

class CalAllEventsVO :public oatpp::DTO
{
	DTO_INIT(CalAllEventsVO, DTO);
	API_DTO_FIELD(Int64, total, ZH_WORDS_GETTER("calender.event.event_total"), true, 1);
	API_DTO_FIELD(List<CalEventsVO::Wrapper>, event_rows, ZH_WORDS_GETTER("calender.event.event_rows"), true, {});

public:
	void addData(CalEventsVO::Wrapper vo) {
		this->event_rows->push_back(vo);
	}
};


#include OATPP_CODEGEN_END(DTO)

#endif
