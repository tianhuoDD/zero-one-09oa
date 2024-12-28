#include "stdafx.h"
#include "PersonController.h"
#include "../../service/PersonService.h"

PersonInfoPageJsonVO::Wrapper PersonController::execcuteQueryPerson(const PersonQuery::Wrapper& perQuery)
{
	// ����һ��Service
	PersonService service;
	//// ��ѯ����
	auto result = service.queryPer(perQuery);
	//// ��Ӧ���

	auto jvo = PersonInfoPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

	//return {};
}
