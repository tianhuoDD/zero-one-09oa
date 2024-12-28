#pragma once
#ifndef _SortByPinYin_QUERY_
#define _SortByPinYin_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class SortByPinYinQuery : public PageQuery
{
	DTO_INIT(SortByPinYinQuery, PageQuery);
	//���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
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
	// ����
	DTO_FIELD(String, miaoshu);
	DTO_FIELD_INFO(miaoshu) {
		info->description = ZH_WORDS_GETTER("sample.field.shuxing");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_