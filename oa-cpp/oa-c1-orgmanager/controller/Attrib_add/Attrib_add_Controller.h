#pragma once
#ifndef _ATTRIB_CONTROLLER_
#define _ATTRIB_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/Attrib_add/Attrib_add_DTO.h"
#include "domain/vo/Attrib_add/Attrib_add_VO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class Attrib_add_Controller : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(Attrib_add_Controller);
	// 3 定义接口
public:
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addAttrib) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Attrib_add.title.add"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理  API_HANDLER_AUTH_PARAME
	ENDPOINT(API_M_POST, "/c1-org/Attrib_add", addAttrib, BODY_DTO(Attrib_add_DTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddAttrib(dto));
	}
private:
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddAttrib(const Attrib_add_DTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_