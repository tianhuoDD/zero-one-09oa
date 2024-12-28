#pragma once

#ifndef _GetOrganizationMembers_QUERY_
#define _GetOrganizationMembers_QUERY_

#include "../../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҳ��ѯ����
 */
class GetOrganizationMembersQuery : public PageQuery
{
	DTO_INIT(GetOrganizationMembersQuery, PageQuery);
	//  Ⱥ��Ψһ��ʶ
	DTO_FIELD(String, groupxid);
	DTO_FIELD_INFO(groupxid) {
		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id");
	}
	// ��֯����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.name");
	}
	// �㼶����
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