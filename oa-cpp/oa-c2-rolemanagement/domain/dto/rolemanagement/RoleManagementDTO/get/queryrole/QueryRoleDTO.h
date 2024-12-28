#pragma once

#ifndef _ROLELIST_DTO_
#define _ROLELIST_DTO_
#include "../../../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  角色名称列表传输对象
*/
class QueryRoleDTO : public oatpp::DTO {
	DTO_INIT(QueryRoleDTO, DTO);
	// 角色id
	DTO_FIELD(String, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("rolelist.field.Id");
	}
	// 角色名称
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("rolelist.field.name");
	}

	DTO_FIELD(String, xunique);
	DTO_FIELD_INFO(xunique) {
		info->description = "xunique";
	}



};

/**
*  角色名称列表传输对象
*/
class QueryRolePageDTO : public PageDTO<QueryRoleDTO::Wrapper> {
	DTO_INIT(QueryRolePageDTO, PageDTO<QueryRoleDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ROLELIST_DTO_