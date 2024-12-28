#pragma once

#ifndef _SYSTEMINFO_SERVICE_
#define _SYSTEMINFO_SERVICE_
#include "../../domain/dto/system/setting/SystemInfoDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class SystemInfoService
{
public:
	// 更新系统副标题
	bool modifySystemSubtitle(const SystemInfoDTO::Wrapper& dto);
	// 更新系统名称
	bool modifySystemName(const SystemInfoDTO::Wrapper& dto);
};

#endif // !_SYSTEMINFO_SERVICE_