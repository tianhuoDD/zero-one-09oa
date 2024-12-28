#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/26 16:29:52

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

#ifndef _MEETINGROOMSELECTAPICLIENT_H_
#define _MEETINGROOMSELECTAPICLIENT_H_

// 1 导入必须头文件
#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"


/**
 * 书写示例ApiClient来演示定义声明式服务
 */
class MeetingRoomSelectApiClient : public oatpp::web::client::ApiClient // 2 继承这个类
{
	// 3 定义ApiClient控制器使用宏---开始
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 初始化定义
	API_CLIENT_INIT(MeetingRoomSelectApiClient);

	// 5 使用API_CALL或API_CALL_ASYNC声明调用服务接口

	// 定义查询单个会议室详细信息的接口，使用 meetingRoomId 和 token
	API_CALL("GET", "/meetingroom/details/{meetingRoomId}", queryOne,
		HEADER(String, token, "Authorization"),
		PATH(UInt64, meetingRoomId))
	//// 多条件查询
	//API_CALL(API_M_GET, "/meetingmanager/query-all", queryAll, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, QUERY(String, meetingRoomName));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 取消ApiClient控制器使用宏---结束
};

#endif // !_SAMPLEAPICLIENT_H_