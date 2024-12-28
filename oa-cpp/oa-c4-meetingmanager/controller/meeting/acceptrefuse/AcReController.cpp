#include "stdafx.h"
#include "AcReController.h"
//#include "../../../service/acceptrefuse/AcReService.h"
#include "../../ApiDeclarativeServicesHelper.h"


/*
mt_meeting_acceptpersonlist���е�orderColumn����ͬһ�������в����ߵ�չʾ˳��
mt_meeting_refusepersonlist��һ��
�ɺ������
*/
StringJsonVO::Wrapper AcReController::execAcceptMeeting(const string& xid, const PayloadDTO& payload)
{
	string userId = payload.getId();
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	//if (""==xid)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	// ��ЧֵУ��
	if (xid.empty())
	{
		jvo->init("empty String", RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	AcReService service;
	// ִ����������
	uint64_t id = service.saveDataAccept(xid,userId);
	if (id > 0) {
		jvo->success(xid);
	}
	else
	{
		jvo->fail(xid);
	}
	//��Ӧ���
	return jvo;

}

StringJsonVO::Wrapper AcReController::execRefuseMeeting(const string& xid, const PayloadDTO& payload)
{
	string userId = payload.getId();
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	//if (""==xid)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	// ��ЧֵУ��
	if (xid.empty())
	{
		jvo->init("empty String", RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	AcReService service;
	// ִ����������
	uint64_t id = service.saveDataRefuse(xid, userId);
	if (id > 0) {
		jvo->success(xid);
	}
	else
	{
		jvo->fail(xid);
	}
	//��Ӧ���
	return jvo;
}
