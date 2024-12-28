#pragma once
#ifndef _APPLICATION_DAO_
#define _APPLICATION_DAO_

#include "BaseDAO.h"
#include <list>
#include "domain/do/application/ApplicationTypesDO.h"
#include "domain/do/application/ApplicationPropertiesDO.h"
#include "domain/query/application/ApplicationQuery.h"
#include "domain/do/application/ApplicationDO.h"
#include "domain/do/application/ApplicationNameDO.h"

class ApplicationDAO : public BaseDAO {
public:
	// 统计数据条数
	uint64_t count(const ApplicationQuery::Wrapper& query);
	// 分页查询数据
	list<ApplicationDO> selectWithPage(const ApplicationQuery::Wrapper& query);
	// 查询所有应用名称
	list<ApplicationNameDO> selectApplicationName();
	// 插入数据
	uint64_t insert(const ApplicationDO& iObj);
	// 通过name删除数据
	uint64_t deleteById(std::string id);
	// 查询应用类型
	list<ApplicationTypesDO> selectAppTypes();
	// 查询应用属性
	list<ApplicationPropertiesDO> selectAppProperties(const string& id);
	// 查询其他应用属性
	list<AvailableGroupListDO> selectAvailableGroupList(const string& appid);
	list<AvailableIdentityListDO> selectAvailableIdentityList(const string& appid);
	list<AvailableUnitListDO> selectAvailableUnitList(const string& appid);
	list<ControllerListDO> selectControllerList(const string& appid);

	// 修改应用属性
	int updateAppProperties(const ApplicationPropertiesDO& obj);
	// 增加可用身份
	int insertAvailableIdentity(const AvailableIdentityListDO& obj);
	// 增加可用组织
	int insertAvailableGroup(const AvailableGroupListDO& obj);
	// 增加管理者
	int insertController(const ControllerListDO& obj);
	// 增加可用组织
	int insertAvailableUnit(const AvailableUnitListDO& obj);
	// 根据名字查询可用身份对应的id
	list<ApplicationNameDO> selectAvailableIdentityId(const string& identityName);
	// 根据名字查询可用组织对应的id
	list<ApplicationNameDO> selectAvailableGroupId(const string& groupName);
	// 根据名字查询可用单元对应的id
	list<ApplicationNameDO> selectAvailableUnitId(const string& unitName);
	// 根据名字查询管理者对应的id
	list<ApplicationNameDO> selectControllerId(const string& controllerName);

	// 删除可用身份
	int deleteAvailableIdentity(const string& appId);
	// 删除可用组织
	int deleteAvailableGroup(const string& appId);
	// 删除管理者
	int deleteController(const string& appId);
	// 删除可用组织
	int deleteAvailableUnit(const string& appId);
	// 修改属性
	int updateProp(const string& appId, const string& propJson);
};

#endif // !_APPLICATION_DAO_