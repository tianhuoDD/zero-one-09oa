#pragma once
#ifndef _FORMCATEGORYVO_H_
#define _FORMCATEGORYVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/form/FormCategoryDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个表单详情显示JsonVO对象，用于响应给客户端
 */
class FormCategoryJsonVO : public  JsonVO<oatpp::List<FormCategoryDTO::Wrapper>>
{
	DTO_INIT(FormCategoryJsonVO, JsonVO<oatpp::List<FormCategoryDTO::Wrapper>>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _FORMCATEGORYVO_H_