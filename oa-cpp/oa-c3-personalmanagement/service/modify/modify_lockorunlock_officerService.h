#pragma once
#ifndef _MODIFY_LOCKORUNLOCK_OFFICERSERVICE_
#define _MODIFY_LOCKORUNLOCK_OFFICERSERVICE_

#include <list>
#include "../../domain/dto/modify/modify_lockorunlock_officerDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class modify_lockorunlock_officerService
{
public:

	// 修改数据
	bool updateData(const modify_lockorunlock_officerDTO::Wrapper& dto);

};











#endif // !_MODIFY_LOCKORUNLOCK_OFFICERSERVICE_
