#include "stdafx.h"
#include "ModifyDutyController.h"
#include "../service/OrgDutyService.h"
#include "ApiDeclarativeServicesHelper.h"

StringJsonVO::Wrapper ModifyDutyController::execModifyDuty(const OrgDutyDTO::Wrapper& dto)
{
	auto jvo = StringJsonVO::createShared();

	// 非空校验和有效值校验
	if (!dto->xname || !dto->xdescription || dto->xname->empty() || dto->xdescription->empty())
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	OrgDutyService service;

	if (service.updateData(dto))
	{
		jvo->success(dto->xid);
	}
	else
	{
		jvo->fail(dto->xid);
	}

	return jvo;
}