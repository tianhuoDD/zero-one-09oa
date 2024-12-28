#pragma once
#ifndef _FORMCATEGORYVO_H_
#define _FORMCATEGORYVO_H_

#include "../GlobalInclude.h"
#include "../dto/FormTemplateCategoryDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����������ʾJsonVO����������Ӧ���ͻ���
 */
class FormTemplateCategoryJsonVO : public  JsonVO<oatpp::List<FormTemplateCategoryDTO::Wrapper>>
{
	DTO_INIT(FormTemplateCategoryJsonVO, JsonVO<oatpp::List<FormTemplateCategoryDTO::Wrapper>>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _FORMCATEGORYVO_H_