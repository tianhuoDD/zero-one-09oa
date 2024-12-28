#pragma once
#ifndef _ATTRIB_SERVICE_
#define _ATTRIB_SERVICE_
#include <list>
#include "domain/vo/Attrib_modify/Attrib_modify_VO.h"
#include "domain/dto/Attrib_modify/Attrib_modify_DTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class Attrib_modify_Service
{
public:
	//查找id是否存在
	uint64_t select_id(const Attrib_modify_DTO::Wrapper& dto);

	// 修改数据
	bool updateData(const Attrib_modify_DTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_

