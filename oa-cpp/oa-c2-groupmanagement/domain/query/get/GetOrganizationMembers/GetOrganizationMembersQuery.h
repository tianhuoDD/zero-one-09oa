#pragma once

#ifndef _GetOrganizationMembers_QUERY_
#define _GetOrganizationMembers_QUERY_

#include "../../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询对象
 */
class GetOrganizationMembersQuery : public PageQuery
{
	DTO_INIT(GetOrganizationMembersQuery, PageQuery);
	//  群组唯一标识
	DTO_FIELD(String, groupxid);
	DTO_FIELD_INFO(groupxid) {
		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id");
	}
	// 组织名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.name");
	}
	// 层级名称
	DTO_FIELD(String, xunitList);
	DTO_FIELD_INFO(xunitList) {
		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.xunitList");
	}

};
class GetOrganizationMembersPageQuery : public PageDTO<GetOrganizationMembersQuery::Wrapper>
{
	DTO_INIT(GetOrganizationMembersPageQuery, PageDTO<GetOrganizationMembersQuery::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_GetOrganizationMembers_QUERY_