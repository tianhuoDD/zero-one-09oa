#pragma once
#ifndef _FORMCATEGORYDTO_H_
#define _FORMCATEGORYDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ�������͵����ݴ���ģ��
 */
class FormCategoryDTO : public oatpp::DTO
{
	DTO_INIT(FormCategoryDTO, DTO);
	// ����
	API_DTO_FIELD_DEFAULT(String, xcategory, ZH_WORDS_GETTER("form.field.xcategory"));
	//����
	API_DTO_FIELD_DEFAULT(Int32, xnum, ZH_WORDS_GETTER("form.category.field.number"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // _FORMCATEGORYDTO_H_