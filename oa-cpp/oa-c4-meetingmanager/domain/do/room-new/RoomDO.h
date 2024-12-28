#pragma once
#ifndef _ROOM_DO_
#define _ROOM_DO_
#include "../DoInclude.h"
class RoomDO {
	
	
	
	//会议室名称
	CC_SYNTHESIZE(string, roomName, RoomName);
	
	
	//会议室位置ID
	CC_SYNTHESIZE(string, buildId, BuildId);
public:
	RoomDO() : roomName(""), buildId(""){}
};
#endif // !_ROOM_DO_
