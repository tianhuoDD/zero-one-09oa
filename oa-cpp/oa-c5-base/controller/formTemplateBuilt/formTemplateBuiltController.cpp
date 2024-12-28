#include "stdafx.h"
#include "formTemplateBuiltController.h"
#include"../../service/formTemplate/built/formTemplateBuiltService.h"



Uint64JsonVO::Wrapper formTemplateBuiltController::executeAddformTemplateBuilt(const formTemplateBuiltDTO::Wrapper& dto)
{
	
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->xsequence || !dto->xdescription || !dto->xalias || !dto->xcategory || !dto->xdata || !dto->xdescription || !dto->xicon || !dto->xmobileData || !dto->xname || !dto->xoutline)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->xsequence->empty() || dto->xdescription->empty() || dto->xalias->empty() || dto->xcategory->empty() || dto->xdata->empty() || dto->xdescription->empty() || dto->xicon->empty() || dto->xmobileData->empty() || dto->xname->empty() || dto->xoutline->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	formTemplateBuiltService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}

Uint64JsonVO::Wrapper formTemplateBuiltController::executeremoveformTemplateBuilt(const UInt64& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	formTemplateBuiltService service;
	// 执行数据删除
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}
