#pragma once

#ifndef _ROLELIST_QUERY_H_
#define _ROLELIST_QUERY_H_

#include "../../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  ��ɫ�б��ѯ����
*/
class QueryRoleQuery : public PageQuery {
	DTO_INIT(QueryRoleQuery, PageQuery);
	// �ؼ���
	DTO_FIELD(String, key);
	DTO_FIELD_INFO(key) {
		info->description = ZH_WORDS_GETTER("rolelist.field.words");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GETROLELIST_QUERY_H_
