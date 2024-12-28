#include "stdafx.h"
#include "CalendarFollowService.h"
#include "../../dao/calendar/CalendarFollowDAO.h"
#include "../../domain/do/calendar/cal_calendar_followersDO.h"

int CalendarFollowService::addFollow(const CalendarFollowDTO::Wrapper& dto)
{
	cal_calendar_followersDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CalenderId, xid, XfollowersId, xfollowersId, XorderColumn, xorderColumn);
	CalendarFollowDAO dao;
	return dao.insert(data);
}

int CalendarFollowService::removeFollow(const CalendarFollowDTO::Wrapper& dto)
{
	cal_calendar_followersDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CalenderId, xid, XfollowersId, xfollowersId, XorderColumn, xorderColumn);
	CalendarFollowDAO dao;
	return dao.deleteByIdAndName(data);
}