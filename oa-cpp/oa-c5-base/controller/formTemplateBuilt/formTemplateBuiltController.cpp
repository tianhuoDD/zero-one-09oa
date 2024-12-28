#include "stdafx.h"
#include "formTemplateBuiltController.h"
#include"../../service/formTemplate/built/formTemplateBuiltService.h"



Uint64JsonVO::Wrapper formTemplateBuiltController::executeAddformTemplateBuilt(const formTemplateBuiltDTO::Wrapper& dto)
{
	
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->xsequence || !dto->xdescription || !dto->xalias || !dto->xcategory || !dto->xdata || !dto->xdescription || !dto->xicon || !dto->xmobileData || !dto->xname || !dto->xoutline)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->xsequence->empty() || dto->xdescription->empty() || dto->xalias->empty() || dto->xcategory->empty() || dto->xdata->empty() || dto->xdescription->empty() || dto->xicon->empty() || dto->xmobileData->empty() || dto->xname->empty() || dto->xoutline->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	formTemplateBuiltService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper formTemplateBuiltController::executeremoveformTemplateBuilt(const UInt64& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	formTemplateBuiltService service;
	// ִ������ɾ��
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}
