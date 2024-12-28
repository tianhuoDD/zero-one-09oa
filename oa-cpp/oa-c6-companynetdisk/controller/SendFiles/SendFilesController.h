#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: $DATE$ $HOUR$:$MINUTE$:$SECOND$

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
#ifndef _SENDFILESCONTROLLER_H_
#define _SENDFILESCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include"domain/query/PageQuery.h"
#include "domain/GlobalInclude.h"
#include"domain/dto/myfiles/SendFilesDTO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class SendFilesController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(SendFilesController);
public: // 定义接口

	//发送文件接口
	ENDPOINT_INFO(sendfiles) {

		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Myfile.send.summary"));
		//info->summary = "发送文件给用户让其可以编辑";
		//info->addConsumes<Object<UserDto>>("application/json");
		info->addResponse<Object<StringJsonVO>>(Status::CODE_200, "application/json");//返回请求体数据response
		//info->addResponse<String>(Status::CODE_404, "text/plain");
		// params specific
		//info->queryParams["xid"].description = "wen jian id";
		//info->queryParams["xeditorList"].description = "shou jian ren id";
///定义接口标题
		//API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sample.post.summary"));
///定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		///定义响应参数格式
				//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}


	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/companynetdisk/myfile-sendfiles", sendfiles, BODY_DTO(SendFilesDTO::Wrapper, condition), API_HANDLER_AUTH_PARAME) {

		// 呼叫执行函数响应结果
		//API_HANDLER_QUERY_PARAM(condition, SendFilesDTO, params);
		API_HANDLER_RESP_VO(executeSendFiles(condition, authObject->getPayload()));
	}

private: // 定义接口执行函数
	StringJsonVO::Wrapper executeSendFiles(const SendFilesDTO::Wrapper& condition, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_SENDFILESCONTROLLER_H_
