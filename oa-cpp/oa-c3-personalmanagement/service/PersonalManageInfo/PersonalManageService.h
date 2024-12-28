#pragma once
#ifndef PERSONALMANAGESERVICE
#define PERSONALMANAGESERVICE

#include "domain/dto/PersonalManageInfo/PersonalManageInfoDTO.h"
#include "domain/vo/PersonalManageInfo/PersonalManageInfoVO.h"
#include "domain/GlobalInclude.h"

class PersonalManageService {
public:
	PersonalManageInfoDTO::Wrapper queryPersonalManageInfo(const string& id);
	bool modifyPersonalManageInfo(const PersonalManageInfoDTO::Wrapper& dto);
};

#endif