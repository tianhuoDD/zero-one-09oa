#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: siri
 @Date: 2024/10/20 20:24:15

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _CHECKINMEETINGCONTROLLER_H_
#define _CHECKINMEETINGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/Meeting/checkinmeeting/CheckinMeetingDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class CheckinMeetingController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(CheckinMeetingController);
public:
	// 定义新增会议签到记录接口描述
	ENDPOINT_INFO(addCheckinMeeting) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("meeting.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义新增会议签到记录接口处理
	ENDPOINT(API_M_POST, "/meeting/checkin-meeting", addCheckinMeeting, BODY_DTO(CheckinMeetingDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddCheckinMeeting(dto, authObject->getPayload()));
	}
	
private:
	// 前端只需传入会议ID
	Uint64JsonVO::Wrapper execAddCheckinMeeting(const CheckinMeetingDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_CHECKINMEETINGCONTROLLER_H_