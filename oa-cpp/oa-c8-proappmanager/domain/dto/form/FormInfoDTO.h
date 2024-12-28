#pragma once
#ifndef _FORMINFODTO_H_
#define _FORMINFODTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ���������ݴ������
 */
class FormInfoDTO : public oatpp::DTO
{
	DTO_INIT(FormInfoDTO, DTO);
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
	// ����
	API_DTO_FIELD_DEFAULT(String, xdata, ZH_WORDS_GETTER("form.field.xdata"));
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
	// �ƶ�������
	API_DTO_FIELD_DEFAULT(String, xmobileData, ZH_WORDS_GETTER("form.field.xmobileData"));
	// ����
	API_DTO_FIELD_DEFAULT(String, xproperties, ZH_WORDS_GETTER("form.field.xproperties"));
	// ͼ��
	API_DTO_FIELD_DEFAULT(String, xicon, ZH_WORDS_GETTER("form.field.xicon"));
};




#include OATPP_CODEGEN_END(DTO)
#endif // _FORMINFODTO_H_