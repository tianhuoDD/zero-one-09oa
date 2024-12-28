#pragma once
#ifndef _SEARCHDUTYVO_H_
#define _SEARCHDUTYVO_H_
#include "../../../GlobalInclude.h"
#include "domain/dto/OrgManagement/PersonalManagement/SearchDutyDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class SearchDutyJsonVO : public JsonVO<oatpp::List<SearchDutyDTO::Wrapper>> {
	DTO_INIT(SearchDutyJsonVO, JsonVO<oatpp::List<SearchDutyDTO::Wrapper>>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
