#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/01 17:39:36

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
#ifndef _USERCONTROLLER_H_
#define _USERCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/resourcedocument/UpdateAttachmentQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/resourcedocument/AddAttachmentVO.h"
#include "domain/vo/resourcedocument/UpdateAttachmentVO.h"
#include "domain/dto/resourcedocument/AddAttachmentDTO.h"
#include "domain/dto/resourcedocument/UpdateAttachmentDTO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class AttachmentController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(AttachmentController);
public:
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addAttachment) 
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("resourcedocument.query.summary1"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AddAttachmentJsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/resdoc/attachment/add", addAttachment, BODY_DTO(AddAttachmentDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME)
	{
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddAttachment(dto));
	}


	// 4.1 定义修改接口描述
	ENDPOINT_INFO(updateAttachment)
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("resourcedocument.query.summary2"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(UpdateAttachmentJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("productionorder.query.fields.xid"), "", true);
	}
	// 4.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/resdoc/attachment/update", updateAttachment, BODY_DTO(UpdateAttachmentDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME)
	{
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execUpdateAttachment(dto));
	}

private:
	AddAttachmentJsonVO::Wrapper execAddAttachment(const AddAttachmentDTO::Wrapper& dto1);
	UpdateAttachmentJsonVO::Wrapper execUpdateAttachment(const UpdateAttachmentDTO::Wrapper& dto2);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_