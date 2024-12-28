#include "stdafx.h"
#include "atqController.h"
#include "../../../service/configuration/atq/ConfigurationService.h"
#include "../../ApiDeclarativeServicesHelper.h"

ConfigurationPageJsonVO::Wrapper atqController::execucateconfigquery(const String& logo) {

	// ����һ��Service
	ConfigurationService service;
	// ��ѯ����
	auto result = service.listAll(logo);
	// ��Ӧ���
	auto jvo = ConfigurationPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper atqController::execucatemodify(const ConfigurationDTO::Wrapper& dto)
{
	auto jvo = StringJsonVO::createShared();
	//����У��
	//��ΧУ��

	//����һ��Service
	ConfigurationService service;
	//ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->xappId);
	}
	else {
		jvo->fail(dto->xappId);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper atqController::execucateadd(const ConfigurationDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	//auto jvo = StringJsonVO::createShared();
	auto jvo = Uint64JsonVO::createShared();
	//����У��
	//�ǿ�У��
	if (!dto->xappId || !dto->xdocumentType ||!dto->process||!dto->range||!dto->xcreatorPerson||!dto->xmanagePerson) {
		jvo->init(-1, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ConfigurationService service;
	// ִ����������
	int id = service.saveData(dto);
	if (id>0) {
		jvo->success(int(id));
	}
	else {
		jvo->fail(int(id));
	}
	//��Ӧ���
	return jvo;
}



Uint64JsonVO::Wrapper atqController::execRemoveConfiguration(const String& logo)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	ConfigurationService service;
	auto result = service.removeData(logo);

	// ��Ӧ���
	jvo->success(result);
	return jvo;
}