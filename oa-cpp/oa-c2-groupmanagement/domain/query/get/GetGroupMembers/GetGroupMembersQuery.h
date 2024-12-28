#pragma once

#ifndef _GetGroupMembers_QUERY_
#define _GetGroupMembers_QUERY_

#include "../../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҳ��ѯ����
 */
class GetGroupMembersQuery : public PageQuery
{
	DTO_INIT(GetGroupMembersQuery, PageQuery);
	// Ⱥ���Ψһ��ʶ��
	DTO_FIELD(String, groupxid);
	DTO_FIELD_INFO(groupxid) {
		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id");
	}
	// Ⱥ������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.name");
	}
	// Ⱥ��ȫ��
	DTO_FIELD(String, allname);
	DTO_FIELD_INFO(allname) {
		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.allname");
	}

};
/**
 * ʾ����ҳ�������
 */
class GetGroupMembersPageQuery : public PageDTO<GetGroupMembersQuery::Wrapper>
{
	DTO_INIT(GetGroupMembersPageQuery, PageDTO<GetGroupMembersQuery::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_GetGroupMembers_QUERY_