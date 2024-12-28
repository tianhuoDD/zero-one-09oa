/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.  MenuInfo
*/
#include "stdafx.h"
#include "MenuInfoDAO.h"
#include "MenuInfoMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define MENUINFO_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->menu_id) { \
	sql << " AND menu_id=?"; \
	SQLPARAMS_PUSH(params, "s", string, query->menu_id.getValue("")); \
}\
if (query->menu_name) { \
	sql << " AND `menu_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->menu_name.getValue("")); \
}\
if (query->menu_type) {\
		sql << " AND `menu_type`=?"; \
		SQLPARAMS_PUSH(params, "i", std::int, query->menu_type.getValue(7)); \
}\
if (query->parent_id) {\
		sql << " AND `parent_id`=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->parent_i.getValue("")); \
}
//if (query->orgabbreviation) { \
//	sql << " AND `orgabbreviation`=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->orgabbreviation.getValue("")); \
//}\
//if (query->orgicon) {\
//		sql << " AND `orgicon`=?"; \
//		SQLPARAMS_PUSH(params, "s", std::string, query->orgicon.getValue("")); \
//}\
//if (query->orgdescription) {\
//		sql << " AND `orgdescription`=?"; \
//		SQLPARAMS_PUSH(params, "s", std::string, query->orgdescription.getValue("")); \
//}\
//if (query->manager) {\
//		sql << " AND `manager`=?"; \
//		SQLPARAMS_PUSH(params, "s", std::string, query->manager.getValue("")); \
//}


//uint64_t MenuInfoDAO::count(const MenuInfoQuery::Wrapper& query)
//{
//	stringstream sql;
//	sql << "SELECT COUNT(*) FROM MenuInfo";
//	MENUINFO_TERAM_PARSE(query, sql);
//	string sqlStr = sql.str();
//	return sqlSession->executeQueryNumerical(sqlStr, params);
//}

//std::list<MenuInfoDO> MenuInfoDAO::selectWithPage(const MenuInfoQuery::Wrapper& query)
//{
//	stringstream sql;
//	sql << "SELECT menu_id,menu_name,menu_type,parent_id FROM MenuInfo";
//	MENUINFO_TERAM_PARSE(query, sql);
//	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
//	MenuInfoMapper mapper;
//	string sqlStr = sql.str();
//	return sqlSession->executeQuery<MenuInfoDO, MenuInfoMapper>(sqlStr, mapper, params);
//}

std::list<MenuInfoDO> MenuInfoDAO::selectByName(const string& menu_name)
{
	string sql = "SELECT menu_id,menu_name,menu_type,parent_id FROM org_menu WHERE `menu_name` LIKE CONCAT('%',?,'%')";
	MenuInfoMapper mapper;
	return sqlSession->executeQuery<MenuInfoDO, MenuInfoMapper>(sql, mapper, "%s", menu_name);
}
//* 我自己加的一个按照menu_id查询
std::list<MenuInfoDO> MenuInfoDAO::selectById(const string& menu_id)
{
	stringstream sql;
	sql<< "SELECT menu_id,menu_name,menu_type,parent_id FROM org_menu WHERE `menu_id`=" << menu_id;
	string sqlStr = sql.str();

	MenuInfoMapper mapper;
	return sqlSession->executeQuery<MenuInfoDO, MenuInfoMapper>(sqlStr, mapper);
}

uint64_t MenuInfoDAO::insert(const MenuInfoDO& iObj)
{
	string sql = "INSERT INTO `org_menu` ( `menu_id`,`menu_name`,`menu_type`,`parent_id`) VALUES (?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%i%s", iObj.getMenu_Id(), iObj.getMenu_Name(), iObj.getMenu_Type(), iObj.getParent_Id());
}
//* menu_id一定是和%ull对应，其他的string型和%s对应，int和%i对应
int MenuInfoDAO::update(const MenuInfoDO& uObj)
{
	string sql = "UPDATE `org_menu` SET `menu_name`=?, `menu_type`=?, `parent_id`=? WHERE `menu_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%s", uObj.getMenu_Id(), uObj.getMenu_Name(), uObj.getMenu_Type(), uObj.getParent_Id());
}

int MenuInfoDAO::deleteById(uint64_t menu_id)
{
	string sql = "DELETE FROM `org_menu` WHERE `menu_id`=?";
	return sqlSession->executeUpdate(sql, "%s", menu_id);
}