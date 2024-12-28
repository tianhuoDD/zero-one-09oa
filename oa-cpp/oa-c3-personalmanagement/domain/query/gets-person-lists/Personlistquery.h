#pragma once
#ifndef _PERSONLISTQUERY_H_
#define _PERSONLISTQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class PersonlistQuery : public PageQuery
{
	DTO_INIT(PersonlistQuery, PageQuery);
	// �������
	DTO_FIELD(String, input);
	DTO_FIELD_INFO(input) {
		info->description = ZH_WORDS_GETTER("person.setting.get.field.input");
	}
	// ״̬ɸѡ
	DTO_FIELD(String, xstatus);
	DTO_FIELD_INFO(xstatus) {
		info->description = ZH_WORDS_GETTER("person.setting.get.field.xstatus");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_