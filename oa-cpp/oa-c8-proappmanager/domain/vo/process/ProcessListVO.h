#pragma once
#ifndef _PROCESSLIST_VO_
#define _PROCESSLIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/process/ProcessListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 流程列表显示JsonVO，用于响应给客户端的Json对象
 */
class ProcessListJsonVO : public JsonVO<ProcessListDTO::Wrapper> {
	DTO_INIT(ProcessListJsonVO, JsonVO<ProcessListDTO::Wrapper>);
};

/**
 * 流程列表分页显示JsonVO，用于响应给客户端的Json对象
 */
class ProcessListPageJsonVO : public JsonVO<ProcessListPageDTO::Wrapper> {
	DTO_INIT(ProcessListPageJsonVO, JsonVO<ProcessListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)



#endif // !_PROCESSLIST_VO_
