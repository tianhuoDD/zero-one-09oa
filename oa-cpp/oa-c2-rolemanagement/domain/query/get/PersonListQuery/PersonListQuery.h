#ifndef _QUERY_PERSON_QUERY
#define _QUERY_PERSON_QUERY

#include "../../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҳ��ѯ����
 */
class PersonListQuery : public PageQuery
{
	DTO_INIT(PersonListQuery, PageQuery);
	// Ψһ����
	DTO_FIELD(String, xunique);
	DTO_FIELD_INFO(xunique) {
		info->required = true;
		info->description = "xunique";
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_QUERY_PERSON_QUERY