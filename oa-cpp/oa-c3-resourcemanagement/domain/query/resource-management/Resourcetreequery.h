#pragma once
#ifndef _SAMPLE_QUERY_
#define _SAMPLE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class ResourcetreeQuery : public PageQuery
{
	DTO_INIT(ResourcetreeQuery, PageQuery);
	// 菜单名称
	DTO_FIELD(String, menu_name);
	DTO_FIELD_INFO(menu_name) {
		info->description = ZH_WORDS_GETTER("resource.field.name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_