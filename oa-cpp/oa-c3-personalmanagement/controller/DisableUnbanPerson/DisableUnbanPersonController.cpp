#include "DisableUnbanPersonController.h"
#include "stdafx.h"
#include "../../service/DisableUnbanPerson/DisableUnbanPersonService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper DisableUnbanPersonController::execModifySample(const DisableUnbanPersonDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	/*if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/
	// 定义一个Service
	DisableUnbanPersonService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(2);
	}
	// 响应结果
	return jvo;
}
