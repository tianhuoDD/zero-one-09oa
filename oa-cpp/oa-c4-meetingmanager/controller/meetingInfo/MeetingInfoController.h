#pragma once
#ifndef _MEETING_INFO_CONTROLLER_
#define _MEETING_INFO_CONTROLLER_


#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/Meeting/MeetingInfoDTO.h"
#include "domain/vo/MeetingInfo/meetingInfoVO.h"
#include"../../service/Meeting/MeetingService.h"
#include "zxing/MultiFormatWriter.h"
#include "zxing/CharacterSet.h"
#include "zxing/BitMatrix.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class MeetingInfoController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	API_ACCESS_DECLARE(MeetingInfoController);
public:
	//查询会议详细
	ENDPOINT_INFO(queryMeeting) {
		// 定义接口标题
		//API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sample.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(MeetInfoJsonVO);
		info->summary = ZH_WORDS_GETTER("meeting-manager.meeting-info.query");
		// 定义其他查询参数描述
		//根据会议唯一标识符查询详细会议
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("meeting-manager.meeting-info.meetingId"), "5ew764654t", true);
		
	}
	ENDPOINT(API_M_GET, "/meeting/query-detail", queryMeeting, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryDetailMeetingInfo(id, authObject->getPayload()));
	}

	//修改会议信息
	ENDPOINT_INFO(ModifyMeeting) {
		API_DEF_ADD_AUTH();
		info->summary = ZH_WORDS_GETTER("meeting-manager.modifyMeeting.info");
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_PUT,"/meeting/modify", ModifyMeeting, BODY_DTO(MeetingInfo::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execModifyMeetingInfo(dto, authObject->getPayload()));
	}
	
private:
	
	MeetInfoJsonVO::Wrapper execQueryDetailMeetingInfo(const String& Id, const PayloadDTO& payload);
	StringJsonVO::Wrapper execModifyMeetingInfo(const MeetingInfo::Wrapper& meeting, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif //_MEETING_INFO_CONTROLLER_