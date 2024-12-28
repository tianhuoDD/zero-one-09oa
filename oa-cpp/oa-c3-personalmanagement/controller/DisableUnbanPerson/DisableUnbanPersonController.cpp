#include "DisableUnbanPersonController.h"
#include "stdafx.h"
#include "../../service/DisableUnbanPerson/DisableUnbanPersonService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper DisableUnbanPersonController::execModifySample(const DisableUnbanPersonDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	/*if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/
	// ����һ��Service
	DisableUnbanPersonService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(2);
	}
	// ��Ӧ���
	return jvo;
}
