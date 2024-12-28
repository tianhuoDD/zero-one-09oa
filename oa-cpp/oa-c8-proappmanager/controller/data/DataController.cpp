#include"stdafx.h"
#include"DataController.h"
#include"service/data/DataListService.h"
#include"service/data/DataDetailService.h"
#include "../ApiDeclarativeServicesHelper.h"

StringJsonVO::Wrapper DataController::execAddDataConfiguration(const AddDataDTO::Wrapper& dto) {
	//����һ��stringjsonVO
	auto res = StringJsonVO::createShared();

	//���������������ֺͱ����ļ���
	if (dto->name == nullptr || dto->alias == nullptr || dto->application == nullptr || dto->name->empty() || dto->alias->empty() || dto->application->empty() || dto->application == " ") {
		res->init(String(ZH_WORDS_GETTER("oprator.error.put")), RS_PARAMS_INVALID);
		return res;
	}
	if (dto->datetimevalue != nullptr && dto->datetimevalue->empty()) {
		res->init(String("datetimevalue is empty!"), RS_PARAMS_INVALID);
		return res;
	}

	DataOpService service;
	auto resStr = service.addData(dto);
	if (!resStr.empty()) {
		res->success(String(resStr));
	} else {
		res->fail(String("AddData failed."));
	}
	return res;
}

StringJsonVO::Wrapper DataController::execModifyDataConfiguration(const DataOperatorDTO::Wrapper& dto) {
	auto res = StringJsonVO::createShared();
	String id = dto->id;
	//��������У��
	if (dto->id == nullptr || id->empty() || id == "0" || (id->at(0) == '-')) {
		res->init(String(ZH_WORDS_GETTER("oprator.error.put")), RS_PARAMS_INVALID);
		return res;
	}

	DataOpService service;
	if (service.updateData(dto)) {
		res->success(dto->id);
	} else {
		res->fail(dto->id);
	}

	return res;
}

StringJsonVO::Wrapper DataController::execDeleteDataConfiguration(const String& id) {
	//ɾ�����ݽӿ�ʵ��
	auto res = StringJsonVO::createShared();
	if (id->empty() || id == "0" || (id->at(0) == '-')) {
		res->init(String(ZH_WORDS_GETTER("oprator.error.put")), RS_PARAMS_INVALID);
		return res;
	}
	DataOpService service;
	if (service.removeData(id)) {
		res->success(id);
	} else {
		res->fail(id);
	}
	return res;
}

DataListPageJsonVO::Wrapper DataController::execQueryDataConfigList(const DataListQuery::Wrapper& query, const PayloadDTO& payload) {
	// �������ض���
	auto jvo = DataListPageJsonVO::createShared();

	// �������Ƿ���Ч
	if (query->appid->empty()) {
		jvo->init(DataListPageDTO::createShared(), RS_PARAMS_INVALID);
		return jvo;
	}
	// ���÷��񷽷�
	DataListService service;
	auto result = service.listAll(query);
	jvo->success(result);

	return jvo;

}

DataDetailJsonVO::Wrapper DataController::execQueryDataConfigDetail(const std::string& dataid, const PayloadDTO& payload) {
	// �������ض���
	auto jvo = DataDetailJsonVO::createShared();

	// ����ѯ�����Ƿ���Ч
	if (dataid.empty()) {
		jvo->init(DataDetailDTO::createShared(), RS_PARAMS_INVALID);
		return jvo;
	}
	// ���÷��񷽷�
	DataDetailService service;
	auto result = service.listOne(dataid);
	jvo->success(result);
	return jvo;
}
