#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: siri
 @Date: 2024/10/20 19:43:05

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
#ifndef _UPLOADATTACHMENTCONTROLLER_H_
#define _UPLOADATTACHMENTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/Meeting/uploadattachment/UploadAttachmentDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class UploadAttachmentController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(UploadAttachmentController);
public:
	// 定义一个上传会议文件接口
	// 定义描述
	ENDPOINT_INFO(uploadMeetingFile) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("meeting.file.upload.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 定义端点
	ENDPOINT(API_M_POST, "/meeting/file/upload", uploadMeetingFile, REQUEST(std::shared_ptr<IncomingRequest>, request), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execUploadMeetingFile(request, authObject->getPayload()));
	}

private:
	StringJsonVO::Wrapper execUploadMeetingFile(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_UPLOADATTACHMENTCONTROLLER_H_