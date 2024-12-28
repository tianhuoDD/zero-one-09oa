#pragma once
#ifndef _FORMLISTDTO_H_
#define _FORMLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个表单列表的数据传输模型
 */
class FormListDTO : public oatpp::DTO
{
	DTO_INIT(FormListDTO, DTO);
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
	// 图标
	API_DTO_FIELD_DEFAULT(String, xicon, ZH_WORDS_GETTER("form.field.xicon"));
};


/**
 * 定义一个表单列表分页传输的对象
 */
class FormListPageDTO :public PageDTO<FormListDTO::Wrapper>
{
	DTO_INIT(FormListPageDTO, PageDTO<FormListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _FORMLISTDTO_H_