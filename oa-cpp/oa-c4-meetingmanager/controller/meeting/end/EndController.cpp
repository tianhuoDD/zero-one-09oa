
#include "stdafx.h"
#include "EndController.h"
//#include "../../../service/end/EndService.h"




//mt_meeting表中的xmanualCompleted,xactualCompletedTime,xupdateTime需要被修改
//mt_room表中的xavailable需要被修改


StringJsonVO::Wrapper EndController::execEndMeeting(const EndDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->meetingId)
	{
		jvo->init("", RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	EndService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->meetingId);
	}
	else
	{
		jvo->fail(dto->meetingId);
	}
	// 响应结果
	return jvo;


}
