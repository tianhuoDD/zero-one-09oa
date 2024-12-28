#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _GETSHAREFILESCONTROLLER_H_
#define _GETSHAREFILESCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/getting/file/GetShareFilesVO.h"
#include "domain/query/getting/file/GetShareFilesQuery.h"
#include "domain/dto/getting/file/GetShareFilesDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class GetShareFilesController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(GetShareFilesController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryShareFilesByXunique) {
		// 定义接口标题 - 获取共享文件列表
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Myfile.file.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetShareFilesPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义文件上传人查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xperson", ZH_WORDS_GETTER("Myfile.filed.xperson"), "hhh@1434@P", true);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/companynetdisk/query-filelist-by-fileid", queryShareFilesByXunique, QUERIES(QueryParams, param), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为queryShareFilesByXname领域模型
		API_HANDLER_QUERY_PARAM(sharefileQuery, GetShareFilesQuery, param);
		//获取负载的xid
		sharefileQuery->xid = authObject->getPayload().getId();
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execqueryShareFilesByXunique(sharefileQuery));
	}

private:
	GetShareFilesPageJsonVO::Wrapper execqueryShareFilesByXunique(const GetShareFilesQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _GETSHAREFILESCONTROLLER_H_
