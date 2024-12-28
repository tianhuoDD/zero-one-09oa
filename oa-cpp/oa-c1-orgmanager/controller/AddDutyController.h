#pragma once

#ifndef _ADDDUTY_CONTROLLER_
#define _ADDDUTY_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/OrgDutyDTO.h"



// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class AddDutyController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(AddDutyController);
	// 3 定义接口
public:
	// 定义添加职务组织接口描述；
	ENDPOINT_INFO(addOrganizationDuty) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("duty.add.summary"));

		API_DEF_ADD_AUTH();
		//定义响应的参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义添加职务组织接口处理
	ENDPOINT(API_M_POST, "/c1-org/addorganizationduty", addOrganizationDuty, BODY_DTO(OrgDutyDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddDuty(dto));
	}
private:
	StringJsonVO::Wrapper execAddDuty(const OrgDutyDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_