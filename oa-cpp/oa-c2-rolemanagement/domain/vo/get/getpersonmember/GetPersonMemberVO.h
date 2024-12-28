#pragma once
#ifndef _GETPERSONMEMBER_VO_
#define _GETPERSONMEMBER_VO_

#include "domain/GlobalInclude.h"
#include "domain/dto/rolemanagement/RoleManagementDTO/get/getpersonmember/GetPersonMemberDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class GetPersonMemberJsonVO : public JsonVO<GetPersonMemberDTO::Wrapper> {
	DTO_INIT(GetPersonMemberJsonVO, JsonVO<GetPersonMemberDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class GetPersonMemberPageJsonVO : public JsonVO<GetPersonMemberPageDTO::Wrapper> {

	DTO_INIT(GetPersonMemberPageJsonVO, JsonVO<GetPersonMemberPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GETPERSONMEMBER_VO_