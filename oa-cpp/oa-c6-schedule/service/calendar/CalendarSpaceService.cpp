#include "stdafx.h"
#include "CalendarSpaceService.h"
#include "../../dao/calendar/CalendarSpaceDAO.h"
#include "../../domain/do/calendar/cal_calendar_spaceDO.h"

CalendarSpacePageDTO::Wrapper CalendarSpaceService::listAll(const CalendarSpaceQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CalendarSpacePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	CalendarSpaceDAO dao;
	uint64_t count = dao.count();
	if (count <= 0)
	{
		return pages;
	}

	pages->total = count;
	pages->calcPages();
	std::list<cal_calendar_spaceDO> res = dao.queryAll(query);

	for (cal_calendar_spaceDO sub : res)
	{
		auto dto = CalendarSpaceDTO::createShared();

		dto->xid = sub.getXid();
		dto->xcreatetime = sub.getXcreateTime().substr(0, 10);
		dto->xcolor = sub.getXcolor();
		dto->xcreateor = sub.getXcreateor();
		dto->xname = sub.getXname();
		dto->xtype = sub.getXtype();
		dto->xdescription = sub.getXdescription();
		dto->xisfollow = sub.getXisfollow();

		pages->addData(dto);
	}

	return pages;
}