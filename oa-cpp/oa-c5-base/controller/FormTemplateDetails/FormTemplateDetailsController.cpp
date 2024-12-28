#include "FormTemplateDetailsController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include "../../service/FormTemplateDetailsService/FormTemplateDetailsService.h"
#include <iostream>


FormTemplateDetailsJsonVO::Wrapper FormTemplateDetailsController::execQueryFormInfo(const String& xid)
{
	// 定义一个service
	FormTemplateDetailsService service;
	// 查询数据
	auto result = service.listFormInfo(xid->data());
	auto jvo = FormTemplateDetailsJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
