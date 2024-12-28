#pragma once
#ifndef _MODIFYGROUPINFO_SERVICE_
#define _MODIFYGROUPINFO_SERVICE_
#include <list>
#include "domain/vo/group/GroupVO.h"
#include "domain/dto/group/GroupDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ModifyGroupInfoService
{
public:
	//// 分页查询所有数据
	//SamplePageDTO::Wrapper listAll(const SampleQuery::Wrapper& query);
	// 保存数据
	//uint64_t saveData(const GroupDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const GroupDTO::Wrapper& dto);
};

#endif // !_MODIFYGROUPINFO_SERVICE_
