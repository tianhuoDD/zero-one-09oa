#pragma once
#ifndef _CONFIGURATIONDAO_
#define _CONFIGURATIONDAO_
#include "BaseDAO.h"
#include"../../../domain/do/configuration/atq/ConfigurationDO.h"
/**
 * 示例表数据库操作实现
 */
class ConfigurationDAO : public BaseDAO
{
public:
	// 通过分类标识查询数据
	list<ConfigurationDO> selectById(const string& id);
	// 插入数据
	int insert(const ConfigurationDO& iObj);
	// 修改数据
	int update(const ConfigurationDO& uObj);
	// 通过ID删除数据
	int deleteById(string id);
};
#endif // !_SAMPLE_DAO_
