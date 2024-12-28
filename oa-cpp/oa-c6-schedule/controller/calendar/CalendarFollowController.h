#pragma once
#ifndef _CALENDARFOLLOW_CONTROLLER_
#define _CALENDARFOLLOW_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/calendar/CalendarFollowDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class CalendarFollowController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(CalendarFollowController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(addFollow) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.post.follow"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义其他查询参数描述
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}

	// 3.2 定义查询接口处理
	ENDPOINT(API_M_POST, "/schedule/calendar-space-addfollow", addFollow, BODY_DTO(CalendarFollowDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
	// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddFollow(dto, authObject->getPayload()));
	}

	ENDPOINT_INFO(removeFollow) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.delete.follow"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义其他查询参数描述
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}

	// 3.2 定义查询接口处理
	ENDPOINT(API_M_DEL, "/schedule/calendar-space-removefollow", removeFollow, BODY_DTO(CalendarFollowDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execRemoveFollow(dto, authObject->getPayload()));
	}
private:
	// 3.3 新增关注
	Uint64JsonVO::Wrapper execAddFollow(const CalendarFollowDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 移除关注
	Uint64JsonVO::Wrapper execRemoveFollow(const CalendarFollowDTO::Wrapper& dto, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _CALENDARFOLLOW_CONTROLLER_