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
#ifndef _ACRECONTROLLER_H_
#define _ACRECONTROLLER_H_

#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
//#include "domain/query/PageQuery.h"
#include "domain/dto/PayloadDTO.h"
#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/GlobalInclude.h"
#include "../../../service/acceptrefuse/AcReService.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class AcReController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(AcReController);
	// 3 定义接口
public:

	//accept
	ENDPOINT_INFO(acceptMeeting) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("meeting.accept"), StringJsonVO::Wrapper);
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("meeting.field.xid"), 1, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/meeting/accpet/{id}", acceptMeeting, PATH(String, id), execAcceptMeeting(id, authObject->getPayload()));

	//refuse
	ENDPOINT_INFO(refuseMeeting) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("meeting.refuse"), StringJsonVO::Wrapper);
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("meeting.field.xid"), 1, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/meeting/refuse/{id}", refuseMeeting, PATH(String, id), execRefuseMeeting(id, authObject->getPayload()));


private: // 定义接口执行函数

	// 接受
	StringJsonVO::Wrapper execAcceptMeeting(const string& xid, const PayloadDTO& payload);
	//拒绝会议
	//meetingXid例子 v=-4a1e76a 64位,payload获得用户id
	StringJsonVO::Wrapper execRefuseMeeting(const string& xid, const PayloadDTO& payload);

};




#include OATPP_CODEGEN_END(ApiController)

#endif // !_ACRECONTROLLER_H_