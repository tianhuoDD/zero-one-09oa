#include "stdafx.h"
#include "CalendarListService.h"
#include "../../dao/calendar/CalendarListDAO.h"


oatpp::List<CalenderListDTO::Wrapper> CalendarListService::queryCalenderList(const string& id) {

	//	构建返回对象
	//oatpp::List<CalenderListDTO::Wrapper> result;
	auto result = oatpp::List<CalenderListDTO::Wrapper>::createShared();

	//	查询数据
	CalendarListDAO dao;
	list<cal_calendarDO> sum = dao.selectByXsequence(id);

	//	将DO转化为DTO
	for (cal_calendarDO sub : sum) {
		auto dto = CalenderListDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, xId, xname, xName, xtype, xType, xcolor, xColor);
		result->emplace_back(dto);
	}

	return result;
}