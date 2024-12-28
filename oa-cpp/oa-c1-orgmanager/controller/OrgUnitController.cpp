#include "stdafx.h"
#include "OrgUnitController.h"
#include "../service/OrgUnitService.h"
#include "ApiDeclarativeServicesHelper.h"

OrgUnitJsonVO::Wrapper OrgUnitController::execQuerySample(const OrgUnitQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	OrgUnitService service;
	// ��ѯ����
	auto result = service.listOne(query);
	// ��Ӧ���
	auto jvo = OrgUnitJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper OrgUnitController::execModifySample(const OrgUnitDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	
	// ����һ��Service
	OrgUnitService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->xid);
	}
	else
	{
		jvo->fail(dto->xid);
	}
	// ��Ӧ���
	return jvo;
}
