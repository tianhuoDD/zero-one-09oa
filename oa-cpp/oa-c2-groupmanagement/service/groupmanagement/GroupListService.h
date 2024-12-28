#pragma once

#ifndef _GROUPLIST_SERVICE_
#define _GROUPLIST_SERVICE_
#include <list>
#include "domain/vo/get/GroupListVO.h"
#include "domain/query/get/GroupListQuery.h"
#include "domain/dto/get/GroupListDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class GroupListService
{
public:
	// 分页查询所有数据
	GroupListPageDTO::Wrapper listAll(const GroupListQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const GroupListDTO::Wrapper& dto);
	//// 修改数据
	//bool updateData(const SampleDTO::Wrapper& dto);
	//// 通过ID删除数据
	//bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

