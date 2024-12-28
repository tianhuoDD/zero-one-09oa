#pragma once
#ifndef _ROLEINFODTO_H_
#define _ROLEINFODTO_H_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class RoleInfoDTO : public oatpp::DTO
{
	DTO_INIT(RoleInfoDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("domain.vo.OrgManagement.PersonalManagement.RoleInfo.Role"));
	API_DTO_FIELD_DEFAULT(String, xdistinguishedName, ZH_WORDS_GETTER("domain.vo.OrgManagement.PersonalManagement.RoleInfo.xdistinguishedName"));
	API_DTO_FIELD_DEFAULT(String, xdescription, ZH_WORDS_GETTER("domain.vo.OrgManagement.PersonalManagement.RoleInfo.xdescription"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_ROLEINFODTO_H_