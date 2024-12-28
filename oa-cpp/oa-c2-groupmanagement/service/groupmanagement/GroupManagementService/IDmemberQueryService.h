#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 23日 星期三 17:36:17 CST
*/
#ifndef _IDMEMBERQUERY_SERVICE_
#define _IDMEMBERQUERY_SERVICE_
#include <list>
#include "domain/vo/get/IDmemberVO.h"
#include "domain/query/get/IDmemberQuery.h"
#include "domain/dto/get/IDmemberDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class IDmemberQueryService
{
public:
	// 分页查询所有数据
	IDmemberPageDTO::Wrapper listAll(const IDmemberQuery::Wrapper& query);
};

#endif // !_IDMEMBERQUERY_SERVICE_

