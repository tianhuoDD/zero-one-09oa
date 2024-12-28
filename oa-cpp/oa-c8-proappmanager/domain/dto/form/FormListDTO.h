#pragma once
#ifndef _FORMLISTDTO_H_
#define _FORMLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ�����б�����ݴ���ģ��
 */
class FormListDTO : public oatpp::DTO
{
	DTO_INIT(FormListDTO, DTO);
	// ��ʶ
	API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("form.field.xid"));
	// ����
	API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("form.field.xname"));
	// ����
	API_DTO_FIELD_DEFAULT(String, xalias, ZH_WORDS_GETTER("form.field.xalias"));
	// Ӧ�ñ�ʶ
	API_DTO_FIELD_DEFAULT(String, xapplication, ZH_WORDS_GETTER("form.field.xapplication"));
	// ����
	API_DTO_FIELD_DEFAULT(String, xdescription, ZH_WORDS_GETTER("form.field.xdescription"));
	// ����
	API_DTO_FIELD_DEFAULT(String, xcategory, ZH_WORDS_GETTER("form.field.xcategory"));
	// ����ʱ�� 
	API_DTO_FIELD_DEFAULT(String, xupdateTime, ZH_WORDS_GETTER("form.field.xupdateTime"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, xcreateTime, ZH_WORDS_GETTER("form.field.xcreateTime"));
	// ���һ�θ��µ��û�
	API_DTO_FIELD_DEFAULT(String, xlastUpdatePerson, ZH_WORDS_GETTER("form.field.xlastUpdatePerson"));
	// ���һ�θ��µ�ʱ��
	API_DTO_FIELD_DEFAULT(String, xlastUpdateTime, ZH_WORDS_GETTER("form.field.xlastUpdateTime"));
	// �Ƿ�����ƶ���
	API_DTO_FIELD_DEFAULT(Boolean, xhasMobile, ZH_WORDS_GETTER("form.field.xhasMobile"));
	// ͼ��
	API_DTO_FIELD_DEFAULT(String, xicon, ZH_WORDS_GETTER("form.field.xicon"));
};


/**
 * ����һ�����б��ҳ����Ķ���
 */
class FormListPageDTO :public PageDTO<FormListDTO::Wrapper>
{
	DTO_INIT(FormListPageDTO, PageDTO<FormListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _FORMLISTDTO_H_