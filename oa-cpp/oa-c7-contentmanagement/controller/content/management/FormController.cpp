#include "stdafx.h"
#include "FormController.h"
#include "../../ApiDeclarativeServicesHelper.h"
// #include <service/content/management/FormService.h>
#include "../../../service/FormService.h"

Uint64JsonVO::Wrapper FormController::execModifyForm(const ModifyFormDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//����У��

	FormService service;
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

Uint64JsonVO::Wrapper FormController::execRemoveForm(const String& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//��ǰ�˴��ݵĲ�������У��
	//��У��
	if (id.get()->empty()) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//
	FormService service;
	if (service.removeData(id)){
		jvo->success(1);
	}
	else
	{
		jvo->fail(2);
	}
	return jvo;
}

FormPageJsonVO::Wrapper FormController::execGetForms(const FormQuery::Wrapper& query)
{
	FormService s;
	auto result = s.queryForms(query);
	//// ?��???��??
	auto jvo = FormPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}