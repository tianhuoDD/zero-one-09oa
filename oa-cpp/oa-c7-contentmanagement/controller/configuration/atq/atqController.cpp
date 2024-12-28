#include "stdafx.h"
#include "atqController.h"
#include "../../../service/configuration/atq/ConfigurationService.h"
#include "../../ApiDeclarativeServicesHelper.h"

ConfigurationPageJsonVO::Wrapper atqController::execucateconfigquery(const String& logo) {

	// 定义一个Service
	ConfigurationService service;
	// 查询数据
	auto result = service.listAll(logo);
	// 响应结果
	auto jvo = ConfigurationPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper atqController::execucatemodify(const ConfigurationDTO::Wrapper& dto)
{
	auto jvo = StringJsonVO::createShared();
	//参数校验
	//范围校验

	//定义一个Service
	ConfigurationService service;
	//执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->xappId);
	}
	else {
		jvo->fail(dto->xappId);
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper atqController::execucateadd(const ConfigurationDTO::Wrapper& dto)
{
	// 定义返回数据对象
	//auto jvo = StringJsonVO::createShared();
	auto jvo = Uint64JsonVO::createShared();
	//参数校验
	//非空校验
	if (!dto->xappId || !dto->xdocumentType ||!dto->process||!dto->range||!dto->xcreatorPerson||!dto->xmanagePerson) {
		jvo->init(-1, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ConfigurationService service;
	// 执行数据新增
	int id = service.saveData(dto);
	if (id>0) {
		jvo->success(int(id));
	}
	else {
		jvo->fail(int(id));
	}
	//响应结果
	return jvo;
}



Uint64JsonVO::Wrapper atqController::execRemoveConfiguration(const String& logo)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	ConfigurationService service;
	auto result = service.removeData(logo);

	// 响应结果
	jvo->success(result);
	return jvo;
}