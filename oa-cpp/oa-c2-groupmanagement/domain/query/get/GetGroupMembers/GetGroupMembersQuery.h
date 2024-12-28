#pragma once

#ifndef _GetGroupMembers_QUERY_
#define _GetGroupMembers_QUERY_

#include "../../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询对象
 */
class GetGroupMembersQuery : public PageQuery
{
	DTO_INIT(GetGroupMembersQuery, PageQuery);
	// 群组的唯一标识符
	DTO_FIELD(String, groupxid);
	DTO_FIELD_INFO(groupxid) {
		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id");
	}
	// 群组名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.name");
	}
	// 群组全称
	DTO_FIELD(String, allname);
	DTO_FIELD_INFO(allname) {
		info->description = ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.allname");
	}

};
/**
 * 示例分页传输对象
 */
class GetGroupMembersPageQuery : public PageDTO<GetGroupMembersQuery::Wrapper>
{
	DTO_INIT(GetGroupMembersPageQuery, PageDTO<GetGroupMembersQuery::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_GetGroupMembers_QUERY_