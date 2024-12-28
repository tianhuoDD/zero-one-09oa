#include "stdafx.h"
#include "FormController.h"
#include "service/form/FormService.h"
#include "dao/form/FormDAO.h"

// 执行获取表单详情函数
FormInfoJsonVO::Wrapper FormController::execQueryFormInfo(const String& xid)
{
	// 定义一个service
	FormService service;
	// 查询数据
	auto result = service.listFormInfo(xid->data());
	auto jvo = FormInfoJsonVO::createShared();
	jvo->success(result);
	return jvo;

}

// 执行获取表单列表函数
FormListPageJsonVO::Wrapper FormController::execQueryFormList(const FormListQuery::Wrapper& userQuery)
{
	// 定义一个service
	FormService service;
	//// 查询数据
	auto result = service.listAllForm(userQuery);
	// 响应结果
	auto jvo = FormListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// 执行获取表单类型及数量函数
FormCategoryJsonVO::Wrapper FormController::execQueryFormCategory(const String& xapplication)
{
	// 定义一个service
	FormService service;
	// 查询数据
	auto result = service.listCategory(xapplication->data());
	// 响应结果
	auto jvo = FormCategoryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper FormController::execAddForm(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto jvo = StringJsonVO::createShared();
	// 有效值校验
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
	// 有效值校验
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
	// 有效值校验
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


