#include "stdafx.h"
#include "ProcessController.h"
#include "service/process/ProcessService.h"

ProcessTypesListJsonVO::Wrapper ProcessController::execQueryProcessTypes(const String& appId) {
	auto jvo = ProcessTypesListJsonVO::createShared();
	if (appId == nullptr || appId->empty()) {
		//jvo->fail("appId不能为空");
		return jvo;

	}
	ProcessService service;
	auto result = service.listTypes(appId);
	jvo->success(result);
	return jvo;
}

ProcessListPageJsonVO::Wrapper ProcessController::execQueryProcessList(const ProcessListQuery::Wrapper& query, const PayloadDTO& payload) {
	if (query->application == nullptr || query->application->empty()) {
		auto jvo = ProcessListPageJsonVO::createShared();
		jvo->init(ProcessListPageDTO::createShared(), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个service
	ProcessService service;
	// 查询数据
	auto result = service.listProcess(query);
	// 响应结果
	auto jvo = ProcessListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

ProcessInfoJsonVO::Wrapper ProcessController::execQueryProcessInfo(const String& id) {
	// 数据校验
	auto jvo = ProcessInfoJsonVO::createShared();
	if (id == nullptr || id->empty()) {
		//jvo->fail("id empty");
		return jvo;
	}
	// 定义一个service
	ProcessService service;
	// 查询数据
	auto result = service.queryProcessInfo(id);
	// 响应结果
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper ProcessController::AddProcess(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto res = StringJsonVO::createShared();

	//流程数据配置名字和别名的检验
	if (dto->alias == nullptr || dto->application == nullptr || dto->alias->empty() || dto->application->empty()) {
		res->init(String(ZH_WORDS_GETTER("process.setting.get.summary")), RS_PARAMS_INVALID);
		return res;
	}

	ProcessService service;
	string id = service.insertProcess(dto, payload);
	if (!id.empty()) {
		res->success(String(id));
	} else {
		res->fail(String(id));
	}


	return res;
}

StringJsonVO::Wrapper ProcessController::ModifyProcess(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto res = StringJsonVO::createShared();
	String id = dto->id;
	//进行数据校验
	if (dto->id == nullptr || dto->id->empty()) {
		res->init(String(ZH_WORDS_GETTER("process.setting.put.summary")), RS_PARAMS_INVALID);
		return res;
	}

	//进行数据类型校验校验
	ProcessService service;
	if (service.updateProcess(dto, payload)) {
		res->success(dto->id);
	} else {
		res->fail(dto->id);
	}

	return res;
}

StringJsonVO::Wrapper ProcessController::DeleteProcess(const String id) {
	auto res = StringJsonVO::createShared();
	if (id->empty() || id == "0" || (id->at(0) == '-')) {
		res->init(String(ZH_WORDS_GETTER("process.setting.delete.summary")), RS_PARAMS_INVALID);
		return res;
	}


	ProcessService service;
	if (service.deleteProcess(id)) {
		res->success(id);
	} else {
		res->fail(id);
	}
	return res;
}
