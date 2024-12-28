#pragma once
#ifndef _PERSONLISTQUERY_H_
#define _PERSONLISTQUERY_H_
#include "../../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class PersonlistQuery : public PageQuery
{
	DTO_INIT(PersonlistQuery, PageQuery);
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("person.setting.field.name");
	}
	// �绰
	DTO_FIELD(String, phone);
	DTO_FIELD_INFO(phone) {
		info->description = ZH_WORDS_GETTER("person.setting.field.phone");
	}
	// ����
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("person.setting.field.id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_