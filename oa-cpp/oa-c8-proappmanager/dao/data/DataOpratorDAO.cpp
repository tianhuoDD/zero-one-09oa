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
#include "DataOpratorDAO.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->id) { \
	sql << " AND `xid`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if (query->item_id) { \
	sql << " AND `xbundle`=? AND `xid`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->item_id.getValue("")); \
} 




uint64_t DataOpDAO::insert(const DataOpDO& iObj) {
	list<string> sql_str;
	sql_str.push_back("INSERT INTO `pp_e_applicationdict` (`xid`,`xcreateTime`,`xupdateTime`,`xname`,`xalias`, `xsequence`,`xapplication`,`xdescription`) VALUES (?,NOW(),NOW(),?,?,?,?,?)");
	sql_str.push_back("INSERT INTO `pp_e_applicationdictitem` (`xid`,`xcreateTime`,`xupdateTime`,`xsequence`,`xapplication`,`xbooleanValue`,`xbundle`,`xdateTimeValue`,`xdateValue`,`xitemCategory`,`xitemPrimitiveType`,`xitemStringValueType`,`xitemType`,`xnumberValue`,`xstringLongValue`,`xtimeValue`) VALUES(?,NOW(),NOW(),?,?,?,?,?,?,?,?,?,?,?,?,?)");
	return sqlSession->executeUpdate(sql_str.front(), "%s%s%s%s%s%s", iObj.getId(), iObj.getName(), iObj.getAlias(), iObj.getSequence(), iObj.getApplication(), iObj.getDescription()) & sqlSession->executeUpdate(sql_str.back(), "%s%s%s%b%s%dt%dt%s%s%s%s%d%s%dt", iObj.getItemId(), iObj.getSequence(), iObj.getApplication(), iObj.getBoolValue(), iObj.getId(), iObj.getDateTimeValue(), iObj.getDateValue(), iObj.getItemCategory(), iObj.getItemPrimitiveType(), iObj.getItemStringValueType(), iObj.getItemType(), iObj.getNumberValue(), iObj.getData(), iObj.getTimeValue());
}

bool DataOpDAO::update(const DataOpDO& uObj) {
	string sql = "UPDATE `pp_e_applicationdict` SET `xname`=?, `xalias`=?, `xdescription`=? , `xupdateTime`=NOW() WHERE `xid`=?";
	auto res = sqlSession->executeUpdate(sql, "%s%s%s%s", uObj.getName(), uObj.getAlias(), uObj.getDescription(), uObj.getId());
	sql = "UPDATE `pp_e_applicationdictitem` SET `xbooleanValue`=?,`xdateTimeValue`=?,`xdateValue`=?,`xitemCategory`=?,`xitemPrimitiveType`=?,`xitemStringValueType`=?,`xitemType`=?,`xnumberValue`=?,`xstringLongValue`=?,`xtimeValue`= ?,`xupdateTime`=NOW() WHERE `xbundle`=?";
	res += sqlSession->executeUpdate(sql, "%b%dt%dt%s%s%s%s%d%s%dt%s",uObj.getBoolValue(),uObj.getDateTimeValue(),uObj.getDateValue(),uObj.getItemCategory(),uObj.getItemPrimitiveType(),uObj.getItemStringValueType(),uObj.getItemType(),uObj.getNumberValue(),uObj.getData(),uObj.getTimeValue(),uObj.getId());
	return res;
}

bool DataOpDAO::deleteById(const string& id) {
	string sql1 = "DELETE FROM `pp_e_applicationdictitem` WHERE `xbundle`= ?";
	string sql2 = "DELETE FROM `pp_e_applicationdict` WHERE `xid`=?";
	return sqlSession->executeUpdate(sql1, "%s", id) | sqlSession->executeUpdate(sql2, "%s", id);
}