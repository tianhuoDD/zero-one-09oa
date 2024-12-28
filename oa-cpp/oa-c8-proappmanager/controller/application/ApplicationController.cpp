#include "stdafx.h"
#include "domain/vo/application/ApplicationPageVO.h"
#include "controller/application/ApplicationController.h"
#include "service/application/ApplicationService.h"


ApplicationPageJsonVO::Wrapper ApplicationController::execQueryApplication(const ApplicationQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = ApplicationPageJsonVO::createShared();
	ApplicationService service;
	auto result = service.listAllApplication(query);
	if (result->rows.get()->size() == 0)
	{
		jvo->fail(result);
	}
	else {
		jvo->success(result);
	}

	return jvo;
}

ApplicationIdJsonVO::Wrapper ApplicationController::execAddApplication(const AddApplicationDTO::Wrapper& one_application, const PayloadDTO& payload)
{
	//非空校验
	auto jvo = ApplicationIdJsonVO::createShared();
	if (one_application->xname == nullptr || !one_application->xname)
	{
		auto data = ApplicationIdDTO::createShared();
		data->id = "";
		jvo->init(data, RS_PARAMS_INVALID);
		return jvo;
	}
	ApplicationService service;
	// 获取表中所有应用的名称
	std::list<std::string> names = service.listAllApplicationName();
	// 判断one_application->xname
	auto it = find(names.begin(), names.end(), one_application->xname.getValue(""));
	if (it != names.end())
	{
		auto data = ApplicationIdDTO::createShared();
		data->id = "";
		//应用名称非重复校验
		jvo->fail(data);
		return jvo;
		
	}
	else
	{
		auto result = service.insertApplication(one_application, payload);
		jvo->success(result);
	}
	return jvo;
}

ApplicationIdJsonVO::Wrapper ApplicationController::execRemoveApplication(const oatpp::String id, const PayloadDTO& payload)
{
	auto jvo = ApplicationIdJsonVO::createShared();
	if (!id.get())
	{
		auto data = ApplicationIdDTO::createShared();
		data->id = "";
		jvo->init(data, RS_PARAMS_INVALID);
		return jvo;
	}
	ApplicationService service;
	auto result = service.removeApplication(id.getValue({}));
	if (result->id) {
		jvo->success(result);
	}
	else {
		jvo->fail(result);
	}
	return jvo;
}

ApplicationTypesListJsonVO::Wrapper ApplicationController::execQueryAppTypes() {
	ApplicationService service;
	auto result = service.listAppTypes();
	auto jvo = ApplicationTypesListJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

ApplicationPropertiesJsonVO::Wrapper ApplicationController::execQueryAppProperties(const String& id, const PayloadDTO& payload) {
	ApplicationService service;
	auto result = service.listAppProperties(id);
	auto jvo = ApplicationPropertiesJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper ApplicationController::execModifyAppProperties(const ApplicationPropertiesDTO::Wrapper& dto, const PayloadDTO& payload) {
	if (dto->xid == nullptr || dto->xid->empty()) {
		auto jvo = Uint64JsonVO::createShared();
		jvo->fail(UInt64(-1));
		return jvo;
	}
	ApplicationService service;
	bool result = service.modifyAppProperties(dto, payload);
	auto jvo = Uint64JsonVO::createShared();
	if (result) {
		jvo->success(UInt64(1));
	} else {
		jvo->fail(UInt64(-1));
	}
	return jvo;
}
