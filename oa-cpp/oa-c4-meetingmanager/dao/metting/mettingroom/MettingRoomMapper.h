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
#include "../../../domain/do/metting/mettingroom/MettingRoomDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class MettingRoomMapper : public Mapper<MettingRoomDO>
{
public:
	MettingRoomDO mapper(ResultSet* resultSet) const override
	{
		MettingRoomDO data;
		data.setIds(resultSet->getString(1));
		data.setNames(resultSet->getString(12));
		data.setBuild(resultSet->getString(8));
		data.setFloor(resultSet->getInt(11));
		data.setcapacity(resultSet->getInt(9));
		data.setRoomnumber(resultSet->getString(17));
		data.setDis(resultSet->getInt(5));
		data.setDevice(resultSet->getString(10));
		data.setAvailable(resultSet->getBlob(7));
		return data;
	}
};

class MettingBuildMapper : public Mapper<MettingBuildDO>
{
public:
	MettingBuildDO mapper(ResultSet* resultSet) const override
	{
		MettingBuildDO data;
		data.setBuild(resultSet->getString(1));
		return data;
	}
};

#endif // !_MettingRoom_MAPPER_