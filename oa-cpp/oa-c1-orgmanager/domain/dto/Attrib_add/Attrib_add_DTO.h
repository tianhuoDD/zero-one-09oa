#pragma once
#ifndef _ATTRIB_DTO_
#define _ATTRIB_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

#include<vector>
/**
 * ʾ���������
 */
class Attrib_add_DTO : public oatpp::DTO
{
	DTO_INIT(Attrib_add_DTO, DTO);
	//���
	DTO_FIELD(String, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// ����
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("sample.field.name");//�����ֵ����ǽ������������Ӧ��Ҫ���������������
	}
	// ����
	DTO_FIELD(String, xdistinguishedName);
	DTO_FIELD_INFO(xdistinguishedName) {
		info->description = ZH_WORDS_GETTER("sample.field.shuxing");
	}
	// ֵ
	DTO_FIELD(Int32, xdistributeFactor);
	DTO_FIELD_INFO(xdistributeFactor) {
		info->description = ZH_WORDS_GETTER("sample.field.value");
	}
	//����
	DTO_FIELD(String, xdescription);
	DTO_FIELD_INFO(xdescription) {
		info->description = ZH_WORDS_GETTER("sample.field.shuxing");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_