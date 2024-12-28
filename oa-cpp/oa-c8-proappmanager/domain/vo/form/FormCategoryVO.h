#pragma once
#ifndef _FORMCATEGORYVO_H_
#define _FORMCATEGORYVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/form/FormCategoryDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����������ʾJsonVO����������Ӧ���ͻ���
 */
class FormCategoryJsonVO : public  JsonVO<oatpp::List<FormCategoryDTO::Wrapper>>
{
	DTO_INIT(FormCategoryJsonVO, JsonVO<oatpp::List<FormCategoryDTO::Wrapper>>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _FORMCATEGORYVO_H_