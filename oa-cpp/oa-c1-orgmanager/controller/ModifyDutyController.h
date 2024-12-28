#pragma once

#ifndef _MODIFYDUTY_CONTROLLER_
#define _MODIFYDUTY_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/OrgDutyDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class ModifyDutyController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ModifyDutyController);
	// 3 定义接口
public:
	// 定义修改组织职务接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("duty.modify.summary"), modifyDuty, Uint64JsonVO::Wrapper);
	// 定义修改组织职务接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c1-org/modifyorganizationduty", modifyDuty, BODY_DTO(OrgDutyDTO::Wrapper, dto), execModifyDuty(dto));
private:
	StringJsonVO::Wrapper execModifyDuty(const OrgDutyDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_