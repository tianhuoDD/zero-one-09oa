#include "stdafx.h"
#include "PersonalManagementController.h"

#include "../ApiDeclarativeServicesHelper.h"
Uint64JsonVO::Wrapper PersonManagementController::execModifyDuty(const DutySettingDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//非空校验
	if (dto->xidentity->empty()) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	DutySettingService service;
	if (service.DutySetting(dto) == dto->unitduty_xid->size()) {
		jvo->success(UInt64(1));
	}
	else {
		jvo->fail(UInt64(1));
	}
	return jvo;
}

SearchDutyJsonVO::Wrapper PersonManagementController::execQueryDuty(const String& xname)
{
	// 定义一个Service
	SearchDutyService service;
	// 查询数据
	auto result = service.listAll(xname);
	// 响应结果
	auto jvo = SearchDutyJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

RoleInfoPageJsonVO::Wrapper PersonManagementController::execQueryRole(const RoleInfoQuery::Wrapper& roleinfoQuery)
{
	// 定义一个Service
	RoleInfoService service;
	// 查询数据
	auto result = service.listAll(roleinfoQuery);
	// 响应结果
	auto jvo = RoleInfoPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


