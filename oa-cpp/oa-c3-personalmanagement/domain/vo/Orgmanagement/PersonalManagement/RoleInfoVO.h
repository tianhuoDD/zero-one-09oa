#pragma once
#ifndef _ROLEINFOVO_H_
#define _ROLEINFOVO_H_
#include "../../../GlobalInclude.h"
#include "domain/dto/OrgManagement/PersonalManagement/RoleInfoDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class RoleInfoPageDTO : public PageDTO<RoleInfoDTO::Wrapper>
{
	DTO_INIT(RoleInfoPageDTO, PageDTO<RoleInfoDTO::Wrapper>);
};
class RoleInfoPageJsonVO : public JsonVO<RoleInfoPageDTO::Wrapper> {
	DTO_INIT(RoleInfoPageJsonVO, JsonVO<RoleInfoPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
