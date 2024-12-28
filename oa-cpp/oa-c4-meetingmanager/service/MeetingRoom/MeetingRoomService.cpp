/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "MeetingRoomService.h"
#include "../../dao/MeetingRoom/MeetingRoomDAO.h"
using namespace oatpp;


bool MeetingRoomService::updateData(const MeetingroomDTO::Wrapper& dto)
{
	// 组装DO数据
	MeetingRoomDO data;
	vector<string>dev;
	for (auto& iter : *dto->device) {
		dev.push_back(iter);
	}
	data.setDevice(dev);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id,id,Name, name, Location, location, Floor, floor, Capacity, capacity,Housenumber,housenumber,Extnumber,extnumber,Status,status)
		// 执行数据修改
	MeetingRoomDAO dao;
	return dao.update(data) == 1;
}

bool MeetingRoomService::removeData(const string& name)
{
	MeetingRoomDAO dao;
	return dao.deleteByName(name) == 1;
}
