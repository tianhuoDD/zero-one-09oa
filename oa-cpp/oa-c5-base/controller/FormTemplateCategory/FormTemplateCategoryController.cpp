#include "FormTemplateCategoryController.h"
#include "../../service/FormTemplateDetailsService/FormTemplateDetailsService.h"

FormTemplateCategoryJsonVO::Wrapper FormTemplateCategoryController::execQueryFormCategory(const String& xid)
{
	// ����һ��service
	class FormTemplateDetailsService service;
	// ��ѯ����
	auto result = service.listCategory(xid->data());
	// ��Ӧ���
	auto jvo = FormTemplateCategoryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
