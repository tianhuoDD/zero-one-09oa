#pragma once
#ifndef PERSONATTRIBUTEVO_H
#define PERSONATTRIBUTEVO_H

#include "../../GlobalInclude.h"
#include "domain/dto/PersonAttribute/PersonAttributeDTO.h"

// Oat++ 代码生成开始
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 个人信息显示Json对象，用于响应给客户端的Json对象
 */
class PersonAttributeJsonVO : public JsonVO<PersonAttributeDTO::Wrapper> {
    DTO_INIT(PersonAttributeJsonVO, JsonVO<PersonAttributeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // PERSONATTRIBUTEVO_H