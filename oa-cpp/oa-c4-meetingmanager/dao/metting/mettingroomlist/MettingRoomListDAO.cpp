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
#include "MettingRoomListDAO.h"
#include "MettingRoomListMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; 

uint64_t MettingRoomListDAO::count(const MettingRoomListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM mt_room";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<MettingRoomListDO> MettingRoomListDAO::selectWithPage(const MettingRoomListQuery::Wrapper& query)
{
	stringstream sql;
	if (query->date1.getValue("") == "" || query->time1.getValue("") == "")
	{
		sql << "SELECT mt_room.xid, mt_room.xdistributeFactor, xavailable, xbuilding, xcapacity, xdevice, xfloor, xname, xroomnumber,xsubject FROM mt_room JOIN mt_meeting ON mt_room.xname = mt_meeting.xroom WHERE"
			<< "xbuilding = '" << query->build.getValue("") << "' ";
	}
	else if (query->build.getValue("") == "")
	{
		sql << "SELECT mt_room.xid, mt_room.xdistributeFactor, xavailable, xbuilding, xcapacity, xdevice, xfloor, xname, xroomnumber,xsubject FROM mt_room JOIN mt_meeting ON mt_room.xname = mt_meeting.xroom WHERE ";
	}
	else
	{
		sql << "SELECT mt_room.xid, mt_room.xdistributeFactor, xavailable, xbuilding, xcapacity, xdevice, xfloor, xname, xroomnumber,xsubject FROM mt_room JOIN mt_meeting ON mt_room.xname = mt_meeting.xroom WHERE "
			<< "xbuilding = '" << query->build.getValue("") << "' "
			<< "AND NOW() < '" << query->date1.getValue("") << "' "
			<< "AND TIMESTAMPDIFF(HOUR, xstartTime, xcompletedTime) = " << query->time1.getValue("").substr(0, 2);
	}
		//<< "AND TIMESTAMPDIFF(MINUTE, xstartTime, xendTime) = " << query->time1.getValue("");
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	MettingRoomListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MettingRoomListDO, MettingRoomListMapper>(sqlStr, mapper, params);
}
