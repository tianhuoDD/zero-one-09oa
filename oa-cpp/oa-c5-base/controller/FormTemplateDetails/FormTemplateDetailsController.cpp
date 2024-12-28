#include "FormTemplateDetailsController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include "../../service/FormTemplateDetailsService/FormTemplateDetailsService.h"
#include <iostream>


FormTemplateDetailsJsonVO::Wrapper FormTemplateDetailsController::execQueryFormInfo(const String& xid)
{
	// ����һ��service
	FormTemplateDetailsService service;
	// ��ѯ����
	auto result = service.listFormInfo(xid->data());
	auto jvo = FormTemplateDetailsJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
