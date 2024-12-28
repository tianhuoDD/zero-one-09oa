#pragma once
#ifndef _CALEVENTQUERY_H_
#define _CALEVENTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//定义一个用于查询某个日志详细信息的对象
class CalEventQuery :public PageQuery
{
	DTO_INIT(CalEventQuery, PageQuery);
	//添加参数：你想查询的日志id
	DTO_FIELD(String, calEventId);
	DTO_FIELD_INFO(calEventId) {
		info->description = ZH_WORDS_GETTER("calender.event.xid");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CALEVENTQUERY_H_
