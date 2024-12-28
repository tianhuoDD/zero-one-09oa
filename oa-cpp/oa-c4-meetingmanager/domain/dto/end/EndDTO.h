#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _END_DTO_
#define _END_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class EndDTO : public oatpp::DTO
{
	DTO_INIT(EndDTO, DTO);
	//关联的会议id
	DTO_FIELD(String, meetingId);
	DTO_FIELD_INFO(meetingId) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.meetingId");
	}
	//会议室唯一标识符
	DTO_FIELD(String, roomId);
	DTO_FIELD_INFO(roomId) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.roomId");
	}
	//会议实际结束时间
	DTO_FIELD(String, actualCompleteTime);
	DTO_FIELD_INFO(actualCompleteTime) {
		info->description = ZH_WORDS_GETTER("meeting.actualCompleteTime");
	}

};


#include OATPP_CODEGEN_END(DTO)
#endif // !_END_DTO_