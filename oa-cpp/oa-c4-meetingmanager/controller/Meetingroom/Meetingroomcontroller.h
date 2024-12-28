#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/17 19:36:05

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
#ifndef _PERSONSETTINGCONTROLLER_H_
#define _PERSONSETTINGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/meetingroom/MeetingroomVO.h"
#include "../../domain/dto/meetingroom/MeetingroomDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MeetingroomController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(MeetingroomController);
public: 
	// 定义接口
	// 获取修改会议室信息接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("meetingroom.titlemodify"), saveMeetingroom, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/meeting/meetingroom/modify", saveMeetingroom, BODY_DTO(MeetingroomDTO::Wrapper, dto), executeModifyMeetingroom(dto));

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(roomdeleteMeetinroom) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("meetingroom.titledelete"), StringJsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "name", ZH_WORDS_GETTER("meetingroom.name"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/meeting/meetingroom/delete/{name}", roomdeleteMeetinroom, PATH(String, name), executeRoomDelete(name));

	

	// ....
private: // 定义接口执行函数
	// 执行修改会议室信息
	StringJsonVO::Wrapper executeModifyMeetingroom(const MeetingroomDTO::Wrapper& dto);
	// 执行删除会议室信息
	StringJsonVO::Wrapper executeRoomDelete(const String &name);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PERSONSETTINGCONTROLLER_H_