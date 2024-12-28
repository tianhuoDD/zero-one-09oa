#pragma once
#ifndef _PROCESSLIST_DTO_
#define _PROCESSLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 流程列表传输对象
 */
class ProcessListDTO : public oatpp::DTO {
	DTO_INIT(ProcessListDTO, DTO);
	// 唯一标识
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("process-configuration.process-list.field.id"), true, "A");
	// 流程类型
	API_DTO_FIELD(String, category, ZH_WORDS_GETTER("process-configuration.process-list.field.category"), false, "A");
	// 流程名称
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("process-configuration.process-list.field.name"), false, "A");
	// 流程别名
	API_DTO_FIELD(String, alias, ZH_WORDS_GETTER("process-configuration.process-list.field.alias"), false, "A");
	// 描述
	API_DTO_FIELD(String, description, ZH_WORDS_GETTER("process-configuration.process-list.field.description"), false, "A");
	// 最后修改日期
	API_DTO_FIELD(String, lastUpdateTime, ZH_WORDS_GETTER("process-configuration.process-list.field.last-update-time"), false, "A");
};

/**
 * 流程列表分页传输对象
 */
class ProcessListPageDTO : public PageDTO<ProcessListDTO::Wrapper> {
	DTO_INIT(ProcessListPageDTO, PageDTO<ProcessListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROCESSLIST_DTO_