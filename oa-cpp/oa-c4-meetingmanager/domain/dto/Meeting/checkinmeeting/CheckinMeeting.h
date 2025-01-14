#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: siri
 @Date: 2024/10/20 20:12:53

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
#ifndef _CHECKINMEETING_H_
#define _CHECKINMEETING_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个用于会议签到的数据传输模型
 */
class CheckinMeetingDTO : public oatpp::DTO
{
	DTO_INIT(CheckinMeetingDTO, DTO);
	// 会议ID
	API_DTO_FIELD_DEFAULT(String, meetingId, ZH_WORDS_GETTER("meeting.field.id"));
	// 用户ID
	API_DTO_FIELD_DEFAULT(String, userId, ZH_WORDS_GETTER("user.field.id"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CHECKINMEETING_H_