
#include "stdafx.h"
#include "EndController.h"
//#include "../../../service/end/EndService.h"




//mt_meeting���е�xmanualCompleted,xactualCompletedTime,xupdateTime��Ҫ���޸�
//mt_room���е�xavailable��Ҫ���޸�


StringJsonVO::Wrapper EndController::execEndMeeting(const EndDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->meetingId)
	{
		jvo->init("", RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	EndService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->meetingId);
	}
	else
	{
		jvo->fail(dto->meetingId);
	}
	// ��Ӧ���
	return jvo;


}
