#pragma once
#ifndef _COLUMNSINFO_SERVICE_
#define _COLUMNSINFO_SERVICE_
#include <list>
#include "../../../domain/vo/column/setting/ColumnsInfoVO.h"
#include "../../../domain/dto/column/setting/ColumnsInfoDTO.h"
//#include "domain/query/sample/SampleQuery.h"


/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ColumnsInfoService
{
public:
	// 分页查询所有数据
	//SamplePageDTO::Wrapper listAll(const SampleQuery::Wrapper& query);
	
	//查询数据库中是否存在这个,通过name查询
	bool QueryData(const ColumnsInfoDTO::Wrapper& dto);
	//通过id查询数据
	ColumnsInfoDTO::Wrapper QueryDataById(const ColumnsInfoDTO::Wrapper& dto);
	// 保存数据
	uint64_t saveData(const ColumnsInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改数据
	bool updateData(const ColumnsInfoDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_COLUMNSINFO_SERVICE_

