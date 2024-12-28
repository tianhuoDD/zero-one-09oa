#pragma once
#ifndef _PERSONLIST_VO_
#define _PERSONLIST_VO_
//#include "../../../GlobalInclude.h"
#include "domain/query/personal-management/gets-person-lists/Personlistquery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class PersonlistJsonVO : public JsonVO<PersonlistQuery::Wrapper> {
	DTO_INIT(PersonlistJsonVO, JsonVO<PersonlistQuery::Wrapper>);
	// 姓名
	API_DTO_FIELD_DEFAULT(List<String>, name, ZH_WORDS_GETTER("person.setting.field.name"));
	// 电话
	API_DTO_FIELD_DEFAULT(List<String>, phone, ZH_WORDS_GETTER("person.setting.field.phone"));
	// 头像地址
	API_DTO_FIELD_DEFAULT(List<String>, head, ZH_WORDS_GETTER("person.setting.field.head"));
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class PersonlistPageJsonVO : public JsonVO<PersonlistQuery::Wrapper> {
	DTO_INIT(PersonlistPageJsonVO, JsonVO<PersonlistQuery::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_