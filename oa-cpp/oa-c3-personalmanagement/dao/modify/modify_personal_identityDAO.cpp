/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/23 1:05:55

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
#include "modify_personal_identityDAO.h"
#include "modify_personal_identityMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->xid) { \
	sql << " AND `xid`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xid.getValue(" ")); \
} \
if (query->xname) { \
	sql << " AND xname=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xname.getValue(" ")); \
} \
if (query->xmajor) { \
	sql << " AND xmajor=?"; \
	SQLPARAMS_PUSH(params, "b", std::bool, query->xmajor.getValue(" ")); \
}


int modify_personal_identityDAO::update(const org_identitypersonDO & uObj)
{
	string sql = "UPDATE `org_identity` SET `xname`=?, `xmajor`=? WHERE `xid`=?";
	return  sqlSession->executeUpdate(sql, "%s%b%s", uObj.getXname(), uObj.getXmajor(), uObj.getXid());
	
}

