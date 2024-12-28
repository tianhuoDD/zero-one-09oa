#pragma once
#ifndef _DELETE_SERVICE_
#define _DELETE_SERVICE_
#include <list>
#include "../../../domain/vo/Functional-permissions/Delete-menu/DeletemenuVO.h"
#include "../../../domain/dto/Functional-permissions/Delete-menu/DeletemenuDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class DeletemenuService
{
public:
	// 分页查询所有数据
	uint64_t selectData(const DeletemenuDTO::Wrapper& dto);
	// 保存数据
	
	// 修改数据
	
	// 删除数据
	uint64_t removeData(const DeletemenuDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_