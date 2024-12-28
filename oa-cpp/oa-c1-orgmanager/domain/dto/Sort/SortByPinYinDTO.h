#pragma once
#ifndef _SortByPinYin_DTO_
#define _SortByPinYin_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class SortByPinYinDTO : public oatpp::DTO
{
	DTO_INIT(SortByPinYinDTO, DTO);
	//���
	DTO_FIELD(UInt64, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// ����
	DTO_FIELD(String, shuxing);
	DTO_FIELD_INFO(shuxing) {
		info->description = ZH_WORDS_GETTER("sample.field.shuxing");
	}
	// ֵ
	DTO_FIELD(Int32, value);
	DTO_FIELD_INFO(value) {
		info->description = ZH_WORDS_GETTER("sample.field.value");
	}
	//����
	DTO_FIELD(String, miaoshu);
	DTO_FIELD_INFO(miaoshu) {
		info->description = ZH_WORDS_GETTER("sample.field.value");
	}
	// ƴ��
	DTO_FIELD(String, xpinyin);
	DTO_FIELD_INFO(xpinyin) {
		info->description = ZH_WORDS_GETTER("ƴ��");
	}
	//org_unit����; ����ֵ; xorderNumber; int
	DTO_FIELD(UInt64, xorderNumber);
	DTO_FIELD_INFO(xorderNumber) {
		info->description = ZH_WORDS_GETTER("org.unit.xorderNumber");
	}
	//org_unit����; Ψһ����; xunique; varchar
	DTO_FIELD(String, xunique);
	DTO_FIELD_INFO(xunique) {
		info->description = ZH_WORDS_GETTER("org.unit.xunique");
	}
	
};

/**
 * ʾ����ҳ�������
 */
class SortByPinYinPageDTO : public PageDTO<SortByPinYinDTO::Wrapper>
{
	DTO_INIT(SortByPinYinPageDTO, PageDTO<SortByPinYinDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_