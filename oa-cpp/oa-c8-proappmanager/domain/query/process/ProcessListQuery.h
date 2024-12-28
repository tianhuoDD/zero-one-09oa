#pragma once
#ifndef _PROCESSLIST_QUERY_
#define _PROCESSLIST_QUERY_


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б��ҳ��ѯ����
 */
class ProcessListQuery : public PageQuery {
	DTO_INIT(ProcessListQuery, PageQuery);
	// ����Ӧ��
	API_DTO_FIELD(String, application, ZH_WORDS_GETTER("process-configuration.process-list.field.application"), true, "79bcf960-3a92-4b54-83e7-b99d2298a82d");
	// ��������
	API_DTO_FIELD(String, category, ZH_WORDS_GETTER("process-configuration.process-list.field.category"), false, "A");
	// ��������
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("process-configuration.process-list.field.name"), false, "A");
	// ���̱���
	API_DTO_FIELD(String, alias, ZH_WORDS_GETTER("process-configuration.process-list.field.alias"), false, "A");

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PROCESSLIST_QUERY_
