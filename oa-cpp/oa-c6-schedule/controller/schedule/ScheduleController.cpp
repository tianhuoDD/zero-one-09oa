#include "stdafx.h"
#include "ScheduleController.h"
#include "../../service/event/EventService.h"
#include "../ApiDeclarativeServicesHelper.h"

/**
 * 定义状态提示信息
 */
#ifdef LINUX
#define RS_REPEAT_LOGIC_ERR ResultStatus("repeat related parameter errors", 9919)
#define RS_EMPTY_ERR ResultStatus("parameter is empty", 9918)
#define RS_OVERSIZE_ERR ResultStatus("comment oversize", 9917)
#define RS_DATEFORMAT_ERR ResultStatus("date format err", 9916)
#define RS_DBOPTION_ERR ResultStatus("database operation error", 9915)
#else
#define RS_REPEAT_LOGIC_ERR ResultStatus("repeat related parameter errors", 9919)
#define RS_EMPTY_ERR ResultStatus("parameter is empty", 9918)
#define RS_OVERSIZE_ERR ResultStatus("comment oversize", 9917)
#define RS_DATEFORMAT_ERR ResultStatus("date format err", 9916)
#define RS_DBOPTION_ERR ResultStatus("database operation error", 9915)
const int FLAG1 = -1;
#endif

bool validateDateFormat(const string& dateTime) {
	std::tm tm = {};
	std::istringstream ss(dateTime);

	// 解析字符串，格式为"YYYY-MM-DD HH:MM:SS"
	ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");

	// 如果解析失败或有多余字符，说明格式不正确
	return !ss.fail() && ss.eof();
}

Uint64JsonVO::Wrapper ScheduleController::execAddSchdule(const ScheduleInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	bool flag = true;

	if (dto->xcalendarId == "" || !dto->xcalendarId) {    //关键参数为空
		flag = false;
		jvo->init(flag, RS_EMPTY_ERR);
		return jvo;
	}

	if ((dto->xrepeat != "NO" && dto->xrecurrenceRule == "")) {  //重复逻辑错误
		flag = false;
		jvo->init(flag, RS_REPEAT_LOGIC_ERR);
		return jvo;
	}

	if (dto->xcomment->size() > 255) {  //内容太长
		flag = false;
		jvo->init(flag, RS_EMPTY_ERR);
		return jvo;
	}

	if(!validateDateFormat(dto->xstartTime) || !validateDateFormat(dto->xendTime)){  //日期格式错误
		flag = false;
		jvo->init(flag, RS_DATEFORMAT_ERR);
		return jvo;
	}

	payload.getUsername();
	// 定义一个Service
	EventService service;
	// 执行数据新增
	//cout << payload.getUsername() << endl;
	bool id = service.saveEventData(dto, payload.getXsequence());
	if (id > 0) {
		jvo->success(id);
	}
	else
	{
		jvo->init(id, RS_DBOPTION_ERR);
		
	}
	//响应结果
	return jvo;
	//return ScheduleInfoJsonVO::Wrapper();
}

Uint64JsonVO::Wrapper ScheduleController::execModifySchdule(const ScheduleInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	bool flag = true;
	// 参数校验
	if (!dto->xid || dto->xid == "")    //关键参数为空
	{
		flag = false;
		jvo->init(flag, RS_EMPTY_ERR);
		return jvo;
	}

	// 参数校验

	if (dto->xcalendarId == "" || !dto->xcalendarId) {    //关键参数为空
		flag = false;
		jvo->init(flag, RS_EMPTY_ERR);
		return jvo;
	}

	if ((dto->xrepeat != "NO" && dto->xrecurrenceRule == "")) {  //重复逻辑错误
		flag = false;
		jvo->init(flag, RS_REPEAT_LOGIC_ERR);
		return jvo;
	}

	if (dto->xcomment->size() > 255) {  //内容太长
		flag = false;
		jvo->init(flag, RS_EMPTY_ERR);
		return jvo;
	}

	if (!validateDateFormat(dto->xstartTime) || !validateDateFormat(dto->xendTime)) {  //日期格式错误
		flag = false;
		jvo->init(flag, RS_DATEFORMAT_ERR);
		return jvo;
	}


	// 定义一个Service
	EventService service;
	// 执行数据修改
	bool id;
	id = service.updateEventData(dto, payload.getXsequence());

	if (id) jvo->success(id);
	else jvo->init(id, RS_DBOPTION_ERR);
	
	// 响应结果
	return jvo;
	//return StringJsonVO::Wrapper();
}

Uint64JsonVO::Wrapper ScheduleController::execRemoveSchdule(const ScheduleDelDTO::Wrapper& dto)
{

	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	bool flag = true;
	if (dto->xidList->empty() || dto->xidList->size() == 0)
	{
		flag = false;
		jvo->init(flag, RS_EMPTY_ERR);
		return jvo;
	}
	// 定义一个Service
	EventService service;
	// 执行数据删除
	bool id;
	id = service.removeEventData(dto);

	if (id) jvo->success(id);
	else jvo->init(id, RS_DBOPTION_ERR);

	return jvo;
}
