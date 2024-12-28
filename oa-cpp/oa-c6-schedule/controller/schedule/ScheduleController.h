#pragma once
#ifndef _SCHEDULECONTROLLER_H_
#define _SCHEDULECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/schedule/ScheduleInfoVO.h"
#include "domain/dto/schedule/ScheduleInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ScheduleController : public oatpp::web::server::api::ApiController {

	//  定义控制器访问入口
	API_ACCESS_DECLARE(ScheduleController);

public:
	// 定义日程新增接口描述
	ENDPOINT_INFO(addSchdule) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.event.add_summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义日程新增接口处理
	ENDPOINT(API_M_POST, "/schedule/add-event", addSchdule, BODY_DTO(ScheduleInfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddSchdule(dto, authObject->getPayload()));
	}

	// 定义日程修改接口描述
	ENDPOINT_INFO(modifySchdule) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.event.put_summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义日程修改接口处理
	ENDPOINT(API_M_PUT, "/schedule/modfify-event", modifySchdule, BODY_DTO(ScheduleInfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execModifySchdule(dto, authObject->getPayload()));
	}

	
	// 定义日程删除接口描述
	ENDPOINT_INFO(removeSchdule) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("calender.event.del_summary"), ScheduleDelDTO::Wrapper);
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义日程删除接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/schedule-event/del-event/{xid}", removeSchdule, PATH(String, xid),QUERY(String, pram), execRemoveSchdule(xid, pram));
	ENDPOINT(API_M_DEL, "/schedule/del-event", removeSchdule, BODY_DTO(ScheduleDelDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execRemoveSchdule(dto));
	}

private:

	Uint64JsonVO::Wrapper execAddSchdule(const ScheduleInfoDTO::Wrapper& dto, const PayloadDTO& payload);

	Uint64JsonVO::Wrapper execModifySchdule(const ScheduleInfoDTO::Wrapper& dto, const PayloadDTO& payload);

	Uint64JsonVO::Wrapper execRemoveSchdule(const ScheduleDelDTO::Wrapper& dto);



};


#include OATPP_CODEGEN_END(ApiController)

#endif // !_SCHEDULECONTROLLER_H_
