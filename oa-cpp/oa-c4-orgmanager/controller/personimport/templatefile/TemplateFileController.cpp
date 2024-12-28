/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 11:37:57

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
#include "stdafx.h"
#include <iostream>
#include "TemplateFileController.h"
#include "service/templateFileService/templateFileService.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

//xlnt��Ҫ�����ͷ
#include "ExcelComponent.h"
//#define TEMPLATE_EXCEL_FN "./public/excel/1.xlsx"
//#define TEMPLATE_EXCEL_SN ZH_WORDS_GETTER("excel.sheet.s1")




std::string uploadFileToFast(std::string& errString) {


	
	/* ��ӡ�ļ����� */
	string filename = "templatePersonImport.xlsx";
	OATPP_LOGD("uploadFileToFastDFS", "uploadFile='%s'", filename.c_str());
	/* ���Խ��ļ����浽�������� */
	string fullPath = "public/static/file/" + filename;


	/* �����ϴ���FastDFS */
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	// ��ȡ�ļ���׺��
	string suffix = "";
	size_t pos = filename.rfind(".");
	if (pos != string::npos)
	{
		suffix = filename.substr(pos + 1);
	}
	// �ϴ��ļ�
	string downloadUrl = dfs.uploadFile(fullPath);
	string dfsres = downloadUrl;
	downloadUrl = urlPrefix + downloadUrl;
	OATPP_LOGD("fastDFS", "download url='%s'", downloadUrl.c_str());
	
	
	////�����ݿ⹹��const std::vector<std::vector<std::string>>& data
	//std::vector<std::vector<std::string>> data;
	//
	//templateFileService templateFileService;
	//templateFileService.build(data);
	//
	//// �ж��Ƿ�ɹ������ݿ�ȡ������
	//if (data.empty()) {
	//	errString = "Failed load data from MySQL ";
	//	return "";
	//}


	////excel����writeVectorToBuff ����std::vector<std::uint8_t>
	//ExcelComponent excel;
	//std::vector<std::uint8_t>& excelBuffer = excel.writeVectorToBuff("sheet1",data);

	//        
	////buff�ֽ������ļ��ϴ���fastDFS�������ļ����ص�ַ
	////std::string uploadFile(const char* buff, size_t size, const std::string& extName = "");
	//std::string downloadPath;
	////= uploadFile(excelBuffer, excelBuffer.size(), "xlsx");
	//// �ж��Ƿ��ϴ��ɹ�
	//if ("" == downloadPath)
	//{
	//	std::cerr << "Failed uploadFile to fastDFS: " << std::strerror(errno) << std::endl;
	//	errString = "Failed uploadFile to fastDFS: " + std::string(std::strerror(errno));
	//	return "";
	//}

	if (dfsres.empty()) {
		return dfsres;
	}
	return downloadUrl;


}

void modifyYamlLPNode(YAML::Node& node,string dPath) {
	ofstream fout("zh-dict.yaml");
	if (!fout.is_open()) {
		std::cerr<< "modifyYamlLPNode -> " << "Failed to open file: " << "zh-dict.yaml" << std::endl;
		return;
	}

	node["file"]["templateDownloadPath"] = dPath;

	fout << node;

	fout.close();
}

StringJsonVO::Wrapper TemplateFileController::execTemplateFileDFS()
{
	
	//// �ж�ģ���ļ����ص�ַ�Ƿ�Ϊ��
	//if ((this->templateDownloadPath).empty()) //stringδ��ʼ�����ʳ�Ա����->δ������Ϊ��Ҫ��ʼ��Ϊ""
	//{
	//	std::string errString;
	//	std::string dfsRes = uploadFileToFast(errString);
	//	if ("" == dfsRes) {
	//		
	//		auto jvo = StringJsonVO::createShared();
	//		jvo->fail(errString);
	//		return jvo;
	//	}
	//	else {
	//		this->templateDownloadPath = dfsRes;
	//	}
	//}

	///* ��Ӧ��fastDFS��ȡ�����ص�ַ */
	//auto jvo = StringJsonVO::createShared();
	//jvo->success(this->templateDownloadPath);
	//return jvo;

	//���ɾ��ÿ��������Ҫ������޹��ɵ�xlsx�ļ�?
	//1.����conf/�ļ���templateDownloadPath.yaml������ļ���templateDownloadPath
	//2.����zh-dict.yaml��ͨ��yamlhelper���� YAML::Node����node,node["templateDownloadPath"]=templateDownloadPath
	string lastPath = ZH_WORDS_GETTER("file.templateDownloadPath");
	if (lastPath.empty()) {
		// �ж�ģ���ļ����ص�ַ�Ƿ�Ϊ��
		if ((this->templateDownloadPath).empty()) //stringδ��ʼ�����ʳ�Ա����->δ������Ϊ��Ҫ��ʼ��Ϊ""
		{
			std::string errString;
			std::string dfsRes = uploadFileToFast(errString);
			if ("" == dfsRes) {

				auto jvo = StringJsonVO::createShared();
				jvo->fail(errString);
				return jvo;
			}
			else {
				this->templateDownloadPath = dfsRes;
				//д��yaml�ļ�
				modifyYamlLPNode((ServerInfo::getInstance().getZhDictNode()),this->templateDownloadPath);
			}
		}
	}
	else {
		this->templateDownloadPath = lastPath;
	}

	/* ��Ӧ��fastDFS��ȡ�����ص�ַ */
	auto jvo = StringJsonVO::createShared();
	jvo->success(this->templateDownloadPath);
	return jvo;

}


std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> TemplateFileController::execTemplateFile()
{
	const String& filename="templatePersonImport.xlsx";
	// �����ļ�ȫ·��
	std::string fullPath = "public/static/file/" + URIUtil::urlDecode(filename.getValue(""));

	// ��ȡ�ļ�
	auto fstring = String::loadFromFile(fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// Ӱ��ɹ����
	return response;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> TemplateFileController::execHtmlFile()
{
	// ��ȡ�ļ�·��
	const String& filename = "templatePersonImport.xlsx";

	// �����ļ�ȫ·��
	std::string fullPath = "public/static/file/" + filename.getValue("");

	// ��ȡ�ļ�
	auto fstring = String::loadFromFile(fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file<" << filename.getValue("") << ">: " << std::strerror(errno) << std::endl;
		const char* html = R"(
			<html>
             <head><title>404</title></head>
			 <body>
			  <h1>Page Not Found</h1>
			 </body>
			</html>)";
		auto response = createResponse(Status::CODE_404, html);
		response->putHeader(Header::CONTENT_TYPE, "text/html");
		return response;
	}

	// ������Ӧ����
	auto response = createResponse(Status::CODE_200, fstring);

	// �����ļ���ͬ�������ò�ͬ��Ӧͷ���п���HTML�а���js��css�ļ���ͼƬ�ݲ�����
	if (filename->find(".js") != string::npos)
		response->putHeader(Header::CONTENT_TYPE, "text/javascript; charset=utf-8");
	else if (filename->find(".css") != string::npos)
		response->putHeader(Header::CONTENT_TYPE, "text/css");
	else
		response->putHeader(Header::CONTENT_TYPE, "text/html");

	// ��Ӧ���
	return response;
}


std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> TemplateFileController::execDownloadFile(const String& filename)
{
	// �����ļ�ȫ·��
	std::string fullPath = "public/static/" + URIUtil::urlDecode(filename.getValue(""));

	// ��ȡ�ļ�
	auto fstring = String::loadFromFile(fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// Ӱ��ɹ����
	return response;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> TemplateFileController::execHtmlFile(std::shared_ptr<IncomingRequest> request)
{
	// ��ȡ�ļ�·��
	auto filename = request->getPathTail();

	// �����ļ�ȫ·��
	std::string fullPath = "public/" + filename.getValue("");

	// ��ȡ�ļ�
	auto fstring = String::loadFromFile(fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file<" << filename.getValue("") << ">: " << std::strerror(errno) << std::endl;
		const char* html = R"(
			<html>
             <head><title>404</title></head>
			 <body>
			  <h1>Page Not Found</h1>
			 </body>
			</html>)";
		auto response = createResponse(Status::CODE_404, html);
		response->putHeader(Header::CONTENT_TYPE, "text/html");
		return response;
	}

	// ������Ӧ����
	auto response = createResponse(Status::CODE_200, fstring);

	// �����ļ���ͬ�������ò�ͬ��Ӧͷ���п���HTML�а���js��css�ļ���ͼƬ�ݲ�����
	if (filename->find(".js") != string::npos)
		response->putHeader(Header::CONTENT_TYPE, "text/javascript; charset=utf-8");
	else if (filename->find(".css") != string::npos)
		response->putHeader(Header::CONTENT_TYPE, "text/css");
	else
		response->putHeader(Header::CONTENT_TYPE, "text/html");

	// ��Ӧ���
	return response;
}
