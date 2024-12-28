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
#include "MeetingRoomSelectDAO.h"
#include "MeetingRoomSelectMapper.h"
#include <sstream>

// 定义条件解析宏，减少重复代码
#define MEETINGROOM_TERAM_PARSE(query, sql) \
SqlParams params; \
sql << " WHERE 1=1"; \
if (query->meetingRoomId) { \
    sql << " AND room_id=?"; \
    SQLPARAMS_PUSH(params, "ull", uint64_t, query->meetingRoomId.getValue(0)); \
} \
if (query->meetingRoomName) { \
    sql << " AND room_name LIKE CONCAT('%',?,'%')"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->meetingRoomName.getValue("")); \
} \
if (query->scheduledDateTime) { \
    sql << " AND scheduled_date_time=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->scheduledDateTime.getValue("")); \
} \
if (query->durationHours) { \
    sql << " AND duration_hours=?"; \
    SQLPARAMS_PUSH(params, "i", uint32_t, query->durationHours.getValue(0)); \
} \
if (query->durationMinutes) { \
    sql << " AND duration_minutes=?"; \
    SQLPARAMS_PUSH(params, "i", uint32_t, query->durationMinutes.getValue(0)); \
}

/**
 * 统计会议室记录数
 */
uint64_t MeetingRoomSelectDAO::count(const MeetingRoomSelectQuery::Wrapper& query)
{
    std::stringstream sql;
    sql << "SELECT COUNT(*) FROM meeting_room_select";
    MEETINGROOM_TERAM_PARSE(query, sql);
    std::string sqlStr = sql.str();
    return sqlSession->executeQueryNumerical(sqlStr, params);
}

/**
 * 分页查询会议室记录
 */
std::list<MeetingRoomSelectDO> MeetingRoomSelectDAO::selectWithPage(const MeetingRoomSelectQuery::Wrapper& query)
{
    std::stringstream sql;
    sql << "SELECT room_id, room_name, capacity, is_available FROM meeting_room_select";
    MEETINGROOM_TERAM_PARSE(query, sql);
    sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << ", " << query->pageSize;

    MeetingRoomSelectMapper mapper;
    std::string sqlStr = sql.str();
    return sqlSession->executeQuery<MeetingRoomSelectDO, MeetingRoomSelectMapper>(sqlStr, mapper, params);
}

/**
 * 根据会议室名称查询会议室
 */
std::list<MeetingRoomSelectDO> MeetingRoomSelectDAO::selectByRoomName(const std::string& roomName)
{
    std::string sql = "SELECT room_id, room_name, capacity, is_available FROM meeting_room_select WHERE room_name LIKE CONCAT('%',?,'%')";

    MeetingRoomSelectMapper mapper;
    return sqlSession->executeQuery<MeetingRoomSelectDO, MeetingRoomSelectMapper>(sql, mapper, "%s", roomName);
}

/**
 * 插入新的会议室记录
 */
uint64_t MeetingRoomSelectDAO::insert(const MeetingRoomSelectDO& iObj)
{
    std::string sql = "INSERT INTO meeting_room_select (room_name, capacity, is_available) VALUES (?, ?, ?)";

    return sqlSession->executeInsert(sql, "%s%i%b", iObj.getRoomName(), iObj.getCapacity(), iObj.getIsAvailable());
}

/**
 * 更新会议室记录
 */
int MeetingRoomSelectDAO::update(const MeetingRoomSelectDO& uObj)
{
    std::string sql = "UPDATE meeting_room_select SET room_name=?, capacity=?, is_available=? WHERE room_id=?";

    return sqlSession->executeUpdate(sql, "%s%i%b%ull", uObj.getRoomName(), uObj.getCapacity(), uObj.getIsAvailable(), uObj.getRoomId());
}

/**
 * 根据ID删除会议室记录
 */
int MeetingRoomSelectDAO::deleteById(uint64_t id)
{
    std::string sql = "DELETE FROM meeting_room_select WHERE room_id=?";

    return sqlSession->executeUpdate(sql, "%ull", id);
}
