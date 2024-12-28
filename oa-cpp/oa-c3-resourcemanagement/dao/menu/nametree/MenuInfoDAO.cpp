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
 limitations under the License.
*/
#include "stdafx.h"
#include "MenuInfoDAO.h"
#include "MenuInfoMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->menu_id) { \
	sql << " AND menu_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->menu_id.getValue("")); \
} \
if (query->menu_name) { \
	sql << " AND menu_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->menu_name.getValue("")); \
} \
if (query->parent_id) { \
	sql << " AND parent_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->parent_id.getValue("")); \
} \
if (query->level) { \
	sql << " AND level=?"; \
	SQLPARAMS_PUSH(params, "i", uint64_t, query->level.getValue(0)); \
} 




uint64_t MenuInfoDAO::count(const MyMenuInfoQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM org_menu";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<MenuInfoDO> MenuInfoDAO::selectWithPage(const MyMenuInfoQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT menu_id,menu_name,parent_id,level,icon FROM org_menu";
	SAMPLE_TERAM_PARSE(query, sql);
	//sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	MenuInfoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MenuInfoDO, MenuInfoMapper>(sqlStr, mapper, params);
}

//std::list<MenuInfoDO> MenuInfoDAO::selectByName(const string& name)
//{
//	string sql = "SELECT menu_id,menu_name,parent_id,level FROM menuinfo WHERE `name` LIKE CONCAT('%',?,'%')";
//	MenuInfoMapper mapper;
//	return sqlSession->executeQuery<MenuInfoDO, MenuInfoMapper>(sql, mapper, "%s", name);
//}
//std::list<MenuInfoDO> MenuInfoDAO::selectAll()
//{
//	string sql = "SELECT menu_id,menu_name,parent_id,level FROM menuinfo";
//	MenuInfoMapper mapper;
//	return sqlSession->executeQuery<MenuInfoDO, MenuInfoMapper>(sql, mapper);
//}

//uint64_t MenuUseAutorityDAO::insert(const MenuUseAutorityDO& iObj)
//{
//	string sql = "INSERT INTO `menuuseautority` (`mid`, `name`, `userid`, `type`, `status`) VALUES (?, ?, ?, ?, ?)";
//	return sqlSession->executeInsert(sql, "%i%s%i%s%s", iObj.getMid(), iObj.getName(), iObj.getUserid(), iObj.getType(), iObj.getStatuss());
//}
//
//int MenuUseAutorityDAO::update(const MenuUseAutorityDO& uObj)
//{
//	string sql = "UPDATE `menuuseautority` SET `mid`=?,`name`=?,`userid`=?, `type`=?, `status`=? WHERE `mid`=?";
//	return sqlSession->executeUpdate(sql, "%ull%i%s%i%s%s", uObj.getAid(), uObj.getMid(), uObj.getName(), uObj.getUserid(), uObj.getType(), uObj.getStatuss() );
//}
//
//int MenuUseAutorityDAO::deleteById(uint64_t aid)
//{
//	string sql = "DELETE FROM `menuuseautority` WHERE `aid`=?";
//	return sqlSession->executeUpdate(sql, "%ull", aid);
//}