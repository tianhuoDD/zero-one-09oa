#pragma once

#ifndef _ROLEMANAGEMENTSERVICE_H_
#define _ROLEMANAGEMENTSERVICE_H_

#include "../../domain/GlobalInclude.h"
#include <list>
//vo的头
#include "domain/query/get/PersonListQuery/PersonListQuery.h"
#include "domain/dto/put/groupmember/GroupMemberDTO.h"
#include "domain/vo/get/roleresource/RoleResourceVO.h"
#include "domain/dto/post/roleresource/RoleResourceInfoDTO.h"
#include "domain/do/del/rolegrouplist/OrgRoleGroupListDO.h"
#include "dao/rolemanagement/RoleManagementDAO.h"
#include "tree/TreeUtil.h"
#include "dao/rolemanagement/RoleResourceListMapper.h"
#include "service/TreeRoleResourceInfoMapper.h"
#include "domain/dto/post/roleresource/RoleResourceListDTO.h"

#include "domain/dto/put/updaterole/UpdateRoleDTO.h"
#include"domain/dto/rolemanagement/RoleManagementDTO/get/personlist/PersonListDTO.h"

#include"dao/rolemanagement/RoleManagementDAO.h"
#include"SimpleDateTimeFormat.h"
#include<ctime>
#include "domain/do/put/org_role/OrgRoleDO.h"


class RoleManagementService
{
public:
	uint64_t saveGroupMember(const GroupMemberDTO::Wrapper& idList);
	uint64_t removeGroupMember(const GroupMemberDTO::Wrapper& idList);
	void listRoleMenu(const std::string& roleId, const RoleResourceJsonVO::Wrapper& vo);
	uint64_t updateRoleResource(const RoleResourceListDTO::Wrapper& roleResource);

	//bool updateData(const UpdateRoleDTO::Wrapper& dto);


	// 分页查询所有数据
	PersonListPageDTO::Wrapper listAll(const PersonListQuery::Wrapper& query);
	// 修改数据
	bool updateData(const UpdateRoleDTO::Wrapper& dto);
};

#endif // !_ROLEMANAGEMENTSERVICE_H_