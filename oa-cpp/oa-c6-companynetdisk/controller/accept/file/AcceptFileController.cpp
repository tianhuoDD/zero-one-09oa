#include"stdafx.h"
#include"AcceptFileController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "service/accept/file/AcceptListService.h"



AcceptFileListJsonVO::Wrapper AcceptFileController::execqueryUsersByXunique(const AcceptFileListQuery::Wrapper& query)
{

	// 定义一个Service
	AcceptListService service;
	// 查询数据
	auto result = service.file_listAll(query);
	// 响应结果
	auto jvo = AcceptFileListJsonVO::createShared();
	jvo->success(result);
	return jvo;

};