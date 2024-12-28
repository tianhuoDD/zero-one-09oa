#pragma once
#ifndef _ATTRIB_SERVICE_
#define _ATTRIB_SERVICE_
#include <list>
#include "domain/vo/Attrib_add/Attrib_add_VO.h"
#include "domain/dto/Attrib_add/Attrib_add_DTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class Attrib_add_Service
{
public:
	//查找id是否存在
	uint64_t select_id(const Attrib_add_DTO::Wrapper& dto);

	// 保存数据
	uint64_t saveData1(const Attrib_add_DTO::Wrapper& dto);
	uint64_t saveData2(const Attrib_add_DTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_

