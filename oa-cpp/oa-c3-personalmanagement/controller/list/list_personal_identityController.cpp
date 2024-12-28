
#include "stdafx.h"
#include "list_personal_identityController.h"
//server
#include "service/list/list_personal_identityService.h"
#include "../ApiDeclarativeServicesHelper.h"


listPageJsonVO::Wrapper list_personal_identityController::execQuerylist_personal_identity(const list_personal_identityQuery::Wrapper& query, const PayloadDTO& payload)
{

	// 定义一个Service
	list_personal_identityService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = listPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
