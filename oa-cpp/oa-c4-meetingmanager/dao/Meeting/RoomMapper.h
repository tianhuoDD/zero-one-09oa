#pragma once
#ifndef _ROOM_MAPPER_
#define _ROOM_MAPPER_
#include "Mapper.h"
#include "domain/do/room-new/RoomDO.h"
class RoomMapper : Mapper<RoomDO> {
public:
	RoomDO mapper(ResultSet* resultSet)const override {
		RoomDO data;
		data.setBuildId(resultSet->getString(1));
		
		data.setRoomName(resultSet->getString(2));
		return data;
	}
};
#endif // !_ROOM_MAPPER_
