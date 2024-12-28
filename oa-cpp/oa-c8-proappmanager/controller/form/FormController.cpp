#include "stdafx.h"
#include "FormController.h"
#include "service/form/FormService.h"
#include "dao/form/FormDAO.h"

// ִ�л�ȡ�����麯��
FormInfoJsonVO::Wrapper FormController::execQueryFormInfo(const String& xid)
{
	// ����һ��service
	FormService service;
	// ��ѯ����
	auto result = service.listFormInfo(xid->data());
	auto jvo = FormInfoJsonVO::createShared();
	jvo->success(result);
	return jvo;

}

// ִ�л�ȡ���б���
FormListPageJsonVO::Wrapper FormController::execQueryFormList(const FormListQuery::Wrapper& userQuery)
{
	// ����һ��service
	FormService service;
	//// ��ѯ����
	auto result = service.listAllForm(userQuery);
	// ��Ӧ���
	auto jvo = FormListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// ִ�л�ȡ�����ͼ���������
FormCategoryJsonVO::Wrapper FormController::execQueryFormCategory(const String& xapplication)
{
	// ����һ��service
	FormService service;
	// ��ѯ����
	auto result = service.listCategory(xapplication->data());
	// ��Ӧ���
	auto jvo = FormCategoryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper FormController::execAddForm(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto jvo = StringJsonVO::createShared();
	// ��ЧֵУ��
	if (dto->application == nullptr || dto->name == nullptr || dto->application->empty() || dto->name->empty()) {
		jvo->init(String(dto->id), RS_PARAMS_INVALID);
		return jvo;
	}
	FormService service;
	string id = service.saveForm(dto, payload);
	if (!id.empty()) {
		jvo->success(String(id));
	} else {
		jvo->fail(String(id));
	}
	return jvo;
}

StringJsonVO::Wrapper FormController::execModifyForm(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto jvo = StringJsonVO::createShared();
	// ��ЧֵУ��
	if (dto->application == nullptr || dto->id == nullptr || dto->application->empty() || dto->id->empty()) {
		jvo->init(String(dto->id), RS_PARAMS_INVALID);
		return jvo;
	}
	FormService service;
	if (service.updateForm(dto, payload)) {
		jvo->success(dto->id);
	} else {
		jvo->fail(dto->id);
	}
	return jvo;

	
}

StringJsonVO::Wrapper FormController::execRemoveForm(const String& id) {
	auto jvo = StringJsonVO::createShared();
	// ��ЧֵУ��
	if (id->empty()) {
		jvo->init(String(id), RS_PARAMS_INVALID);
		return jvo;
	}
	FormService service;
	if (service.deleteForm(id)) {
		jvo->success(id);
	} else {
		jvo->fail(id);
	}
	return jvo;
}


