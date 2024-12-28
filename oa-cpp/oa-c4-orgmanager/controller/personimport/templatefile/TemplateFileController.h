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
 * ģ���ļ������ӿ�
 */
class TemplateFileController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(TemplateFileController);
public:

	//// ����һ���ļ����ؽӿ�
	//// ��������
	//ENDPOINT_INFO(downloadFile) {
	//	API_DEF_ADD_COMMON(ZH_WORDS_GETTER("file.download.summary"), Void);
	//	API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.filename"), "file/templateTest.excel", true);
	//}
	//// ����˵�
	//ENDPOINT(API_M_GET, "/file/downloadTemplate", downloadFile, QUERY(String, filename)) {
	//	return execDownloadFile(filename);
	//}

	// ����һ������ģ������ؽӿ�
	// ��������
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.download.summary"), TemplateFile, Void);
	// ����˵�
	ENDPOINT(API_M_GET, "/file/downloadTemplate", TemplateFile) {
		return execTemplateFile();
	}


	//// ����һ������ģ����HTML�ļ��ӿ�
	//// ��������
	//API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.html.summary"), htmlFile, Void);
	//// ����˵�
	//ENDPOINT(API_M_GET, "/file/**", htmlFile, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
	//	return execHtmlFile(request);
	//}

	// ����һ������ģ����HTML�ļ��ӿ�
	// ��������
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.html.summary"), htmlFile, Void);
	// ����˵�
	ENDPOINT(API_M_GET, "/file/Template", htmlFile) {
		return execHtmlFile();
	}

	// ����һ������fastDFS�ļ����ص�ַ�ӿ�
	// ��������
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.download.summary"), TemplateFileDFS, StringJsonVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT_NOPARAM(API_M_POST, "/file/downloadTemplateDFS", TemplateFileDFS, execTemplateFileDFS());
	//ENDPOINT(API_M_POST, "/file/downloadTemplateDFS", TemplateFileDFS) {
	//	return execTemplateFileDFS();
	//}����÷���response��

private: // ����ӿ�ִ�к���

	// ִ���ļ����ش���
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);
	// ִ��HTML�ļ�����
	std::shared_ptr<OutgoingResponse> execHtmlFile(std::shared_ptr<IncomingRequest> request);
	// ִ�е���ģ���ļ����ش���
	std::shared_ptr<OutgoingResponse> execTemplateFile(void);
	// ִ�е���ģ���ļ�HTML�ļ�����
	std::shared_ptr<OutgoingResponse> execHtmlFile(void);
	// ִ�д�fastDFS���ش���
	StringJsonVO::Wrapper execTemplateFileDFS(void);

	//fastDFS�����ļ�����
	std::string templateDownloadPath="";

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_TEMPLATEFILECONTROLLER_H_