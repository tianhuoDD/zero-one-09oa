#include "stdafx.h"
#include "DeleteContentsController.h"
#include "../../service/contents/contentsservice.h"

StringJsonVO::Wrapper DeleteContentsController::execRemoveSample(const String& xid)
{
	//定义数据返回对象
	auto jvo = StringJsonVO::createShared();
	//参数校验
	if (!xid)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		//jvo->fail(String("ParameterWrong"));
		return jvo;
	}
	//定义一个Service
	ContentsService service;
	//执行数据删除
	if (service.removeContents(xid.getValue("1"))) {
		jvo->success(xid);
	}
	else
	{
		jvo->fail(xid);
	}
	return jvo;
}

StringJsonVO::Wrapper DeleteContentsController::execModifySample(const CdeleteDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	//参数校验
	if (!dto->xid)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//定义service
	ContentsService service;
	//执行数据修改

	if (service.updateContents(dto))
	{
		jvo->success(dto->xid);
	}
	else
	{
		jvo->fail(dto->xid);
	}
	// 响应结果
	return jvo;
}


