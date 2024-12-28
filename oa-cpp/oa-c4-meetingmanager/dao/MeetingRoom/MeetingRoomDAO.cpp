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
#include "MeetingRoomDAO.h"
#include <sstream>
#include "../../domain/GlobalInclude.h"


int MeetingRoomDAO::update(const MeetingRoomDO& uObj)
{
	//建立用户和数据库字段映射
	unordered_map<string, string>umap;
	umap[ZH_WORDS_GETTER("meetingroom.device1")] = "projector";
	umap[ZH_WORDS_GETTER("meetingroom.device2")] = "board";
	umap[ZH_WORDS_GETTER("meetingroom.device3")] = "tvset";
	umap[ZH_WORDS_GETTER("meetingroom.device4")] = "tv";
	umap[ZH_WORDS_GETTER("meetingroom.device5")] = "camera";
	umap[ZH_WORDS_GETTER("meetingroom.device6")] = "wifi";
	umap[ZH_WORDS_GETTER("meetingroom.device7")] = "phone";
	//把设备字段转换为字符串
	string xdevice;
	for (auto& iter : uObj.getDevice()) {
		if (!xdevice.empty()) {
			xdevice += "#";
		}
		xdevice += umap[iter];
	}
	//执行修改会议室sql语句：sql2——修改设备，sql3——修改位置，sql1——修改其它字段。
	string sql2 = "UPDATE `mt_room` SET `xdevice`=? WHERE `xid`=?;";
	int c2 = sqlSession->executeUpdate(sql2, "%s%s", xdevice, uObj.getId());
	string sql1 = "UPDATE `mt_room` SET `xname`=?,`xpinyin`=?, `xpinyinInitial`=?,`xfloor`=?,`xcapacity`=?, `xroomNumber`=?, `xphoneNumber`=?, `xavailable`=? WHERE `xid`=?";
	int c1 = sqlSession->executeUpdate(sql1, "%s%s%s%ull%ull%s%s%b%s", uObj.getName(), uObj.getName(), uObj.getName(), uObj.getFloor(), uObj.getCapacity(), uObj.getHousenumber(), uObj.getExtnumber(), uObj.getStatus(), uObj.getId());
	string sql3 = "UPDATE `mt_building` SET `xname`=?,`xpinyin`=?,`xpinyinInitial`=? WHERE `xid`=(select `xbuilding` from `mt_room` where `xid`=?);";
	int c3 = sqlSession->executeUpdate(sql3, "%s%s%s%s", uObj.getLocation(), uObj.getLocation(), uObj.getLocation(), uObj.getId());
	return (c1 + c2 + c3);
}

int MeetingRoomDAO::deleteByName(string name)
{
	//执行会议室删除语句。
	string sql = "DELETE FROM `mt_room` WHERE `xname`=?";
	return sqlSession->executeUpdate(sql, "%s", name);
}