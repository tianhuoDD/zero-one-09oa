#include "stdafx.h"
#include "PersonlistController.h"
#include "../../service/gets-person-lists/PersonlistService.h"

PersonlistPageJsonVO::Wrapper PersonlistController::executeQueryPersonList(const PersonlistQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	PersonlistService service;
	// 查询数据
	auto result = service.listPersonInfo(query);
	// 响应结果
	auto jvo = PersonlistPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
