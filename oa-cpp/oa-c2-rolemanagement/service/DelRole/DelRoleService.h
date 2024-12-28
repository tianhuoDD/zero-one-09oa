#pragma once
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include <string>

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class DelRoleService
{
public:

	// 通过ID删除数据
	bool removeData(std::string id);
};

#endif // !_SAMPLE_SERVICE_