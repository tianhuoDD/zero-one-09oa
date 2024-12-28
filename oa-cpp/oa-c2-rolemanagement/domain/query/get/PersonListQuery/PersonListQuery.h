#ifndef _QUERY_PERSON_QUERY
#define _QUERY_PERSON_QUERY

#include "../../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询对象
 */
class PersonListQuery : public PageQuery
{
	DTO_INIT(PersonListQuery, PageQuery);
	// 唯一编码
	DTO_FIELD(String, xunique);
	DTO_FIELD_INFO(xunique) {
		info->required = true;
		info->description = "xunique";
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_QUERY_PERSON_QUERY