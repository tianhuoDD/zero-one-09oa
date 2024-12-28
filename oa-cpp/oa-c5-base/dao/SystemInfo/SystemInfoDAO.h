#pragma once

#ifndef _SYSTEMINFO_DAO_
#define _SYSTEMINFO_DAO_

//#include "BaseDAO.h"
#include "domain/dto/system/setting/SystemInfoDTO.h"



/**
 * 数据库操作实现
 */
class SysteminfoDAO
{
public:
	// 修改系统副标题
	bool modifySystemSubtitle(const SystemInfoDTO::Wrapper& dto);
	// 修改系统名称
	bool modifySystemName(const SystemInfoDTO::Wrapper& dto);
};

#endif // !_SYSTEMINFO_DAO_