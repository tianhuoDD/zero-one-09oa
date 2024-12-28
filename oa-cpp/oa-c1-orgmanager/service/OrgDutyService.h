#pragma once

#ifndef _ORGDUTY_SERVICE_
#define _ORGDUTY_SERVICE_
#include <list>
#include "domain/dto/OrgDutyDTO.h"
#include <chrono>
#include <thread>
#include <random>
#include "../dao/OrgDutyDAO.h"
#include "../../lib-common/include/SnowFlake.h"
#include "Macros.h"
//#include " ChinToPinyin.h"


class OrgDutyService
{
public:
	// 保存数据
	string saveData(const OrgDutyDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const OrgDutyDTO::Wrapper& dto);
};

#endif