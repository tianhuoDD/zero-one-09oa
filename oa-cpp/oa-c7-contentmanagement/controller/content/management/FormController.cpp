#include "stdafx.h"
#include "FormController.h"
#include "../../ApiDeclarativeServicesHelper.h"
// #include <service/content/management/FormService.h>
#include "../../../service/FormService.h"

Uint64JsonVO::Wrapper FormController::execModifyForm(const ModifyFormDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//参数校验

	FormService service;
	if (service.updateData(dto)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(2);
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper FormController::execRemoveForm(const String& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//对前端传递的参数进行校验
	//空校验
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
	//// ?ì???á??
	auto jvo = FormPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}