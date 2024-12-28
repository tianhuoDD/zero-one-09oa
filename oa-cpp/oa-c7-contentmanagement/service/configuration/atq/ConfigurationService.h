#pragma once
#ifndef _CONFIGURATIONSERVICE_
#define _CONFIGURATIONSERVICE_
#include <list>
#include "domain/vo/configuration/atq/configurationVo.h"
#include "domain/dto/configuration/atq/configurationDto.h"
#include "../../../dao/configuration/atq/ConfigurationDAO.h"
#include "../../../dao/configuration/atq/ConfigurationMapper.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ConfigurationService
{
public:
	//查询数据
	ConfigurationPageDTO::Wrapper listAll(string id);
	// 保存数据
	int saveData(const ConfigurationDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const ConfigurationDTO::Wrapper& dto);
	// 通分类标识删除数据
	bool removeData(string id);
};

#endif // 

