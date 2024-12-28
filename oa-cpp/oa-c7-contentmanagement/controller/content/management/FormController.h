 #pragma once
/*
	栏目表单接口
	author：niuniu
*/
#ifndef _FORMCONTROLLER_H_
#define _FORMCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/content/management/DeleteFormDTO.h"
#include "domain/dto/content/management/ModifyFormDTO.h"
#include "domain/dto/content/management/GetFormDTO.h"
#include "domain/query/content/management/FormQuery.h"
#include "domain/vo/content/management/FormVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class FormController : public oatpp::web::server::api::ApiController {
	 API_ACCESS_DECLARE(FormController);
public:
	//定义删除栏目表单接口描述
	ENDPOINT_INFO(deleteFormById) {
		info->summary = "Delete Form by ID";
		info->pathParams.add<String>("xid").description = "The ID of the form to be deleted";
	}

	//定义删除栏目表单接口处理
	ENDPOINT("DELETE", "/forms/{xid}", deleteFormById, BODY_DTO(Object<DeleteFormDTO>, deleteFormDto)){
		if (execRemoveForm(deleteFormDto->xid)) {
			return createResponse(Status::CODE_204, "Form deleted successfully");
		}else {
			return createResponse(Status::CODE_404, "Form deleted false");
		}
	}

	//定义修改栏目表单接口描述
	ENDPOINT_INFO(modifyForm) {
		info->summary = "Modify a form";
		info->description = "Modify an existing form using the form ID and the details provided.";
		//info->pathParams.add<String>("xid").description = "The ID of the form to modify";
		info->addConsumes<String>("xid").description = "The ID of the form. (Not editable)";
		info->addConsumes<String>("xalias").description = "The alias of the form. (Editable)";
		info->addConsumes<String>("xdescription").description = "The description of the form. (Editable)";
		info->addConsumes<String>("xeditor").description = "The editor of the form. (Editable)";
		info->addConsumes<String>("xname").description = "The name of the form. (Editable)";
		info->addConsumes<String>("xproperties").description = "The properties of the form. (Editable)";
		//info->addResponse<ModifyFormDTO>(Status::CODE_200, "Form modified successfully"); // 成功响应
	}

	// 定义修改表单的端点
	ENDPOINT("PUT", "/forms/{xid}", modifyForm, BODY_DTO(ModifyFormDTO::Wrapper, formDto)){
		//修改逻辑
		return createResponse(Status::CODE_200, "Form modified successfully");
	}

	// 获取栏目表单列表接口
	ENDPOINT_INFO(getForms) {
		info->summary = "Get form lists";
		info->description = "Get form lists belonging to a certain column";
		info->pathParams.add<String>("xappId").description = "The ID of the forms belonging to";
	}
	ENDPOINT("GET", "/forms", getForms, QUERIES(QueryParams, queryParams)) {
		// 解析参数
		API_HANDLER_QUERY_PARAM(formQuery, FormQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execGetForms(formQuery));
	}
private:
	Uint64JsonVO::Wrapper execModifyForm(const ModifyFormDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execRemoveForm(const String& id);
	FormPageJsonVO::Wrapper execGetForms(const FormQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)
#endif //!_FORMCONTROLLER_H_
