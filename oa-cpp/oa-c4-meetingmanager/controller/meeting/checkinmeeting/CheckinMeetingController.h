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
	// ����������������
	API_ACCESS_DECLARE(CheckinMeetingController);
public:
	// ������������ǩ����¼�ӿ�����
	ENDPOINT_INFO(addCheckinMeeting) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("meeting.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ������������ǩ����¼�ӿڴ���
	ENDPOINT(API_M_POST, "/meeting/checkin-meeting", addCheckinMeeting, BODY_DTO(CheckinMeetingDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddCheckinMeeting(dto, authObject->getPayload()));
	}
	
private:
	// ǰ��ֻ�贫�����ID
	Uint64JsonVO::Wrapper execAddCheckinMeeting(const CheckinMeetingDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_CHECKINMEETINGCONTROLLER_H_