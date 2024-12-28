#pragma once
#ifndef _SEARCHDUTYDTO_H_
#define _SEARCHDUTYDTO_H_
#include "../../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)
//查询职务领域模型
class SearchDutyDTO : public oatpp::DTO
{
	DTO_INIT(SearchDutyDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("domain.vo.OrgManagement.PersonalManagement.SearchDuty.Res"));
	API_DTO_FIELD_DEFAULT(String, xlevelName, ZH_WORDS_GETTER("domain.vo.OrgManagement.PersonalManagement.SearchDuty.xlevelName"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_SEARCHDUTYDTO_H_