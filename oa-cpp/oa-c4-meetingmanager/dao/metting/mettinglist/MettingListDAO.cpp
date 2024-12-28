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
#include "MettingListDAO.h"
#include "MettingListMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; 

uint64_t MettingListDAO::count(const MettingListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM mt_meeting";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<MettingListDO> MettingListDAO::selectWithPage(const MettingListQuery::Wrapper& query)
{
	stringstream sql;
	if (query->mtinvite)
	{
		if (query->reject) // reject
		{
			sql << "SELECT xapplicant,xcreateTime,xstartTime,xcompletedTime,xsubject,xroom FROM mt_meeting JOIN mt_meeting_rejectpersonlist ON mt_meeting.xid = mt_meeting_rejectpersonlist.MEETING_XID WHERE xrejectPersonList LIKE '%" << query->name.getValue("") <<  "%' ";
			SAMPLE_TERAM_PARSE(query, sql);
			sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
			MettingListMapper mapper;
			string sqlStr = sql.str();
			return sqlSession->executeQuery<MettingListDO, MettingListMapper>(sqlStr, mapper, params);
		}
		else // unreject
		{
			if (query->time == 1) { // unstart
				sql << "SELECT xapplicant,xcreateTime,xstartTime,xcompletedTime,xsubject,xroom FROM mt_meeting JOIN mt_meeting_invitepersonlist ON mt_meeting.xid = mt_meeting_invitepersonlist.MEETING_XID WHERE xstartTime > NOW() AND xinvitePersonList LIKE '%" << query->name.getValue("") << "%'";
				SAMPLE_TERAM_PARSE(query, sql);
				sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
				MettingListMapper mapper;
				string sqlStr = sql.str();
				return sqlSession->executeQuery<MettingListDO, MettingListMapper>(sqlStr, mapper, params);
			}
			else if (query->time == 2) { // meeting
				sql << "SELECT xapplicant,xcreateTime,xstartTime,xcompletedTime,xsubject,xroom FROM mt_meeting JOIN mt_meeting_invitepersonlist ON mt_meeting.xid = mt_meeting_invitepersonlist.MEETING_XID WHERE xstartTime < NOW() AND xcompletedTime > NOW() AND xinvitePersonList LIKE '%" << query->name.getValue("") << "%' ";
				SAMPLE_TERAM_PARSE(query, sql);
				sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
				MettingListMapper mapper;
				string sqlStr = sql.str();
				return sqlSession->executeQuery<MettingListDO, MettingListMapper>(sqlStr, mapper, params);
			}
			else if (query->time == 3) { // over 
				sql << "SELECT xapplicant,xcreateTime,xstartTime,xcompletedTime,xsubject,xroom FROM mt_meeting JOIN mt_meeting_invitepersonlist ON mt_meeting.xid = mt_meeting_invitepersonlist.MEETING_XID WHERE xcompletedTime < NOW() AND xinvitePersonList LIKE '%" << query->name.getValue("") << "%' ";
				SAMPLE_TERAM_PARSE(query, sql);
				sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
				MettingListMapper mapper;
				string sqlStr = sql.str();
				return sqlSession->executeQuery<MettingListDO, MettingListMapper>(sqlStr, mapper, params);
			}
		}
	}
	else if(!query->mtinvite) //if(!query->reject && !query->mtinvite)
	{
		if (query->time == 1) { // unstart
			sql << "SELECT xapplicant,xcreateTime,xstartTime,xcompletedTime,xsubject,xroom FROM mt_meeting WHERE xstartTime > NOW() AND xapplicant LIKE '%" << query->name.getValue("") << "%' ";
			SAMPLE_TERAM_PARSE(query, sql);
			sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
			MettingListMapper mapper;
			string sqlStr = sql.str();
			return sqlSession->executeQuery<MettingListDO, MettingListMapper>(sqlStr, mapper, params);
		}
		else if (query->time == 2){ // meeting
			sql << "SELECT xapplicant,xcreateTime,xstartTime,xcompletedTime,xsubject,xroom FROM mt_meeting WHERE xstartTime < NOW() AND xcompletedTime > NOW()  AND xapplicant LIKE '%" << query->name.getValue("") << "%' ";
			SAMPLE_TERAM_PARSE(query, sql);
			sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
			MettingListMapper mapper;
			string sqlStr = sql.str();
			return sqlSession->executeQuery<MettingListDO, MettingListMapper>(sqlStr, mapper, params);
		}
		else if (query->time == 3){ // over
			sql << "SELECT xapplicant,xcreateTime,xstartTime,xcompletedTime,xsubject,xroom FROM mt_meeting WHERE xcompletedTime < NOW()  AND xapplicant LIKE '%" << query->name.getValue("") << "%' ";
			SAMPLE_TERAM_PARSE(query, sql);
			sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
			MettingListMapper mapper;
			string sqlStr = sql.str();
			return sqlSession->executeQuery<MettingListDO, MettingListMapper>(sqlStr, mapper, params);
		}
	}
	
}
