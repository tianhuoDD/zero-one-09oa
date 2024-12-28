#include "stdafx.h"
#include "AddDutyController.h"
#include "../service/OrgDutyService.h"
#include "ApiDeclarativeServicesHelper.h"
#include "../../lib-common/include/SnowFlake.h"
#include "AddDutyController.h"

StringJsonVO::Wrapper AddDutyController::execAddDuty(const OrgDutyDTO::Wrapper& dto)
{
	auto  jvo = StringJsonVO::createShared();
	// 非空校验和有效值校验
	if (!dto->xname || !dto->xdescription || dto->xname->empty() || dto->xdescription->empty())
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	OrgDutyService service;

	string id = service.saveData(dto);

	if (id.size() > 0)
	{
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}

	return jvo;
}
