#pragma once
#ifndef _PERSONLISTVO_H_
#define _PERSONLISTVO_H_
#include "../../GlobalInclude.h"
#include "domain/query/gets-person-lists/Personlistquery.h"
#include "domain/dto/gets-person-lists/PersonlistDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class PersonlistPageJsonVO : public JsonVO<PersonlistPageDTO::Wrapper> {
	DTO_INIT(PersonlistPageJsonVO, JsonVO<PersonlistPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_