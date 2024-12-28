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
#include <sstream>
#include "GroupListMapper.h"
#include "GroupListDAO.h"

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->id) { \
	sql << " AND `xid`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if (query->name) { \
	sql << " AND `xname`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} 


uint64_t GroupListDAO::count(const GroupListQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM org_group";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<GroupListDO> GroupListDAO::selectWithPage(const GroupListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT xid,xname,xdescription FROM org_group";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	string sqlStr = sql.str();
	GroupListMapper mapper;
	return sqlSession->executeQuery<GroupListDO, GroupListMapper>(sqlStr, mapper, params);
}

uint64_t GroupListDAO::insert(const GroupListDO& iObj)
{
	string sql = "INSERT INTO `org_group` (`xid`, `xname`, `xdescription`) VALUES (?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s", iObj.getId(), iObj.getName(), iObj.getDescribe());

}
