#pragma once
#ifndef _ROOMPOSSERVICE_H_
#define _ROOMPOSSERVICE_H_
#include "domain/do/room-new/RoomPosDO.h"
#include "domain/dto/room-new/RoomInfoDTO.h"
#include "domain/vo/room-new/RoomInfoVO.h"


class RoomPosService {
public:
	bool updatePos(const RoomInfoVO::Wrapper& dto);
	//bool updatePos(const std::string& xname);
	bool removePos(const string& xid);

};



#endif
