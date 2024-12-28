#pragma once

#ifndef _GETMTROOMPOS_VO_
#define _GETMTROOMPOS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/getmtroompos/GetmtroomposDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class GetmtroomposJsonVO : public JsonVO<GetmtroomposDTO::Wrapper> {
	DTO_INIT(GetmtroomposJsonVO, JsonVO<GetmtroomposDTO::Wrapper>);
	//DTO_FIELD(Vector<Object<GetmtroomposDTO>>, rows);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class GetmtroomposPageJsonVO : public JsonVO<GetmtroomposPageDTO::Wrapper> {
	DTO_INIT(GetmtroomposPageJsonVO, JsonVO<GetmtroomposPageDTO::Wrapper>);
	//DTO_FIELD(Vector<Object<GetmtroomposPageDTO>>, rows);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GETMTROOMPOS_VO_