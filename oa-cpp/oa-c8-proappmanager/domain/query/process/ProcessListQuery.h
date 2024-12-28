#pragma once
#ifndef _PROCESSLIST_QUERY_
#define _PROCESSLIST_QUERY_


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 流程列表分页查询对象
 */
class ProcessListQuery : public PageQuery {
	DTO_INIT(ProcessListQuery, PageQuery);
	// 所属应用
	API_DTO_FIELD(String, application, ZH_WORDS_GETTER("process-configuration.process-list.field.application"), true, "79bcf960-3a92-4b54-83e7-b99d2298a82d");
	// 流程类型
	API_DTO_FIELD(String, category, ZH_WORDS_GETTER("process-configuration.process-list.field.category"), false, "A");
	// 流程名称
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("process-configuration.process-list.field.name"), false, "A");
	// 流程别名
	API_DTO_FIELD(String, alias, ZH_WORDS_GETTER("process-configuration.process-list.field.alias"), false, "A");

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PROCESSLIST_QUERY_
