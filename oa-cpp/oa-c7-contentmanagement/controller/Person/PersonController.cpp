#include "stdafx.h"
#include "PersonController.h"
#include "../../service/PersonService.h"

PersonInfoPageJsonVO::Wrapper PersonController::execcuteQueryPerson(const PersonQuery::Wrapper& perQuery)
{
	// 定义一个Service
	PersonService service;
	//// 查询数据
	auto result = service.queryPer(perQuery);
	//// 响应结果

	auto jvo = PersonInfoPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

	//return {};
}
