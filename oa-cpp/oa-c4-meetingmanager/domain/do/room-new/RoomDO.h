#pragma once
#ifndef _ROOM_DO_
#define _ROOM_DO_
#include "../DoInclude.h"
class RoomDO {
	
	
	
	//����������
	CC_SYNTHESIZE(string, roomName, RoomName);
	
	
	//������λ��ID
	CC_SYNTHESIZE(string, buildId, BuildId);
public:
	RoomDO() : roomName(""), buildId(""){}
};
#endif // !_ROOM_DO_
