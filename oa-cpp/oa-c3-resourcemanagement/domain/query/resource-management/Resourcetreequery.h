#pragma once
#ifndef _SAMPLE_QUERY_
#define _SAMPLE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class ResourcetreeQuery : public PageQuery
{
	DTO_INIT(ResourcetreeQuery, PageQuery);
	// �˵�����
	DTO_FIELD(String, menu_name);
	DTO_FIELD_INFO(menu_name) {
		info->description = ZH_WORDS_GETTER("resource.field.name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_