#include "stdafx.h"
#include "mtroomposcontroller.h"
#include "../../service/GetAddmtroompos/GetAddmtroomposService.h"
#include "../ApiDeclarativeServicesHelper.h"


GetmtroomposPageJsonVO::Wrapper MtroomposController::execQueryMtroompos(const GetmtroomposQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	GetAddmtroomposService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = GetmtroomposPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper MtroomposController::execAddMtroompos(const AddmtroomposDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->xname || !dto->xaddress)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->xname->empty() || dto->xaddress->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	GetAddmtroomposService service;
	// 执行数据新增
	uint64_t id = service.insertData(dto);
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