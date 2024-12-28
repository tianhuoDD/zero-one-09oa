#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 25日 星期五 19:33:03 CST
*/
#ifndef _ADDPERSON_SERVICE_
#define _ADDPERSON_SERVICE_
#include <list>
#include "domain/vo/put/AddPersonVO.h"
#include "domain/dto/put/AddPersonDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class AddPersonService
{
public:
	// 保存数据
	AddPersonDTO::Wrapper saveData(const AddPersonDTO::Wrapper& dto);
};

#endif // !_ADDPERSON_SERVICE_

