#pragma once
#ifndef _DUTYSETTINGDTO_H_
#define _DUTYSETTINGDTO_H_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class DutySettingDTO: public oatpp::DTO
{
	DTO_INIT(DutySettingDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, xidentity, ZH_WORDS_GETTER("domain.dto.OrgManagement.PersonalManagement.DutySetting.Xidentity"));
	API_DTO_FIELD_DEFAULT(List<String>, unitduty_xid, ZH_WORDS_GETTER("domain.dto.OrgManagement.PersonalManagement.DutySetting.unitduty_xid"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_