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
#include "MenuUseAutorityDAO.h"
#include "MenuUseAutorityMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->role_id) { \
	sql << " AND role_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->role_id.getValue("")); \
} \
if (query->menulist) { \
	sql << " AND menulist=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->menulist.getValue("")); \
} \
if (query->xorderColumn) { \
	sql << " AND xorderColumn=?"; \
	SQLPARAMS_PUSH(params, "i", uint64_t, query->xorderColumn.getValue(0)); \
} 

uint64_t MenuUseAutorityDAO::count(const MenuUseAutorityQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM org_role_menulist";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<Org_role_menulistDO> MenuUseAutorityDAO::selectWithPage(const MenuUseAutorityQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT role_id,menulist,xorderColumn FROM org_role_menulist";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	MenuUseAutorityMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<Org_role_menulistDO, MenuUseAutorityMapper>(sqlStr, mapper, params);
}

//std::list<MenuUseAutorityDO> MenuUseAutorityDAO::selectByName(const string& name)
//{
//	string sql = "SELECT aid,mid,name,userid,type,status FROM menuuseautority WHERE `name` LIKE CONCAT('%',?,'%')";
//	MenuUseAutorityMapper mapper;
//	return sqlSession->executeQuery<MenuUseAutorityDO, MenuUseAutorityMapper>(sql, mapper, "%s", name);
//}
//
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