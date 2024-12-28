#pragma once
#ifndef _GROUPMEMBER_DTO_
#define _GROUPMEMBER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class GetGroupMemberDTO : public oatpp::DTO
{
	DTO_INIT(GetGroupMemberDTO, DTO);
	// 群组名称
	DTO_FIELD(String, groupname);
	DTO_FIELD_INFO(groupname) {
		info->description = ZH_WORDS_GETTER("queryGroupMember.field.groupname");
	}
	// 群组全称
	DTO_FIELD(String, groupnameA);
	DTO_FIELD_INFO(groupnameA) {
		info->description = ZH_WORDS_GETTER("queryGroupMember.field.groupnameA");
	}
	// 群组描述
	DTO_FIELD(String, groupdes);
	DTO_FIELD_INFO(groupdes) {
		info->description = ZH_WORDS_GETTER("queryGroupMember.field.groupdes");
	}
};

/**
 * 示例分页传输对象
 */
class GetGroupMemberPageDTO : public PageDTO<GetGroupMemberDTO::Wrapper>
{
	DTO_INIT(GetGroupMemberPageDTO, PageDTO<GetGroupMemberDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUPMEMBER_DTO_