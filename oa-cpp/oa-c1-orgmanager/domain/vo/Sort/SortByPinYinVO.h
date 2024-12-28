#pragma once
#ifndef _SortByPinYin_VO_
#define _SortByPinYin_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Sort/SortByPinYinDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class SortByPinYinJsonVO : public JsonVO<SortByPinYinDTO::Wrapper> {
	DTO_INIT(SortByPinYinJsonVO, JsonVO<SortByPinYinDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class SortByPinYinPageJsonVO : public JsonVO<SortByPinYinPageDTO::Wrapper> {//!!!!!!!!!
	DTO_INIT(SortByPinYinPageJsonVO, JsonVO<SortByPinYinPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_