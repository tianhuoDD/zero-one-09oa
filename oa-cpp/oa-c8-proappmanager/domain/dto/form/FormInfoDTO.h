#pragma once
#ifndef _FORMINFODTO_H_
#define _FORMINFODTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 表单详情数据传输对象
 */
class FormInfoDTO : public oatpp::DTO
{
	DTO_INIT(FormInfoDTO, DTO);
	// 标识
	API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("form.field.xid"));
	// 名称
	API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("form.field.xname"));
	// 别名
	API_DTO_FIELD_DEFAULT(String, xalias, ZH_WORDS_GETTER("form.field.xalias"));
	// 应用标识
	API_DTO_FIELD_DEFAULT(String, xapplication, ZH_WORDS_GETTER("form.field.xapplication"));
	// 描述
	API_DTO_FIELD_DEFAULT(String, xdescription, ZH_WORDS_GETTER("form.field.xdescription"));
	// 分类
	API_DTO_FIELD_DEFAULT(String, xcategory, ZH_WORDS_GETTER("form.field.xcategory"));
	// 数据
	API_DTO_FIELD_DEFAULT(String, xdata, ZH_WORDS_GETTER("form.field.xdata"));
	// 更新时间 
	API_DTO_FIELD_DEFAULT(String, xupdateTime, ZH_WORDS_GETTER("form.field.xupdateTime"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, xcreateTime, ZH_WORDS_GETTER("form.field.xcreateTime"));
	// 最后一次更新的用户
	API_DTO_FIELD_DEFAULT(String, xlastUpdatePerson, ZH_WORDS_GETTER("form.field.xlastUpdatePerson"));
	// 最后一次更新的时间
	API_DTO_FIELD_DEFAULT(String, xlastUpdateTime, ZH_WORDS_GETTER("form.field.xlastUpdateTime"));
	// 是否兼容移动端
	API_DTO_FIELD_DEFAULT(Boolean, xhasMobile, ZH_WORDS_GETTER("form.field.xhasMobile"));
	// 移动端数据
	API_DTO_FIELD_DEFAULT(String, xmobileData, ZH_WORDS_GETTER("form.field.xmobileData"));
	// 属性
	API_DTO_FIELD_DEFAULT(String, xproperties, ZH_WORDS_GETTER("form.field.xproperties"));
	// 图标
	API_DTO_FIELD_DEFAULT(String, xicon, ZH_WORDS_GETTER("form.field.xicon"));
};




#include OATPP_CODEGEN_END(DTO)
#endif // _FORMINFODTO_H_