/*
 Copyright Zero One Star. All rights reserved.

 @Author: UptoFate
 @Date: 2024/10/22 14:26:52

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
#include "OrgUnitattributeDAO.h"
#include "OrgUnitattributeMapper.h"
#include <sstream>

// 定义条件解析宏，用于减少重复代码
#define ORG_UNITATTRIBUTE_TERM_PARSE(query, sql) \
SqlParams params; \
sql << " WHERE 1=1"; \
if (query->xid) { \
    sql << " AND `xid`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->xid.getValue("")); \
} \
if (query->xcreateTime) { \
    sql << " AND xcreateTime=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->xcreateTime.getValue("")); \
} \
if (query->xsequence) { \
    sql << " AND xsequence=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->xsequence.getValue("")); \
} \
if (query->xupdateTime) { \
    sql << " AND xupdateTime=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->xupdateTime.getValue("")); \
} \
if (query->xdistributeFactor) { \
    sql << " AND xdistributeFactor=?"; \
    SQLPARAMS_PUSH(params, "i", int, query->xdistributeFactor.getValue(0)); \
} \
if (query->xdescription) { \
    sql << " AND xdescription=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->xdescription.getValue("")); \
} \
if (query->xdistinguishedName) { \
    sql << " AND xdistinguishedName=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->xdistinguishedName.getValue("")); \
} \
if (query->xname) { \
    sql << " AND xname=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->xname.getValue("")); \
} \
if (query->xorderNumber) { \
    sql << " AND xorderNumber=?"; \
    SQLPARAMS_PUSH(params, "i", int, query->xorderNumber.getValue(0)); \
} \
if (query->xpinyin) { \
    sql << " AND xpinyin=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->xpinyin.getValue("")); \
} \
if (query->xpinyinInitial) { \
    sql << " AND xpinyinInitial=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->xpinyinInitial.getValue("")); \
} \
if (query->xunique) { \
    sql << " AND xunique=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->xunique.getValue("")); \
} \
if (query->xunit) { \
    sql << " AND xunit=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->xunit.getValue("")); \
}


uint64_t OrgUnitattributeDAO::count(const OrgUnitattributeQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM org_unitattribute";
    ORG_UNITATTRIBUTE_TERM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<OrgUnitattributeDO> OrgUnitattributeDAO::selectWithPage(const OrgUnitattributeQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM org_unitattribute";
    ORG_UNITATTRIBUTE_TERM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	OrgUnitattributeMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<OrgUnitattributeDO, OrgUnitattributeMapper>(sqlStr, mapper, params);
}

//std::list<SampleDO> OrgUnitattributeDAO::selectByName(const string& name)
//{
//	string sql = "SELECT id,name,sex,age FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
//	SampleMapper mapper;
//	return sqlSession->executeQuery<SampleDO, SampleMapper>(sql, mapper, "%s", name);
//}

//uint64_t OrgUnitattributeDAO::insert(const SampleDO& iObj)
//{
//	string sql = "INSERT INTO `sample` (`name`, `sex`, `age`) VALUES (?, ?, ?)";
//	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getName(), iObj.getSex(), iObj.getAge());
//}

//int OrgUnitattributeDAO::update(constOrgUnitattributeDO& uObj)
//{
//	string sql = "UPDATE `sample` SET `name`=?, `sex`=?, `age`=? WHERE `id`=?";
//	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getName(), uObj.getSex(), uObj.getAge(), uObj.getId());
//}

int OrgUnitattributeDAO::deleteById(string id)
{
	string sql = "DELETE FROM `org_unitattribute` WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}