#include "stdafx.h"
#include "ProcessController.h"
#include "service/process/ProcessService.h"

ProcessTypesListJsonVO::Wrapper ProcessController::execQueryProcessTypes(const String& appId) {
	auto jvo = ProcessTypesListJsonVO::createShared();
	if (appId == nullptr || appId->empty()) {
		//jvo->fail("appId����Ϊ��");
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
	// ����һ��service
	ProcessService service;
	// ��ѯ����
	auto result = service.listProcess(query);
	// ��Ӧ���
	auto jvo = ProcessListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

ProcessInfoJsonVO::Wrapper ProcessController::execQueryProcessInfo(const String& id) {
	// ����У��
	auto jvo = ProcessInfoJsonVO::createShared();
	if (id == nullptr || id->empty()) {
		//jvo->fail("id empty");
		return jvo;
	}
	// ����һ��service
	ProcessService service;
	// ��ѯ����
	auto result = service.queryProcessInfo(id);
	// ��Ӧ���
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper ProcessController::AddProcess(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto res = StringJsonVO::createShared();

	//���������������ֺͱ����ļ���
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
	//��������У��
	if (dto->id == nullptr || dto->id->empty()) {
		res->init(String(ZH_WORDS_GETTER("process.setting.put.summary")), RS_PARAMS_INVALID);
		return res;
	}

	//������������У��У��
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
