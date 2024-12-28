#pragma once
#ifndef _DELROLE_QUERY_
#define _DELROLE_QUERY_

#include"../../GlobalInclude.h"
#include"domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class GetRoleQuery : public PageQuery
{
	DTO_INIT(GetRoleQuery, PageQuery);

	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("addroleDTO.field.name");
	}

	DTO_FIELD(String, key);
	DTO_FIELD_INFO(key) {
		info->description = ZH_WORDS_GETTER("addroleDTO.field.key");
	}

	DTO_FIELD(String, refer);
	DTO_FIELD_INFO(refer) {
		info->description = ZH_WORDS_GETTER("addroleDTO.field.refer");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DELROLE_QUERY_
