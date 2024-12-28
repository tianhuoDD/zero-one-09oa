#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 26日 星期六 09:37:55 CST
*/
#ifndef _REMOVEPERSON_SERVICE_
#define _REMOVEPERSON_SERVICE_
#include <list>
#include "domain/vo/del/RemovePersonVO.h"
#include "domain/dto/del/RemovePersonDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class RemovePersonService
{
public:
	// 通过xpersonList删除数据
	bool removeData(const string&group_person);
};

#endif // !_REMOVEPERSON_SERVICE_

