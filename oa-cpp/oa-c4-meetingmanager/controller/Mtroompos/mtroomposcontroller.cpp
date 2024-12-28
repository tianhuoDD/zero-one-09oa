#include "stdafx.h"
#include "mtroomposcontroller.h"
#include "../../service/GetAddmtroompos/GetAddmtroomposService.h"
#include "../ApiDeclarativeServicesHelper.h"


GetmtroomposPageJsonVO::Wrapper MtroomposController::execQueryMtroompos(const GetmtroomposQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	GetAddmtroomposService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = GetmtroomposPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper MtroomposController::execAddMtroompos(const AddmtroomposDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->xname || !dto->xaddress)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->xname->empty() || dto->xaddress->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	GetAddmtroomposService service;
	// ִ����������
	uint64_t id = service.insertData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}