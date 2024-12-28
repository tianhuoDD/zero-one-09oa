#include "stdafx.h"
#include "NewController.h"

#include "../../service/New/NewService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/Put/PutService.h"
PutJsonVO::Wrapper NewController::executeModifyNew(const PutDTO::Wrapper& dto)
{
	auto jvo = PutJsonVO::createShared();
	//参数校验
	//范围校验

	//定义一个Service
	PutService service;
	//执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto);
	}
	else {
		jvo->fail(dto);
	}
	// 响应结果
	return jvo;
}
NewJsonVO::Wrapper NewController::executeQueryNew(const String& id)
{// 定义一个Service
	
	NewService service;
	// 查询数据
	auto result = service.listAll(id);
	// 响应结果
	auto jvo = NewJsonVO::createShared();
	jvo->success(result);
	return jvo;
}