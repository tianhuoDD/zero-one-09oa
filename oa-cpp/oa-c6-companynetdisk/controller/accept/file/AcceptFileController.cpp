#include"stdafx.h"
#include"AcceptFileController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "service/accept/file/AcceptListService.h"



AcceptFileListJsonVO::Wrapper AcceptFileController::execqueryUsersByXunique(const AcceptFileListQuery::Wrapper& query)
{

	// ����һ��Service
	AcceptListService service;
	// ��ѯ����
	auto result = service.file_listAll(query);
	// ��Ӧ���
	auto jvo = AcceptFileListJsonVO::createShared();
	jvo->success(result);
	return jvo;

};