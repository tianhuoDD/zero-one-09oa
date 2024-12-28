#pragma once
#ifndef _DUTYSETTINGSERVICE_H_
#define _DUTYSETTINGSERVICE_H_
#include "domain/dto/OrgManagement/PersonalManagement/DutySettingDTO.h"
#include "domain/do/OrgManagement/PersonalManagement/org_unitduty_identitylistDO.h"


class DutySettingService
{
public:
	// …Ë÷√÷∞ŒÒ
	int DutySetting(const DutySettingDTO::Wrapper& dto);
};

#endif // !_ROLEINFOSERVICE_H_
