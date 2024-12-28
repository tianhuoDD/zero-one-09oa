#pragma once

#ifndef _SortByValue_Controller_
#define _SortByValue_Controller_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/Sort/SortByValue.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class SortByValueController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(SortByValueController);
	// 3 定义接口
public:
	// 定义修改组织职务接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("sort.sort_value"), sortValue, Uint64JsonVO::Wrapper);
	// 定义修改组织职务接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c1-org/sortValue", sortValue, BODY_DTO(SortByValueDTO::Wrapper, dto), execSortByValue(dto));
private:
	Uint64JsonVO::Wrapper execSortByValue(const SortByValueDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_