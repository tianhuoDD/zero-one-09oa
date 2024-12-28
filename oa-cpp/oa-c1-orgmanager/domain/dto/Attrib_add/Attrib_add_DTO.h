#pragma once
#ifndef _ATTRIB_DTO_
#define _ATTRIB_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

#include<vector>
/**
 * 示例传输对象
 */
class Attrib_add_DTO : public oatpp::DTO
{
	DTO_INIT(Attrib_add_DTO, DTO);
	//编号
	DTO_FIELD(String, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// 姓名
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("sample.field.name");//中文字典里是介绍输入框里面应该要输入的内容做介绍
	}
	// 属性
	DTO_FIELD(String, xdistinguishedName);
	DTO_FIELD_INFO(xdistinguishedName) {
		info->description = ZH_WORDS_GETTER("sample.field.shuxing");
	}
	// 值
	DTO_FIELD(Int32, xdistributeFactor);
	DTO_FIELD_INFO(xdistributeFactor) {
		info->description = ZH_WORDS_GETTER("sample.field.value");
	}
	//描述
	DTO_FIELD(String, xdescription);
	DTO_FIELD_INFO(xdescription) {
		info->description = ZH_WORDS_GETTER("sample.field.shuxing");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_