//
// Created by asd on 2024/10/25.
//

#include "GroupManagementDAO.h"

#include "OrgGroupIdListMapper.h"
#include "OrgGroupNameMapper.h"
#include "OrgGroupUnitListMapper.h"
#include "OrgUnitNameMapper.h"
#include "domain/do/groupmanagement/OrgGroupGroupListDO.h"

int GroupManagementDAO::delByGroupIdList(const DelGroupMemberDTO::Wrapper& dto) {
	string groupId = dto->gruopId;//所属的群组的id

	for(auto& it : *dto->groupList) {
		if( groupId == *it ) {
			return 0;
		}
	}

	string groupListId = "'" + dto->groupList->front() + "'";//从属的群组列表id
	//先获取第一个群组id
	auto it = dto->groupList->begin();
	++it;
	for (; it != dto->groupList->end(); ++it ) {
		groupListId.append(", '" +  *it + "'");//拼接id列表
	}

	string sqlDel =  "DELETE FROM org_group_grouplist WHERE GROUP_XID = '" + dto->gruopId + "' AND xgroupList in (" + groupListId + ")";

	string sqlUpdate = "UPDATE org_group_grouplist AS ogg JOIN "
			"(SELECT xgroupList, ROW_NUMBER() OVER "
			"(PARTITION BY GROUP_XID ORDER BY xorderColumn) "
			"AS new_order FROM org_group_grouplist WHERE GROUP_XID = "
			"'" + groupId + "') AS subquery ON "
			"ogg.xgroupList = subquery.xgroupList SET ogg.xorderColumn = "
			"subquery.new_order - 1 WHERE ogg.GROUP_XID = '" + groupId + "'";

	sqlSession->beginTransaction();
	if( sqlSession->executeUpdate(sqlDel) > 0 ) {
		if( sqlSession->executeUpdate(sqlUpdate) > 0 ) {
			sqlSession->commitTransaction();
			return 1;
		}
	}
	sqlSession->rollbackTransaction();

	return 0;
}

int GroupManagementDAO::delByUnitIdList(const DelUnitMemberDTO::Wrapper &dto) {
	string groupId = dto->gruopId;//所属的群组的id

	string unitListId = "'" + dto->unitList->front() + "'";//从属的组织列表id
	//先获取第一个组织id
	auto it = dto->unitList->begin();
	++it;
	for (; it != dto->unitList->end(); ++it ) {
		unitListId.append(", '" +  *it + "'");//拼接id列表
	}

	string sqlDel =  "DELETE FROM org_group_unitlist WHERE GROUP_XID = '"
						+ dto->gruopId + "' AND xunitList in (" + unitListId + ")";

	string sqlUpdate = "UPDATE org_group_unitlist AS ogg JOIN "
			"(SELECT xunitList, ROW_NUMBER() OVER "
			"(PARTITION BY GROUP_XID ORDER BY xorderColumn) "
			"AS new_order FROM org_group_unitlist WHERE GROUP_XID = "
			"'" + groupId + "') AS subquery ON "
			"ogg.xunitList = subquery.xunitList SET ogg.xorderColumn = "
			"subquery.new_order - 1 WHERE ogg.GROUP_XID = '" + groupId + "'";

	sqlSession->beginTransaction();
	if( sqlSession->executeUpdate(sqlDel) > 0 ) {
		if( sqlSession->executeUpdate(sqlUpdate) > 0 ) {
			sqlSession->commitTransaction();
			return 1;
		}
	}
	sqlSession->rollbackTransaction();

	return 0;
}

int GroupManagementDAO::addGroupIdList(string& groupId, list<string>& addIdList, list<string>& delIdList) {
	string sqlUpdate = "UPDATE org_group_grouplist AS ogg JOIN "
			"(SELECT xgroupList, ROW_NUMBER() OVER "
			"(PARTITION BY GROUP_XID ORDER BY xorderColumn) "
			"AS new_order FROM org_group_grouplist WHERE GROUP_XID = "
			"'" + groupId + "') AS subquery ON "
			"ogg.xgroupList = subquery.xgroupList SET ogg.xorderColumn = "
			"subquery.new_order - 1 WHERE ogg.GROUP_XID = '" + groupId + "'";

	sqlSession->beginTransaction();
	if( !addIdList.empty() ) {
		//有群组要增加
		string add = "('" + groupId + "', '" + addIdList.front() + "', '-1')";//从属的群组列表id
		auto it = addIdList.begin();
		++it;
		for(; it != addIdList.end(); ++it) {
			add.append( ", ('" + groupId + "', '" );
			add.append( *it + "', '-1')" );
		}

		string sqlAdd = "INSERT INTO org_group_grouplist (GROUP_XID, xgroupList, xorderColumn) VALUES" + add ;
		if( sqlSession->executeUpdate(sqlAdd) <= 0 ) {
			//增加失败，回滚事务
			sqlSession->rollbackTransaction();
			return 0;
		}
	}
	if( !delIdList.empty() ) {
		//有群组要删除
		string del = "'" + delIdList.front() + "'";//从属的群组列表id
		//先获取第一个群组id
		auto it = delIdList.begin();
		++it;
		for (; it != delIdList.end(); ++it ) {
			del.append(", '" +  *it + "'");//拼接id列表
		}

		string sqlDel =  "DELETE FROM org_group_grouplist WHERE GROUP_XID = '"
			+ groupId + "' AND xgroupList in (" + del + ")";
		if( sqlSession->executeUpdate(sqlDel) <= 0 ) {
			//删除失败，回滚事务
			sqlSession->rollbackTransaction();
			return 0;
		}
	}

	if( sqlSession->executeUpdate(sqlUpdate) >= 0 ) {
		//不知道为什么，这个删除操作之后，还剩一个群组id，执行了update后返回为0
		//更新orderColumn成功
		sqlSession->commitTransaction();
		return 1;
	}

	sqlSession->rollbackTransaction();
	return 0;
}

int GroupManagementDAO::addUnitIdList(string& groupId, list<string>& addIdList, list<string>& delIdList) {
	string sqlUpdate = "UPDATE org_group_unitlist AS ogg JOIN "
			"(SELECT xunitList, ROW_NUMBER() OVER "
			"(PARTITION BY GROUP_XID ORDER BY xorderColumn) "
			"AS new_order FROM org_group_unitlist WHERE GROUP_XID = "
			"'" + groupId + "') AS subquery ON "
			"ogg.xunitList = subquery.xunitList SET ogg.xorderColumn = "
			"subquery.new_order - 1 WHERE ogg.GROUP_XID = '" + groupId + "'";

	sqlSession->beginTransaction();
	if( !addIdList.empty() ) {
		//有群组要增加
		string add = "('" + groupId + "', '" + addIdList.front() + "', '-1')";//从属的群组列表id
		auto it = addIdList.begin();
		++it;
		for(; it != addIdList.end(); ++it) {
			add.append( ", ('" + groupId + "', '" );
			add.append( *it + "', '-1')" );
		}

		string sqlAdd = "INSERT INTO org_group_unitlist (GROUP_XID, xunitList, xorderColumn) VALUES" + add ;
		if( sqlSession->executeUpdate(sqlAdd) <= 0 ) {
			//增加失败，回滚事务
			sqlSession->rollbackTransaction();
			return 0;
		}
	}
	if( !delIdList.empty() ) {
		//有群组要删除
		string del = "'" + delIdList.front() + "'";//从属的群组列表id
		//先获取第一个群组id
		auto it = delIdList.begin();
		++it;
		for (; it != delIdList.end(); ++it ) {
			del.append(", '" +  *it + "'");//拼接id列表
		}

		string sqlDel =  "DELETE FROM org_group_unitlist WHERE GROUP_XID = '"
			+ groupId + "' AND xunitList in (" + del + ")";
		if( sqlSession->executeUpdate(sqlDel) <= 0 ) {
			//删除失败，回滚事务
			sqlSession->rollbackTransaction();
			return 0;
		}
	}

	if( sqlSession->executeUpdate(sqlUpdate) >= 0 ) {
		//不知道为什么，这个删除操作之后，还剩一个群组id，执行了update后返回为0
		//更新orderColumn成功
		sqlSession->commitTransaction();
		return 1;
	}

	sqlSession->rollbackTransaction();
	return 0;
}

list<OrgGroupDO> GroupManagementDAO::queryGroupNameByGroupIdList(string gorupId) {
	string sql = "SELECT og.xid, og.xname, og.xdistinguishedName "
		"FROM org_group_grouplist ogl JOIN org_group og ON og.xid = ogl.xgroupList "
		"WHERE ogl.GROUP_XID = '" + gorupId + "'";
	OrgGroupNameMapper mapper;
	return sqlSession->executeQuery<OrgGroupDO, OrgGroupNameMapper>(sql, mapper);
}

list<OrgUnitDO> GroupManagementDAO::queryUnitNameByUnitIdList(string gorupId) {
	string sql = "SELECT ou.xid, ou.xname, ou.xlevelName "
		"FROM org_group_unitlist oul JOIN org_unit ou ON ou.xid = oul.xunitList "
		"WHERE oul.GROUP_XID = '" + gorupId + "'";
	OrgUnitNameMapper mapper;
	return sqlSession->executeQuery<OrgUnitDO, OrgUnitNameMapper>(sql, mapper);
}

list<oatpp::String> GroupManagementDAO::queryGroupIdListByGroupId(oatpp::String groupId) {
	string sql = "SELECT xgroupList FROM org_group_grouplist WHERE GROUP_XID = ?";
	OrgGroupIdListMapper mapper;
	return sqlSession->executeQuery<oatpp::String, OrgGroupIdListMapper>(sql, mapper, "%s", *groupId);
}

list<oatpp::String> GroupManagementDAO::queryUnitIdListByGroupId(oatpp::String groupId) {
	string sql = "SELECT xunitList FROM org_group_unitlist WHERE GROUP_XID = ?";
	OrgGroupUnitListMapper mapper;
	return sqlSession->executeQuery<oatpp::String, OrgGroupUnitListMapper>(sql, mapper, "%s", *groupId);
}

