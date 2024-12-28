#pragma once
#ifndef _ADDMENU_SERVICE_
#define _ADDMENU_SERVICE_
#include <list>
//#include "domain/vo/sa/SampleVO.h"
#include "../../../domain/vo/Functional-permissions/Add-menu/AddmenuVO.h"
//#include "domain/query/sample/SampleQuery.h"
//#include "domain/dto//SampleDTO.h"
#include  "../../../domain/dto/Functional-permissions/Add-menu/AddmenuDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class AddmenuService
{
public:
	
	// 保存数据
	uint64_t saveData(const AddmenuDTO::Wrapper& dto);
	uint64_t selectDatabyrole_id(const AddmenuDTO::Wrapper& dto);
	uint64_t selectDatabypermissions(const AddmenuDTO::Wrapper& dto);
	uint64_t selectDataisexist(const AddmenuDTO::Wrapper& dto);
	// 修改数据
	//bool updateData(const AddmenuDTO::Wrapper& dto);
	// 通过ID删除数据
	//bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_
