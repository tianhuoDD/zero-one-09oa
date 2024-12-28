#pragma once
#ifndef _GROUPMEMBER_VO_
#define _GROUPMEMBER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/GroupMember/GetGroupMemberDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MemberGroupJsonVO : public JsonVO<GetGroupMemberDTO::Wrapper> {
	DTO_INIT(MemberGroupJsonVO, JsonVO<GetGroupMemberDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GetGroupMemberPageJsonVO : public JsonVO<GetGroupMemberPageDTO::Wrapper> {
	DTO_INIT(GetGroupMemberPageJsonVO, JsonVO<GetGroupMemberPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GROUPMEMBER_VO_
