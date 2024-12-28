#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#ifndef _MettingRoom_MAPPER_
#define _MettingRoom_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/metting/mettingroomlist/MettingRoomListDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class MettingRoomListMapper : public Mapper<MettingRoomListDO>
{
public:
	MettingRoomListDO mapper(ResultSet* resultSet) const override
	{
		MettingRoomListDO data;
		data.setIds(resultSet->getString(1));
		data.setNames(resultSet->getString(8));
		data.setBuild(resultSet->getString(4));
		data.setFloor(resultSet->getInt(7));
		data.setcapacity(resultSet->getInt(5));
		data.setRoomnumber(resultSet->getString(9));
		data.setDis(resultSet->getInt(2));
		data.setDevice(resultSet->getString(6));
		data.setAvailable(resultSet->getBlob(3));
		data.setMeetings(resultSet->getString(10));
		return data;
	}
};



#endif // !_MettingRoomList_MAPPER_