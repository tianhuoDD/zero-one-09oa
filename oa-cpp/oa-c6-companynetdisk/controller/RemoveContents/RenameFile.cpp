#include "stdafx.h"
#include "RenameFile.h"
#include "../../service/contents/fileservice.h"

StringJsonVO::Wrapper RenameFileController::execModifySample(const DdeleteDTO::Wrapper& dto, const PayloadDTO& payload)
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
	FileService service;
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
