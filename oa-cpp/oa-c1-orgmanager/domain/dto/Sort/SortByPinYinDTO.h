#pragma once
#ifndef _SortByPinYin_DTO_
#define _SortByPinYin_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class SortByPinYinDTO : public oatpp::DTO
{
	DTO_INIT(SortByPinYinDTO, DTO);
	//编号
	DTO_FIELD(UInt64, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// 属性
	DTO_FIELD(String, shuxing);
	DTO_FIELD_INFO(shuxing) {
		info->description = ZH_WORDS_GETTER("sample.field.shuxing");
	}
	// 值
	DTO_FIELD(Int32, value);
	DTO_FIELD_INFO(value) {
		info->description = ZH_WORDS_GETTER("sample.field.value");
	}
	//描述
	DTO_FIELD(String, miaoshu);
	DTO_FIELD_INFO(miaoshu) {
		info->description = ZH_WORDS_GETTER("sample.field.value");
	}
	// 拼音
	DTO_FIELD(String, xpinyin);
	DTO_FIELD_INFO(xpinyin) {
		info->description = ZH_WORDS_GETTER("拼音");
	}
	//org_unit表下; 排序值; xorderNumber; int
	DTO_FIELD(UInt64, xorderNumber);
	DTO_FIELD_INFO(xorderNumber) {
		info->description = ZH_WORDS_GETTER("org.unit.xorderNumber");
	}
	//org_unit表下; 唯一编码; xunique; varchar
	DTO_FIELD(String, xunique);
	DTO_FIELD_INFO(xunique) {
		info->description = ZH_WORDS_GETTER("org.unit.xunique");
	}
	
};

/**
 * 示例分页传输对象
 */
class SortByPinYinPageDTO : public PageDTO<SortByPinYinDTO::Wrapper>
{
	DTO_INIT(SortByPinYinPageDTO, PageDTO<SortByPinYinDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_