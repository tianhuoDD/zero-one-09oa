#pragma once
#ifndef _SEARCHDUTYSERVICE_H_
#define _SEARCHDUTYSERVICE_H_
#include <list>
#include "domain/vo/Orgmanagement/PersonalManagement/SearchDutyVO.h"
#include "domain/dto/OrgManagement/PersonalManagement/SearchDutyDTO.h"


class SearchDutyService
{
public:
	// 查询职务及所属的公司
	oatpp::List<SearchDutyDTO::Wrapper> listAll(const oatpp::String& query);
};

#endif // !_SEARCHDUTYSERVICE_H_
