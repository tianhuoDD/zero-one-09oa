#include "stdafx.h"
#include "NewController.h"

#include "../../service/New/NewService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/Put/PutService.h"
PutJsonVO::Wrapper NewController::executeModifyNew(const PutDTO::Wrapper& dto)
{
	auto jvo = PutJsonVO::createShared();
	//����У��
	//��ΧУ��

	//����һ��Service
	PutService service;
	//ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto);
	}
	else {
		jvo->fail(dto);
	}
	// ��Ӧ���
	return jvo;
}
NewJsonVO::Wrapper NewController::executeQueryNew(const String& id)
{// ����һ��Service
	
	NewService service;
	// ��ѯ����
	auto result = service.listAll(id);
	// ��Ӧ���
	auto jvo = NewJsonVO::createShared();
	jvo->success(result);
	return jvo;
}