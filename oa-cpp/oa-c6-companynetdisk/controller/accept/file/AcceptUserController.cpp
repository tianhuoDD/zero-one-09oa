#include"stdafx.h"
#include"AcceptUserController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "service/accept/file/AcceptListService.h"



AcceptUserListJsonVO::Wrapper AcceptUserController::execqueryUsersByXunique(const AcceptUserListQuery::Wrapper& query)
{

	// 定义一个Service
	AcceptListService service;
	// 查询数据
	auto result = service.user_listAll(query);
	// 响应结果
	auto jvo = AcceptUserListJsonVO::createShared();
	jvo->success(result);
	return jvo;
};