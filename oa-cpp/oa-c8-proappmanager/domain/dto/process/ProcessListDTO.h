#pragma once
#ifndef _PROCESSLIST_DTO_
#define _PROCESSLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б������
 */
class ProcessListDTO : public oatpp::DTO {
	DTO_INIT(ProcessListDTO, DTO);
	// Ψһ��ʶ
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("process-configuration.process-list.field.id"), true, "A");
	// ��������
	API_DTO_FIELD(String, category, ZH_WORDS_GETTER("process-configuration.process-list.field.category"), false, "A");
	// ��������
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("process-configuration.process-list.field.name"), false, "A");
	// ���̱���
	API_DTO_FIELD(String, alias, ZH_WORDS_GETTER("process-configuration.process-list.field.alias"), false, "A");
	// ����
	API_DTO_FIELD(String, description, ZH_WORDS_GETTER("process-configuration.process-list.field.description"), false, "A");
	// ����޸�����
	API_DTO_FIELD(String, lastUpdateTime, ZH_WORDS_GETTER("process-configuration.process-list.field.last-update-time"), false, "A");
};

/**
 * �����б��ҳ�������
 */
class ProcessListPageDTO : public PageDTO<ProcessListDTO::Wrapper> {
	DTO_INIT(ProcessListPageDTO, PageDTO<ProcessListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROCESSLIST_DTO_