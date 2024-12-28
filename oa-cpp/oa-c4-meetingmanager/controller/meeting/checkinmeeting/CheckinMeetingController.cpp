#include "stdafx.h"
#include "CheckinMeetingController.h"
#include "../../../service/Meeting/checkinmeeting/CheckinMeetingService.h"

#include "SqlSession.h"
#include "../../../domain/do/Meeting/checkinmeeting/CheckinMeetingDO.h"


Uint64JsonVO::Wrapper CheckinMeetingController::execAddCheckinMeeting(const CheckinMeetingDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	// 获取用户名
	dto->xcheckinPersonList = payload.getUsername();

	// 设置此用户签到记录在同一会议下的序号
	string sql = "SELECT COUNT(*) FROM mt_meeting_checkinpersonlist WHERE `MEETING_XID`=?";
	SqlSession sqlsession;
	CheckinMeetingDO cmdo;
	cmdo.setMeetingId(dto->meetingId);
	uint64_t num = sqlsession.executeQueryNumerical(sql, "%s", cmdo.getMeetingId());
	std::cout << "xorderColumn = " << num << std::endl;
	dto->xorderColumn = num;

	// 参数校验
	// 非空校验
	if (!dto->meetingId || !dto->xcheckinPersonList || !dto->xorderColumn)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->xorderColumn < 0 || dto->meetingId->empty() || dto->xcheckinPersonList->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	CheckinMeetingService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}
