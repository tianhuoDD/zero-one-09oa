#pragma once
#ifndef _OPERATEFORM_DTO_
#define _OPERATEFORM_DTO_

#include "../../GlobalInclude.h"

#define API_DTO_FIELD_REQUIRE(_TYPE_, _NAME_, _DESCRIPTION_, _REQUIRE_) \
DTO_FIELD(_TYPE_, _NAME_); \
DTO_FIELD_INFO(_NAME_) { \
	info->description = _DESCRIPTION_; \
	info->required = _REQUIRE_; \
}

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个表单列表的数据传输模型
 */
class OperateFormDTO : public oatpp::DTO {
	DTO_INIT(OperateFormDTO, DTO);
	// 名称
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("form.add.field.id"));
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("form.add.field.name"));
	API_DTO_FIELD_DEFAULT(String, description, ZH_WORDS_GETTER("form.add.field.description"));
	API_DTO_FIELD_DEFAULT(String, category, ZH_WORDS_GETTER("form.add.field.category"));
	//API_DTO_FIELD_DEFAULT(Boolean, readOnly, ZH_WORDS_GETTER("form.add.field.readOnly"));
	API_DTO_FIELD_DEFAULT(String, alias, ZH_WORDS_GETTER("form.add.field.alias"));
	API_DTO_FIELD_DEFAULT(String, application, ZH_WORDS_GETTER("form.add.field.application"));
	API_DTO_FIELD_DEFAULT(String, data, ZH_WORDS_GETTER("form.add.field.data"));
	//API_DTO_FIELD_DEFAULT(String, formFieldList, ZH_WORDS_GETTER("form.add.field.formFieldList"));
	API_DTO_FIELD_DEFAULT(Boolean, hasMobile, ZH_WORDS_GETTER("form.add.field.hasMobile"));
	API_DTO_FIELD_DEFAULT(String, icon, ZH_WORDS_GETTER("form.add.field.icon"));
	API_DTO_FIELD_DEFAULT(String, mobileData, ZH_WORDS_GETTER("form.add.field.mobileData"));
	//API_DTO_FIELD_DEFAULT(String, mobileRelatedFormList, ZH_WORDS_GETTER("form.add.field.mobileRelatedFormList"));
	//API_DTO_FIELD_DEFAULT(String, mobileRelatedScriptMap, ZH_WORDS_GETTER("form.add.field.mobileRelatedScriptMap"));
	//API_DTO_FIELD_DEFAULT(String, relatedFormList, ZH_WORDS_GETTER("form.add.field.relatedFormList"));
	//API_DTO_FIELD_DEFAULT(String, relatedScriptMap, ZH_WORDS_GETTER("form.add.field.relatedScriptMap"));
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_OPERATEFORM_DTO_
