#include "stdafx.h"
#include "RoomSettingController.h"
#include "../../../service/room/RoomPosService.h"


StringJsonVO::Wrapper RoomSettingController::execModifyRoomInfo_DTO(const RoomInfoVO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();

	// 参数校验
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
//	// 定义一个Service
//	RoomPosService service;
//	// 执行数据删除
//	if (service.updatePos(xname)) {
//		jvo->success(xname);
//	}
//	else
//	{
//		jvo->fail(xname);
//	}
//	// 响应结果
//	return jvo;
//}

//StringJsonVO::Wrapper RoomSettingController::execDeleteRoomInfo(const string& xname)
//{
//	// 定义返回数据对象
//	auto jvo = StringJsonVO::createShared();
//	// 参数校验
//	if (xname=="" )
//	{
//		jvo->init(String("-1"), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// 定义一个Service
//	RoomPosService service;
//	// 执行数据删除
//	if (service.removePos(xname)) {
//		jvo->success(xname);
//	}
//	else
//	{
//		jvo->fail(xname);
//	}
//	// 响应结果
//	return jvo;
//}

StringJsonVO::Wrapper RoomSettingController::execDeleteRoomInfo(const string& xid)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (xid == "")
	{
		jvo->init(String("-1"), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	RoomPosService service;
	// 执行数据删除
	if (service.removePos(xid)) {
		jvo->success(xid);
	}
	else
	{
		jvo->fail(xid);
	}
	// 响应结果
	return jvo;
}