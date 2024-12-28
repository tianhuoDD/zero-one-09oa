#pragma once

#ifndef _CALENDERCREATECONTROLLER_H
#define _CALENDERCREATECONTROLLER_H

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/calender/CalenderInfoDTO.h"
#include "domain/vo/calender/CalenderInfoVO.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class CalenderCreateController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	//  定义控制器访问入口
	API_ACCESS_DECLARE(CalenderCreateController);

public:
	// 修改日历信息接口
		//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("calender.put.summary"), modifyCalenderInfo, StringJsonVO::Wrapper);
	ENDPOINT_INFO(modifyCalenderInfo) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("calender.put.summary"), Uint64JsonVO::Wrapper);
	}
	// 定义修改接口处理
	ENDPOINT(API_M_PUT, "/schedule/modify-calender", modifyCalenderInfo, BODY_DTO(CalenderInfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeModifyCalenderInfo(dto, authObject->getPayload().getXsequence()));
	}
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/calender-create/modify-calender", modifyCalenderInfo, BODY_DTO(CalenderInfoDTO::Wrapper, dto), executeModifyCalenderInfo(dto, authObject->getPayload().getXsequence()));

	//定义新增接口描述
	ENDPOINT_INFO(addCalenderInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义新增接口处理
	ENDPOINT(API_M_POST, "/schedule/create-calender", addCalenderInfo, BODY_DTO(CalenderInfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		//std::cout << authObject->getPayload().getXsequence() << std::endl;
		API_HANDLER_RESP_VO(execAddCalender(dto, authObject->getPayload().getXsequence()));
	}

	// 定义删除接口描述
	ENDPOINT_INFO(removeCalender) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("calender.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "xid", ZH_WORDS_GETTER("calender.field.xid"), "123aaa", true);
	}
	// 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/schedule/del-calender/{xid}", removeCalender, PATH(String, xid), execRemoveCalender(xid));

private:
	// 执行修改日历信息
	CalenderInfoJsonVo::Wrapper executeModifyCalenderInfo(const CalenderInfoDTO::Wrapper& dto, const string& loaddisName);
	// 新增数据
	CalenderInfoJsonVo::Wrapper execAddCalender(const CalenderInfoDTO::Wrapper& dto, const string& loaddisName);
	//删除数据
	Uint64JsonVO::Wrapper execRemoveCalender(const String& xid);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _CALENDERCREATECONTROLLER_H
