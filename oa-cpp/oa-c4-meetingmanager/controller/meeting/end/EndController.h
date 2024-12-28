#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/20 16:51:27

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
#ifndef _ENDCONTROLLER_H_
#define _ENDCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../../service/end/EndService.h"
//#include "domain/vo/room/RoomInfoVO.h"
#include "domain/dto/end/EndDTO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class EndController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(EndController);
	// 3 定义接口
public:

	/*
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("sample.put.summary"), modifySample, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/sample", modifySample, BODY_DTO(SampleDTO::Wrapper, dto), execModifySample(dto));
	*/

	//end
	ENDPOINT_INFO(endMeeting) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("meeting.end"), StringJsonVO::Wrapper);
		/*API_DEF_ADD_PATH_PARAMS(String, "meetingId", ZH_WORDS_GETTER("meeting.field.xid"), 1, true);*/
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/meeting/end", endMeeting, BODY_DTO(EndDTO::Wrapper, dto), execEndMeeting(dto));


private: // 定义接口执行函数

	//结束会议
	StringJsonVO::Wrapper execEndMeeting(const EndDTO::Wrapper& dto);

};




#include OATPP_CODEGEN_END(ApiController)

#endif // !_ENDCONTROLLER_H_