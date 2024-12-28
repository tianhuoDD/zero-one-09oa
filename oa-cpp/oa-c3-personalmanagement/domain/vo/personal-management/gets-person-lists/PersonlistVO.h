#pragma once
#ifndef _PERSONLIST_VO_
#define _PERSONLIST_VO_
//#include "../../../GlobalInclude.h"
#include "domain/query/personal-management/gets-person-lists/Personlistquery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PersonlistJsonVO : public JsonVO<PersonlistQuery::Wrapper> {
	DTO_INIT(PersonlistJsonVO, JsonVO<PersonlistQuery::Wrapper>);
	// ����
	API_DTO_FIELD_DEFAULT(List<String>, name, ZH_WORDS_GETTER("person.setting.field.name"));
	// �绰
	API_DTO_FIELD_DEFAULT(List<String>, phone, ZH_WORDS_GETTER("person.setting.field.phone"));
	// ͷ���ַ
	API_DTO_FIELD_DEFAULT(List<String>, head, ZH_WORDS_GETTER("person.setting.field.head"));
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PersonlistPageJsonVO : public JsonVO<PersonlistQuery::Wrapper> {
	DTO_INIT(PersonlistPageJsonVO, JsonVO<PersonlistQuery::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_