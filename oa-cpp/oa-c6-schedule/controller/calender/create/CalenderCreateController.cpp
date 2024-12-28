#include "stdafx.h"
#include "CalenderCreateController.h"
#include "../../../service/calendar/CalenderService.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include <iostream>

CalenderInfoJsonVo::Wrapper CalenderCreateController::executeModifyCalenderInfo(const CalenderInfoDTO::Wrapper& dto, const string& loaddisName)
{
	// 定义返回数据对象
	auto jvo = CalenderInfoJsonVo::createShared();
	// 参数校验
	// 非空校验
	if (dto->xname->empty())    //日历名称为空   -4
	{
		jvo->init(RS_CALENDERNAME_FAIL);
		return jvo;
	}
	else if ("UNIT" == (string)(dto->xtype) && dto->xtarget->empty())  //所属组织为空  -2
	{
		jvo->init( RS_CALENDERXTARGETRMPTY_FAIL);
		return jvo;
	}
	// 有效值校验
	if (dto->xdescription->size() > 255)  //备注过长  -3
	{
		jvo->init(RS_CALENDERDESCRIPTION_FAIL);
		return jvo;
	}

	// 定义一个Service
	CalenderService service;
	// 执行数据修改
	uint64_t result = service.updateData(dto, loaddisName);
	if (88 == result) {
		jvo->fail(UInt64(result));
	}
	else if (result)
	{
		jvo->success();
	}
	else
		jvo->fail(-1);
	// 响应结果
	return jvo;
}

CalenderInfoJsonVo::Wrapper CalenderCreateController::execAddCalender(const CalenderInfoDTO::Wrapper& dto, const string& loaddisName)
{
	// 定义返回数据对象
	auto jvo = CalenderInfoJsonVo::createShared();
	// 参数校验
	// 非空校验
	if (dto->xname->empty())    //日历名称为空   -4
	{
		jvo->init(RS_CALENDERNAME_FAIL);
		return jvo;
	}
	else if ("UNIT" == (string)(dto->xtype) && dto->xtarget->empty())  //所属组织为空  -2
	{
		jvo->init(RS_CALENDERXTARGETRMPTY_FAIL);
		return jvo;
	}
	// 有效值校验
	if (dto->xdescription->size() > 255)  //备注过长  -3
	{
		jvo->init(RS_CALENDERDESCRIPTION_FAIL);
		return jvo;
	}

	// 定义一个Service
	CalenderService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto, loaddisName);
	std::cout << id << std::endl;
	if (88 == id)
	{
		jvo->fail(UInt64(id));
	}
	else if (id > 0) {
		jvo->success();
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}

Uint64JsonVO::Wrapper CalenderCreateController::execRemoveCalender(const String& xid)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (xid->empty())  //xid为空
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	CalenderService service;
	// 执行数据删除
	if (service.removeData(xid)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(-1);
	}
	// 响应结果
	return jvo;
}
