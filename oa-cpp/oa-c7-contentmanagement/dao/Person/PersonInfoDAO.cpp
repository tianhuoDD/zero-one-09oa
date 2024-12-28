


/*
 Copyright Zero One Star. All rights reserved.

 @Author: Rif 
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
#include "./PersonInfoMapper.h"
#include "./PersonInfoDAO.h"
#include <sstream>

//�������������꣬�����ظ�����
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->xname) { \
	sql << " AND `xname`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xname.getValue("")); \
} \

std::list<PersonInfoDO> PersonInfoDAO::selectWithPage(const PersonQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT xid,xname FROM org_person";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	PersonInfoMapper mapper;
	string sqlStr = sql.str();
	std::cout << sqlStr << std::endl;
	return sqlSession->executeQuery<PersonInfoDO, PersonInfoMapper>(sqlStr, mapper, params);
}

uint64_t PersonInfoDAO::count(const PersonQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `org_person`";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}



