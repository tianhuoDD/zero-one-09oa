#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 11:19:05

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
#ifndef _TEMPLATEFILECONTROLLER_H_
#define _TEMPLATEFILECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/personimport/templatefile/TemplateVO.h"
#include <fstream>

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 模板文件操作接口
 */
class TemplateFileController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(TemplateFileController);
public:

	//// 定义一个文件下载接口
	//// 定义描述
	//ENDPOINT_INFO(downloadFile) {
	//	API_DEF_ADD_COMMON(ZH_WORDS_GETTER("file.download.summary"), Void);
	//	API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.filename"), "file/templateTest.excel", true);
	//}
	//// 定义端点
	//ENDPOINT(API_M_GET, "/file/downloadTemplate", downloadFile, QUERY(String, filename)) {
	//	return execDownloadFile(filename);
	//}

	// 定义一个导入模板表下载接口
	// 定义描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.download.summary"), TemplateFile, Void);
	// 定义端点
	ENDPOINT(API_M_GET, "/file/downloadTemplate", TemplateFile) {
		return execTemplateFile();
	}


	//// 定义一个导入模板表的HTML文件接口
	//// 定义描述
	//API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.html.summary"), htmlFile, Void);
	//// 定义端点
	//ENDPOINT(API_M_GET, "/file/**", htmlFile, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
	//	return execHtmlFile(request);
	//}

	// 定义一个导入模板表的HTML文件接口
	// 定义描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.html.summary"), htmlFile, Void);
	// 定义端点
	ENDPOINT(API_M_GET, "/file/Template", htmlFile) {
		return execHtmlFile();
	}

	// 定义一个返回fastDFS文件下载地址接口
	// 定义描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.download.summary"), TemplateFileDFS, StringJsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT_NOPARAM(API_M_POST, "/file/downloadTemplateDFS", TemplateFileDFS, execTemplateFileDFS());
	//ENDPOINT(API_M_POST, "/file/downloadTemplateDFS", TemplateFileDFS) {
	//	return execTemplateFileDFS();
	//}必须得返回response类

private: // 定义接口执行函数

	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);
	// 执行HTML文件处理
	std::shared_ptr<OutgoingResponse> execHtmlFile(std::shared_ptr<IncomingRequest> request);
	// 执行导入模板文件下载处理
	std::shared_ptr<OutgoingResponse> execTemplateFile(void);
	// 执行导入模板文件HTML文件处理
	std::shared_ptr<OutgoingResponse> execHtmlFile(void);
	// 执行从fastDFS下载处理
	StringJsonVO::Wrapper execTemplateFileDFS(void);

	//fastDFS下载文件名字
	std::string templateDownloadPath="";

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_TEMPLATEFILECONTROLLER_H_