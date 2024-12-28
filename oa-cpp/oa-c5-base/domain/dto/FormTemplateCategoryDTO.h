#pragma once
#ifndef _FORMTEMPLATECATEGORYDTO_H_
#define _FORMTEMPLATECATEGORYDTO_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ�������͵����ݴ���ģ��
 */
class FormTemplateCategoryDTO : public oatpp::DTO
{
	DTO_INIT(FormTemplateCategoryDTO, DTO);
	// ����
	API_DTO_FIELD_DEFAULT(String, xcategory, ZH_WORDS_GETTER("formTemplate.field.xcategory"));
	//����
	API_DTO_FIELD_DEFAULT(Int32, xnum, ZH_WORDS_GETTER("formTemplate.category.field.number"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // _FORMTEMPLATECATEGORYDTO_H_