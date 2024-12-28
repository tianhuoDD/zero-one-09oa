#pragma once
#ifndef _PUTSERVICE_
#define _PUTSERVICE_
#include <list>
#include"domain/vo/New/PutVO.h"
#include"domain/dto/New/PutDTO.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class PutService
{
public:
	//查询数据
	
	bool updateData(const PutDTO::Wrapper& dto);
	// 通分类标识删除数据
	
};

#endif // 

