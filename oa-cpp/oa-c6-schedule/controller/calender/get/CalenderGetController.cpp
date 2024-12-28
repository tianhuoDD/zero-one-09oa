#include "stdafx.h"
#include "CalenderGetController.h"
#include "../../../service/calendar/CalendarListService.h"
#include "../../../service/calendar/CalendarInfoService.h"
#include <iostream>

CalenderInfoJsonVo::Wrapper CalenderGetController::execQueryCalenderInfo(const String& xid, const PayloadDTO& payload) {

	//	传入参数检验
	
	if (!xid) {
		std::cout << "请输入需要查询的日历ID" << std::endl;
		return {};
	}
	else {
		//	Service层
		CalendarInfoService service;
		//	查询日历详细
		auto result = service.queryCalendarInfo(xid);
		//	响应结果
		auto jvo = CalenderInfoJsonVo::createShared();
		jvo->success(result);

		return jvo;
	}

	
	//return {};
}

CalenderListJsonVO::Wrapper CalenderGetController::execQueryCalenderList(const PayloadDTO& payload) {

	//std::cout << "进入controller层" << std::endl;

	//	数据检验:  但是这个接口是无参的...
	string id = payload.getId();
	//	Service层
	CalendarListService service;
	//	查询日历列表
	auto result = service.queryCalenderList(id);	//	从负载中拿出用户id作为查询参数
	//	响应结果
	auto jvo = CalenderListJsonVO::createShared();

	jvo->success(result);

	return jvo;
}