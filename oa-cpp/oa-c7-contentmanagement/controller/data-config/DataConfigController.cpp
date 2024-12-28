#include "stdafx.h"
#include"DataConfigController.h"
#include "../../service/data-config/DataConfigService.h"
#include "../ApiDeclarativeServicesHelper.h"

DataConfigJsonVO::Wrapper DataConfigController::execQueryDataConfig(const String& id) {
	// 定义一个Service
	DataConfigService service;
	// 查询数据
	auto result = service.queryByXid(id);
	// 响应结果
	auto jvo = DataConfigJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper DataConfigController::execAddDataConfig(const AddDataConfigDTO::Wrapper& dto) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->xname || !dto->xalias)
	{
		jvo->init("NULL", RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	DataConfigService service;
	// 执行数据新增
	string id = service.saveData(dto);
	if(id!="") {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	//响应结果
	return jvo;
}

StringJsonVO::Wrapper DataConfigController::execModifyDataConfig(const ModifyDataConfigDTO::Wrapper& dto) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->xid)
	{
		jvo->init("NULL", RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	DataConfigService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->xid);
	}
	else
	{
		jvo->fail(dto->xid);
	}
	// 响应结果
	return jvo;
}