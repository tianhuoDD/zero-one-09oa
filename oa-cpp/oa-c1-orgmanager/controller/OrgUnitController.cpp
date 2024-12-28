#include "stdafx.h"
#include "OrgUnitController.h"
#include "../service/OrgUnitService.h"
#include "ApiDeclarativeServicesHelper.h"

OrgUnitJsonVO::Wrapper OrgUnitController::execQuerySample(const OrgUnitQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	OrgUnitService service;
	// 查询数据
	auto result = service.listOne(query);
	// 响应结果
	auto jvo = OrgUnitJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper OrgUnitController::execModifySample(const OrgUnitDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	
	// 定义一个Service
	OrgUnitService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->xid);
	}
	else
	{
		jvo->fail(dto->xid);
	}
	// 响应结果
	return jvo;
}
