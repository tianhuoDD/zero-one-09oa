#pragma once
#ifndef _SortByValue_QUERY_
#define _SortByValue_QUERY_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SortByValueQuery : public PageQuery
{
	DTO_INIT(SortByValueQuery, PageQuery);

	//org_unit表下; 组织名称; unit_xname; varchar
	DTO_FIELD(String, xordervalue);
	DTO_FIELD_INFO(xordervalue) {
		info->description = ZH_WORDS_GETTER("sort.xname");
	}

};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SortByValue_QUERY_