#pragma once
#ifndef _FORMLISTVO_H_
#define _FORMLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/form/FormListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个表单列表分页显示JsonVO对象，用于响应给客户端
 */
class FormListPageJsonVO :public JsonVO<FormListPageDTO::Wrapper>
{
	DTO_INIT(FormListPageJsonVO, JsonVO<FormListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _FORMINFOVO_H_