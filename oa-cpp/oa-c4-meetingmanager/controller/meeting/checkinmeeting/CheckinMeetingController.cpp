#include "stdafx.h"
#include "CheckinMeetingController.h"
#include "../../../service/Meeting/checkinmeeting/CheckinMeetingService.h"

#include "SqlSession.h"
#include "../../../domain/do/Meeting/checkinmeeting/CheckinMeetingDO.h"


Uint64JsonVO::Wrapper CheckinMeetingController::execAddCheckinMeeting(const CheckinMeetingDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	// ��ȡ�û���
	dto->xcheckinPersonList = payload.getUsername();

	// ���ô��û�ǩ����¼��ͬһ�����µ����
	string sql = "SELECT COUNT(*) FROM mt_meeting_checkinpersonlist WHERE `MEETING_XID`=?";
	SqlSession sqlsession;
	CheckinMeetingDO cmdo;
	cmdo.setMeetingId(dto->meetingId);
	uint64_t num = sqlsession.executeQueryNumerical(sql, "%s", cmdo.getMeetingId());
	std::cout << "xorderColumn = " << num << std::endl;
	dto->xorderColumn = num;

	// ����У��
	// �ǿ�У��
	if (!dto->meetingId || !dto->xcheckinPersonList || !dto->xorderColumn)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->xorderColumn < 0 || dto->meetingId->empty() || dto->xcheckinPersonList->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	CheckinMeetingService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
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
