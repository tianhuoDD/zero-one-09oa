
#include "stdafx.h"
#include "Attrib_add_Controller.h"
#include "../../service/Attrib_add/Attrib_add_Service.h"
#include "../ApiDeclarativeServicesHelper.h"

//add
Uint64JsonVO::Wrapper Attrib_add_Controller::execAddAttrib(const Attrib_add_DTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	
	// �ǿ�У��(��֯���ƺ�id����Ϊ�գ�һ����˵�õ���ǰ������id�϶���Ϊ��)
	if (!dto->xname)
	{
		jvo->init(UInt64(-1), ResultStatus(ZH_WORDS_GETTER("Attrib_add.message_error.one"), 9990));//���ظ�ǰ����Ϣmessage--�ϴ������쳣
		return jvo;
	}
	if (dto->xid == "0") {
		jvo->init(UInt64(-1), ResultStatus(ZH_WORDS_GETTER("Attrib_add.message_error.two"), 9991));//���ظ�ǰ����Ϣmessage--�ϴ������쳣����ʵ����Ӧ��д��Ϊ�ҵ���id��֯��
		return jvo;
	}
	// ��ЧֵУ��(���ݿ����Ƿ�������id)
	Attrib_add_Service service_id_name;
	uint64_t sample_id = service_id_name.select_id(dto);
	if (sample_id <= 0) {//˵�����ݿ�û�����id
		jvo->init(UInt64(-1), ResultStatus(ZH_WORDS_GETTER("Attrib_add.message_error.three"), 9995));//���ظ�ǰ����Ϣmessage--�ϴ������쳣����ʵ����Ӧ��д��Ϊ�ҵ���id��֯��
		return jvo;
	}

	// ����һ��Service
	Attrib_add_Service service;
	// ִ����������
	//uint64_t id1 = service.saveData1(dto);//��id������
	uint64_t id2 = service.saveData2(dto);//��id������
	if (id2 > 0) {
		jvo->success(UInt64(1));//���ص�dataֵ
	}
	else
	{
		jvo->fail(UInt64(1));//���ص�dataֵ
	}
	//��Ӧ���
	return jvo;
}
