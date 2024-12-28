
#include "stdafx.h"
#include "Attrib_modify_Controller.h"
#include "../../service/Attrib_modify/Attrib_modify_Service.h"
#include "../ApiDeclarativeServicesHelper.h"

//modify �޸�����ֵ��Ҫ�������������ݹ�����ԭ����ֵ��Ҫ�޸�Ϊ������ֵ
Uint64JsonVO::Wrapper Attrib_modify_Controller::execModifyAttrib(const Attrib_modify_DTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	if (dto->xid == "0") {
		jvo->init(UInt64(-1), ResultStatus(ZH_WORDS_GETTER("Attrib_modify.message_error.two"), 9993));
		return jvo;
	}
	// id��ЧֵУ��(���ݿ����Ƿ�������id������)
	Attrib_modify_Service service_id_name;
	uint64_t sample_id = service_id_name.select_id(dto);
	if (sample_id <= 0) {//˵�����ݿ�û�����id
		jvo->init(UInt64(-1), ResultStatus(ZH_WORDS_GETTER("Attrib_modify.message_error.three"), 9994));
		return jvo;
	}

	//���� Ҫ�޸ĵ���֯���ԣ�ȥ���ݿ���Ҹ�id������ֵ�Ƿ���ڣ�һ����˵�Ǵ��ڵģ�����ǰ�˷�����ʱ�����Ա仯��

	// ����һ��Service
	Attrib_modify_Service service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(1);
	}
	// ��Ӧ���
	return jvo;
}
