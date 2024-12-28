#pragma once
#ifndef _GROUPMEMBER_VO_
#define _GROUPMEMBER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/GroupMember/GetGroupMemberDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class MemberGroupJsonVO : public JsonVO<GetGroupMemberDTO::Wrapper> {
	DTO_INIT(MemberGroupJsonVO, JsonVO<GetGroupMemberDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class GetGroupMemberPageJsonVO : public JsonVO<GetGroupMemberPageDTO::Wrapper> {
	DTO_INIT(GetGroupMemberPageJsonVO, JsonVO<GetGroupMemberPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GROUPMEMBER_VO_
