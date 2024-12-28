#include "stdafx.h"
#include"DataConfigController.h"
#include "../../service/data-config/DataConfigService.h"
#include "../ApiDeclarativeServicesHelper.h"

DataConfigJsonVO::Wrapper DataConfigController::execQueryDataConfig(const String& id) {
	// ����һ��Service
	DataConfigService service;
	// ��ѯ����
	auto result = service.queryByXid(id);
	// ��Ӧ���
	auto jvo = DataConfigJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper DataConfigController::execAddDataConfig(const AddDataConfigDTO::Wrapper& dto) {
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->xname || !dto->xalias)
	{
		jvo->init("NULL", RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	DataConfigService service;
	// ִ����������
	string id = service.saveData(dto);
	if(id!="") {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	//��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper DataConfigController::execModifyDataConfig(const ModifyDataConfigDTO::Wrapper& dto) {
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->xid)
	{
		jvo->init("NULL", RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	DataConfigService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->xid);
	}
	else
	{
		jvo->fail(dto->xid);
	}
	// ��Ӧ���
	return jvo;
}