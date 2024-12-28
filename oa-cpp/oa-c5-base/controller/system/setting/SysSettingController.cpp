#include "stdafx.h"
#include "SysSettingController.h"
#include "service/SystemInfo/SystemInfoService.h"

StringJsonVO::Wrapper SysSettingController::executeModifySystemSubtitle(const SystemInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (dto->subtitle == nullptr)
	{
		jvo->init("error", RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	SystemInfoService service;
	// 执行删除消息
	if (service.modifySystemSubtitle(dto)) {
		jvo->success("success");
	}
	else
	{
		jvo->fail("fail");
	}
	// 响应结果
	return jvo;
}


StringJsonVO::Wrapper SysSettingController::executeModifySystemName(const SystemInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (dto->subtitle == nullptr)
	{
		jvo->init("error", RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	SystemInfoService service;
	// 执行删除消息
	if (service.modifySystemName(dto)) {
		jvo->success("success");
	}
	else
	{
		jvo->fail("fail");
	}
	// 响应结果
	return jvo;
}