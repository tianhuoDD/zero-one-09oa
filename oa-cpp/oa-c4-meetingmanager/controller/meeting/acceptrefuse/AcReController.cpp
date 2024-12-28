#include "stdafx.h"
#include "AcReController.h"
//#include "../../../service/acceptrefuse/AcReService.h"
#include "../../ApiDeclarativeServicesHelper.h"


/*
mt_meeting_acceptpersonlist表中的orderColumn代表同一个会议中参与者的展示顺序
mt_meeting_refusepersonlist表一样
由后端生成
*/
StringJsonVO::Wrapper AcReController::execAcceptMeeting(const string& xid, const PayloadDTO& payload)
{
	string userId = payload.getId();
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	//if (""==xid)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	// 有效值校验
	if (xid.empty())
	{
		jvo->init("empty String", RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	AcReService service;
	// 执行数据新增
	uint64_t id = service.saveDataAccept(xid,userId);
	if (id > 0) {
		jvo->success(xid);
	}
	else
	{
		jvo->fail(xid);
	}
	//响应结果
	return jvo;

}

StringJsonVO::Wrapper AcReController::execRefuseMeeting(const string& xid, const PayloadDTO& payload)
{
	string userId = payload.getId();
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	//if (""==xid)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	// 有效值校验
	if (xid.empty())
	{
		jvo->init("empty String", RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	AcReService service;
	// 执行数据新增
	uint64_t id = service.saveDataRefuse(xid, userId);
	if (id > 0) {
		jvo->success(xid);
	}
	else
	{
		jvo->fail(xid);
	}
	//响应结果
	return jvo;
}
