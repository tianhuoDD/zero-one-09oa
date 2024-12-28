#pragma once
#ifndef _GETPERSONMEMBER_VO_
#define _GETPERSONMEMBER_VO_

#include "domain/GlobalInclude.h"
#include "domain/dto/rolemanagement/RoleManagementDTO/get/getpersonmember/GetPersonMemberDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GetPersonMemberJsonVO : public JsonVO<GetPersonMemberDTO::Wrapper> {
	DTO_INIT(GetPersonMemberJsonVO, JsonVO<GetPersonMemberDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GetPersonMemberPageJsonVO : public JsonVO<GetPersonMemberPageDTO::Wrapper> {

	DTO_INIT(GetPersonMemberPageJsonVO, JsonVO<GetPersonMemberPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GETPERSONMEMBER_VO_