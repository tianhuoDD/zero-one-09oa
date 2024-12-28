#include"stdafx.h"
#include"AcceptUserController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "service/accept/file/AcceptListService.h"



AcceptUserListJsonVO::Wrapper AcceptUserController::execqueryUsersByXunique(const AcceptUserListQuery::Wrapper& query)
{

	// ����һ��Service
	AcceptListService service;
	// ��ѯ����
	auto result = service.user_listAll(query);
	// ��Ӧ���
	auto jvo = AcceptUserListJsonVO::createShared();
	jvo->success(result);
	return jvo;
};