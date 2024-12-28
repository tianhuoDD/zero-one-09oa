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
#include "AcceptUserListDAO.h"
#include "AcceptUserListMapper.h"


//定义条件解析宏，减少重复代码
#define ACCEPT_USER_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->xid) {\
	sql << " AND o.xid=?"; \
	SQLPARAMS_PUSH(params, "s", string, query->xid.getValue("")); \
}
//用户的统计数据条数和分页查询数据

uint64_t AcceptUserListDAO::user_count(const AcceptUserListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM file_attachment_editorlist f JOIN org_person o ON f.xeditorList = o.xdistinguishedName";
	ACCEPT_USER_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}


std::list<file_attachment_editorlistDO> AcceptUserListDAO::user_selectWithPage(const AcceptUserListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "WITH t AS (SELECT fa.xperson,fe.ATTACHMENT_XID,fe.xeditorlist FROM file_attachment fa JOIN file_attachment_editorlist fe ON fa.xid = fe.ATTACHMENT_XID) SELECT t.ATTACHMENT_XID, t.xperson FROM t JOIN org_person o ON t.xeditorlist = o.xdistinguishedName";
	ACCEPT_USER_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	AcceptUserListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<file_attachment_editorlistDO, AcceptUserListMapper>(sqlStr, mapper, params);
}
