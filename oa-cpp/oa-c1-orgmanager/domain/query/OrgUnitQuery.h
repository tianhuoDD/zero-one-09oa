#pragma once
#ifndef _ORGUNIT_QUERY_
#define _ORGUNIT_QUERY_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class OrgUnitQuery : public PageQuery
{
	DTO_INIT(OrgUnitQuery, PageQuery);

	//org_unit表下; 组织名称; unit_xname; varchar
	DTO_FIELD(String, unit_xname);
	DTO_FIELD_INFO(unit_xname) {
		info->description = ZH_WORDS_GETTER("org.unit.unit_xname");
	}
	
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_ORGUNIT_QUERY_