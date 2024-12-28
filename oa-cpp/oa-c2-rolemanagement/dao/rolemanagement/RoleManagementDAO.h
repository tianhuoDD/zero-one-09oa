#pragma once

#ifndef _ROLEMANAGEMENTDAO_H_
#define _ROLEMANAGEMENTDAO_H_
#include "BaseDAO.h"
#include "domain/do/put/org_role/OrgRoleDO.h"
#include "domain/do/get/personlist/OrgRolePersonListDO.h"
#include "../../domain/query/get/PersonListQuery/PersonListQuery.h"
#include "domain/do/del/rolegrouplist/OrgRoleGroupListDO.h"
#include "dao/rolemanagement/RoleGroupListMapper.h"
#include "dao/rolemanagement/MenuListMapper.h"
#include "domain/do/get/roleresource/RoleResourceDO.h"
#include "dao/rolemanagement/RoleResourceListMapper.h"
#include "domain/do/get/roleresource/OrgResRoleMenuDO.h"
#include "domain/do/rolemanagement/RoleManagementDO/put/addrole/AddroleDO.h"


class RoleManagementDAO : public BaseDAO
{
public:
	uint64_t insertToOrgRoleGroupList(const std::list<OrgRoleGroupListDO>& listIobj);
	uint64_t updateOrgRoleGroupList(const string roleId, list<oatpp::String>& dataGroupList, std::list<OrgRoleGroupListDO>& listData);
	uint64_t deleteOrgRoleGroupList(const string roleId, const string groupId, const uint64_t maxColumn);
	uint64_t deleteOrgRoleGroupListOperation(const string roleId, const std::list<oatpp::String>& groupList);
	uint64_t selectMaxXordercolumn(const string roleId, const string dataTableName, const string field);
	std::list<oatpp::String> selectGroupList(const string roleId);
	std::list<oatpp::String> selectMenuList(const string roleId);
	std::list<RoleResourceDO> selectRoleResource(const std::list<oatpp::String>& menuList);
	uint64_t insertToOrgResRoleMenu(const std::list<OrgResRoleMenuDO>& listIobj);
	uint64_t deleteOrgResRoleMenu(const string roleId, list<oatpp::String>&, std::list<OrgResRoleMenuDO>&);

	//int update(const OrgRoleDO& uObj);

	//判断role->xunique是否唯一
	uint64_t roleUnique(const string& xunique);
	//更改数据 lhg
	int update(const OrgRoleDO& uObj);
	//role->PersonList页数 lhg
	uint64_t count(const PersonListQuery::Wrapper& query);
	//分页查询 lhg
	list<OrgRolePersonListDO> selectWithPage(const PersonListQuery::Wrapper& query);
};

#endif // !_ROLEMANAGEMENTDAO_H_

