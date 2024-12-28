#include "stdafx.h"
#include "PersonlistController.h"
#include "../../service/gets-person-lists/PersonlistService.h"

PersonlistPageJsonVO::Wrapper PersonlistController::executeQueryPersonList(const PersonlistQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	PersonlistService service;
	// ��ѯ����
	auto result = service.listPersonInfo(query);
	// ��Ӧ���
	auto jvo = PersonlistPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
