#include "stdafx.h"
#include "RoomPosService.h"
#include "../../dao/room/RoomPosDAO.h"



bool RoomPosService::updatePos(const RoomInfoVO::Wrapper& dto)
{
	RoomBuildingDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto , \
		Xid,id,Xname,name, Xaddress,address,Xpinyin,xpinyin, Xpinyinintial, xpinyinintial);
	RoomPosDAO dao;

	return dao.updateById(data) == 1;
	
}

//bool RoomPosService::updatePos(const std::string& xname)
//{
//	RoomPosDAO dao;
//	return dao.updateByName(xname) == 1;
//}

bool RoomPosService::removePos(const string& xid)
{
	RoomPosDAO dao;
	return dao.deleteById(xid) == 1;
}
