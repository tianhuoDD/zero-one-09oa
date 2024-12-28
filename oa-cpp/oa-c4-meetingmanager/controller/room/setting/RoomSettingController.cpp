#include "stdafx.h"
#include "RoomSettingController.h"
#include "../../../service/room/RoomPosService.h"


StringJsonVO::Wrapper RoomSettingController::execModifyRoomInfo_DTO(const RoomInfoVO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();

	// ����У��
	if (!dto->id)
	{
		jvo->init(String(""), RS_PARAMS_INVALID);
		return jvo;
	}

	RoomPosService service;
	if (service.updatePos(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	
	return jvo;
}

//StringJsonVO::Wrapper RoomSettingController::execModifyRoomInfo_NAME(const std::string& xname)
//{
//	auto jvo = StringJsonVO::createShared();
//	if (xname == "") {
//		jvo->init(String("-1"), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ����һ��Service
//	RoomPosService service;
//	// ִ������ɾ��
//	if (service.updatePos(xname)) {
//		jvo->success(xname);
//	}
//	else
//	{
//		jvo->fail(xname);
//	}
//	// ��Ӧ���
//	return jvo;
//}

//StringJsonVO::Wrapper RoomSettingController::execDeleteRoomInfo(const string& xname)
//{
//	// ���巵�����ݶ���
//	auto jvo = StringJsonVO::createShared();
//	// ����У��
//	if (xname=="" )
//	{
//		jvo->init(String("-1"), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ����һ��Service
//	RoomPosService service;
//	// ִ������ɾ��
//	if (service.removePos(xname)) {
//		jvo->success(xname);
//	}
//	else
//	{
//		jvo->fail(xname);
//	}
//	// ��Ӧ���
//	return jvo;
//}

StringJsonVO::Wrapper RoomSettingController::execDeleteRoomInfo(const string& xid)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (xid == "")
	{
		jvo->init(String("-1"), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	RoomPosService service;
	// ִ������ɾ��
	if (service.removePos(xid)) {
		jvo->success(xid);
	}
	else
	{
		jvo->fail(xid);
	}
	// ��Ӧ���
	return jvo;
}