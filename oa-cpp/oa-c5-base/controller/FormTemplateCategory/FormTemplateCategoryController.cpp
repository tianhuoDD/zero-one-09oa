#include "FormTemplateCategoryController.h"
#include "../../service/FormTemplateDetailsService/FormTemplateDetailsService.h"

FormTemplateCategoryJsonVO::Wrapper FormTemplateCategoryController::execQueryFormCategory(const String& xid)
{
	// 定义一个service
	class FormTemplateDetailsService service;
	// 查询数据
	auto result = service.listCategory(xid->data());
	// 响应结果
	auto jvo = FormTemplateCategoryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
