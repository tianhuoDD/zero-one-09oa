#include "stdafx.h"
#include "CalenderCreateController.h"
#include "../../../service/calendar/CalenderService.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include <iostream>

CalenderInfoJsonVo::Wrapper CalenderCreateController::executeModifyCalenderInfo(const CalenderInfoDTO::Wrapper& dto, const string& loaddisName)
{
	// ���巵�����ݶ���
	auto jvo = CalenderInfoJsonVo::createShared();
	// ����У��
	// �ǿ�У��
	if (dto->xname->empty())    //��������Ϊ��   -4
	{
		jvo->init(RS_CALENDERNAME_FAIL);
		return jvo;
	}
	else if ("UNIT" == (string)(dto->xtype) && dto->xtarget->empty())  //������֯Ϊ��  -2
	{
		jvo->init( RS_CALENDERXTARGETRMPTY_FAIL);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->xdescription->size() > 255)  //��ע����  -3
	{
		jvo->init(RS_CALENDERDESCRIPTION_FAIL);
		return jvo;
	}

	// ����һ��Service
	CalenderService service;
	// ִ�������޸�
	uint64_t result = service.updateData(dto, loaddisName);
	if (88 == result) {
		jvo->fail(UInt64(result));
	}
	else if (result)
	{
		jvo->success();
	}
	else
		jvo->fail(-1);
	// ��Ӧ���
	return jvo;
}

CalenderInfoJsonVo::Wrapper CalenderCreateController::execAddCalender(const CalenderInfoDTO::Wrapper& dto, const string& loaddisName)
{
	// ���巵�����ݶ���
	auto jvo = CalenderInfoJsonVo::createShared();
	// ����У��
	// �ǿ�У��
	if (dto->xname->empty())    //��������Ϊ��   -4
	{
		jvo->init(RS_CALENDERNAME_FAIL);
		return jvo;
	}
	else if ("UNIT" == (string)(dto->xtype) && dto->xtarget->empty())  //������֯Ϊ��  -2
	{
		jvo->init(RS_CALENDERXTARGETRMPTY_FAIL);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->xdescription->size() > 255)  //��ע����  -3
	{
		jvo->init(RS_CALENDERDESCRIPTION_FAIL);
		return jvo;
	}

	// ����һ��Service
	CalenderService service;
	// ִ����������
	uint64_t id = service.saveData(dto, loaddisName);
	std::cout << id << std::endl;
	if (88 == id)
	{
		jvo->fail(UInt64(id));
	}
	else if (id > 0) {
		jvo->success();
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper CalenderCreateController::execRemoveCalender(const String& xid)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (xid->empty())  //xidΪ��
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	CalenderService service;
	// ִ������ɾ��
	if (service.removeData(xid)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(-1);
	}
	// ��Ӧ���
	return jvo;
}
