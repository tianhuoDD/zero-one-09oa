#include "stdafx.h"
#include "../../service/calendar/CalendarFollowService.h"
#include "CalendarFollowController.h"

Uint64JsonVO::Wrapper CalendarFollowController::execAddFollow(const CalendarFollowDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();
	if (dto->xid == "" || dto->xorderColumn < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	if (dto->xfollowersId == "")
	{
		dto->xfollowersId = payload.getId();
	}

	CalendarFollowService service;
	if (service.addFollow(dto))
	{
		jvo->init(UInt64(-1), RS_UNAUTHORIZED);
		return jvo;
	}

	jvo->init(UInt64(-1), ResultStatus("success to follow", 10000));
	return jvo;
}

Uint64JsonVO::Wrapper CalendarFollowController::execRemoveFollow(const CalendarFollowDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();
	if (dto->xid == "" || dto->xorderColumn < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	if (dto->xfollowersId == "")
	{
		dto->xfollowersId = payload.getId();
	}

	CalendarFollowService service;
	if (service.removeFollow(dto))
	{
		jvo->init(UInt64(-1), RS_UNAUTHORIZED);
		return jvo;
	}

	jvo->init(UInt64(-1), ResultStatus("success to unfollow", 10000));
	return jvo;
}