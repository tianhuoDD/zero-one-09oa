//
// Created by asd on 2024/10/25.
//

#ifndef GROUPMANAGEMENTDAO_H
#define GROUPMANAGEMENTDAO_H
#include <BaseDAO.h>
#include <domain/dto/groupMember/add/AddGroupMemberDTO.h>
#include <domain/dto/groupMember/del/DelGroupMemberDTO.h>
#include <domain/dto/unitMember/add/AddUnitMemberDTO.h>
#include <domain/dto/unitMember/del/DelUnitMemberDTO.h>

#include "domain/do/groupmanagement/OrgGroupDO.h"
#include "domain/do/groupmanagement/OrgGroupGroupListDO.h"
#include "domain/do/groupmanagement/OrgGroupUnitListDO.h"
#include "domain/do/groupmanagement/OrgUnitDO.h"

//#include "BaseDAO.h"
#include "../../domain/do/get/UserDO.h"
//#include "../../domain/do/get/ModifyDO.h"
//#include "../../domain/query/sample/SampleQuery.h"

class GroupManagementDAO : public BaseDAO {
public:
	//删除群组成员
	int delByGroupIdList(const DelGroupMemberDTO::Wrapper& dto);
	//删除组织成员
	int delByUnitIdList(const DelUnitMemberDTO::Wrapper& dto);

	//增加群组成员,也有可能删除
	int addGroupIdList(string& groupId, list<string>& addIdList, list<string>& delIdList);
	//增加组织成员,也有可能删除
	int addUnitIdList(string& groupId, list<string>& addIdList, list<string>& delIdList);

	//查询群组成员的群组名称
	list<OrgGroupDO> queryGroupNameByGroupIdList(string gorupId);
	//查询组织成员的组织名称
	list<OrgUnitDO> queryUnitNameByUnitIdList(string gorupId);

	//通过群组id查询所属的群组id列表
	list<oatpp::String> queryGroupIdListByGroupId(oatpp::String groupId);
	//通过群组id查询所属的组织id列表
	list<oatpp::String> queryUnitIdListByGroupId(oatpp::String groupId);

	//// 统计数据条数
	//uint64_t count(const SampleQuery::Wrapper& query);
	//// 分页查询数据
	//list<SampleDO> selectWithPage(const SampleQuery::Wrapper& query);
	//// 通过姓名查询数据
	//list<SampleDO> selectByName(const string& name);
	//// 修改数据
	//int update(const SampleDO& uObj);
};



#endif //GROUPMANAGEMENTDAO_H
