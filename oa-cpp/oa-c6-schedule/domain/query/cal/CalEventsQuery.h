#pragma once
#ifndef _CALEVENTSQUEERY_H_
#define _CALEVENTSQUEERY_H_

#include"../../GlobalInclude.h"
#include"domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//定义一个查询日志列表的对象

class CalEventsQuery :public PageQuery {
	DTO_INIT(CalEventsQuery, PageQuery);
	//添加参数：所属日历
	DTO_FIELD(String, calendarId);
	DTO_FIELD_INFO(calendarId) {
		info->description = ZH_WORDS_GETTER("calender.event.xcalendarId");
	}
	//添加参数：查询的年月
	DTO_FIELD(String, queryDate);
	DTO_FIELD_INFO(queryDate) {
		info->description = ZH_WORDS_GETTER("calender.event.xqueryDate");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_CALENDARQUEERY_H_
