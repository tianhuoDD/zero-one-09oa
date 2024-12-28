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
#include "AcceptFileListDAO.h"
#include "AcceptFileListMapper.h"

//定义条件解析宏，减少重复代码
#define ACCEPT_FILE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1";\
if (query->xperson) { \
	sql << " AND f.xperson=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xperson.getValue("")); \
}\
if (query->xid) { \
	sql << " AND o.xid=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xid.getValue("")); \
}

//文件的统计数据条数和分页查询数据

uint64_t AcceptFileListDAO::file_count(const AcceptFileListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "WITH f AS (SELECT fa.xperson,fd.xeditorList FROM file_attachment fa JOIN file_attachment_editorlist fd ON fa.xid = fd.ATTACHMENT_XID)SELECT COUNT(*) FROM f JOIN org_person o ON f.xeditorList = o.xdistinguishedName";
	ACCEPT_FILE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}


std::list<file_attachmentDO> AcceptFileListDAO::file_selectWithPage(const AcceptFileListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "WITH f AS(SELECT fa.xname, fa.xperson, fa.xcreateTime, fa.xlastUpdateTime, fa.xlength, fe.xeditorList FROM file_attachment fa JOIN file_attachment_editorlist fe ON fa.xid = fe.ATTACHMENT_XID)SELECT f.xname, f.xperson, f.xcreateTime,f.xlastUpdateTime, f.xlength FROM f JOIN  org_person o ON f.xeditorList = o.xdistinguishedName";
	ACCEPT_FILE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	AcceptFileListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<file_attachmentDO, AcceptFileListMapper>(sqlStr, mapper, params);
}

