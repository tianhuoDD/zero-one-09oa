#include "FormTemplateController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include "../../service/FormTemplateService/FormTemplateService.h"
#include <iostream>

FormTemplatePageJsonVO::Wrapper FormTemplateController::execQuerySample(const FormTemplateQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	FormTemplateService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = FormTemplatePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
