#pragma once
#ifndef _ADDSERVE_
#define _ADDSERVE_
#include <list>
#include "../../domain/dto/Person/add/PersonInfoDTO.h"
#include "../../domain/do/org_personDo/org_personDO.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class AddServe
{
public:

	// 保存数据
	uint64_t saveData(const PersioninfoDTO::Wrapper& dto);
	//删除数据
	bool removeData(string id);
	//获取当前时间
	string getTime();
	//获取序列号
	string getSequence(string time, string id);
	//获取年龄
	int getAge(string time, string birth);
};

#endif  
