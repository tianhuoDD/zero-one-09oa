#pragma once

#ifndef _GETADDMTROOMPOS_SERVICE_
#define _GETADDMTROOMPOS_SERVICE_
#include <list>
#include "domain/vo/getmtroompos/GetmtroomposVO.h"
#include "domain/query/getmtroompos/GetmtroomposQuery.h"
#include "domain/dto/getmtroompos/GetmtroomposDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class GetAddmtroomposService
{
public:
	// 分页查询所有数据
	GetmtroomposPageDTO::Wrapper listAll(const GetmtroomposQuery::Wrapper& query);
	// 新增数据
	bool insertData(const AddmtroomposDTO::Wrapper& dto);
};

#endif // !_GETADDMTROOMPOS_SERVICE_

