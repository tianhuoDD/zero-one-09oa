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

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

//xlnt需要导入的头
#include "ExcelComponent.h"
//#define TEMPLATE_EXCEL_FN "./public/excel/1.xlsx"
//#define TEMPLATE_EXCEL_SN ZH_WORDS_GETTER("excel.sheet.s1")




std::string uploadFileToFast(std::string& errString) {


	
	/* 打印文件名称 */
	string filename = "templatePersonImport.xlsx";
	OATPP_LOGD("uploadFileToFastDFS", "uploadFile='%s'", filename.c_str());
	/* 测试将文件保存到磁盘上面 */
	string fullPath = "public/static/file/" + filename;


	/* 测试上传到FastDFS */
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	// 获取文件后缀名
	string suffix = "";
	size_t pos = filename.rfind(".");
	if (pos != string::npos)
	{
		suffix = filename.substr(pos + 1);
	}
	// 上传文件
	string downloadUrl = dfs.uploadFile(fullPath);
	string dfsres = downloadUrl;
	downloadUrl = urlPrefix + downloadUrl;
	OATPP_LOGD("fastDFS", "download url='%s'", downloadUrl.c_str());
	
	
	////从数据库构建const std::vector<std::vector<std::string>>& data
	//std::vector<std::vector<std::string>> data;
	//
	//templateFileService templateFileService;
	//templateFileService.build(data);
	//
	//// 判断是否成功从数据库取出数据
	//if (data.empty()) {
	//	errString = "Failed load data from MySQL ";
	//	return "";
	//}


	////excel方法writeVectorToBuff 构建std::vector<std::uint8_t>
	//ExcelComponent excel;
	//std::vector<std::uint8_t>& excelBuffer = excel.writeVectorToBuff("sheet1",data);

	//        
	////buff字节流将文件上传到fastDFS，返回文件下载地址
	////std::string uploadFile(const char* buff, size_t size, const std::string& extName = "");
	//std::string downloadPath;
	////= uploadFile(excelBuffer, excelBuffer.size(), "xlsx");
	//// 判断是否上传成功
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
	
	//// 判断模板文件下载地址是否为空
	//if ((this->templateDownloadPath).empty()) //string未初始化访问成员函数->未定义行为，要初始化为""
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

	///* 响应从fastDFS获取的下载地址 */
	//auto jvo = StringJsonVO::createShared();
	//jvo->success(this->templateDownloadPath);
	//return jvo;

	//如何删除每次重启都要增多的无规律的xlsx文件?
	//1.存在conf/文件中templateDownloadPath.yaml，如果文件中templateDownloadPath
	//2.存在zh-dict.yaml，通过yamlhelper访问 YAML::Node对象node,node["templateDownloadPath"]=templateDownloadPath
	string lastPath = ZH_WORDS_GETTER("file.templateDownloadPath");
	if (lastPath.empty()) {
		// 判断模板文件下载地址是否为空
		if ((this->templateDownloadPath).empty()) //string未初始化访问成员函数->未定义行为，要初始化为""
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
				//写入yaml文件
				modifyYamlLPNode((ServerInfo::getInstance().getZhDictNode()),this->templateDownloadPath);
			}
		}
	}
	else {
		this->templateDownloadPath = lastPath;
	}

	/* 响应从fastDFS获取的下载地址 */
	auto jvo = StringJsonVO::createShared();
	jvo->success(this->templateDownloadPath);
	return jvo;

}


std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> TemplateFileController::execTemplateFile()
{
	const String& filename="templatePersonImport.xlsx";
	// 构建文件全路径
	std::string fullPath = "public/static/file/" + URIUtil::urlDecode(filename.getValue(""));

	// 读取文件
	auto fstring = String::loadFromFile(fullPath.c_str());

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// 影响成功结果
	return response;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> TemplateFileController::execHtmlFile()
{
	// 获取文件路径
	const String& filename = "templatePersonImport.xlsx";

	// 构建文件全路径
	std::string fullPath = "public/static/file/" + filename.getValue("");

	// 读取文件
	auto fstring = String::loadFromFile(fullPath.c_str());

	// 判断是否读取成功
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

	// 创建响应对象
	auto response = createResponse(Status::CODE_200, fstring);

	// 根据文件不同类型设置不同响应头，有可能HTML中包含js和css文件，图片暂不处理
	if (filename->find(".js") != string::npos)
		response->putHeader(Header::CONTENT_TYPE, "text/javascript; charset=utf-8");
	else if (filename->find(".css") != string::npos)
		response->putHeader(Header::CONTENT_TYPE, "text/css");
	else
		response->putHeader(Header::CONTENT_TYPE, "text/html");

	// 响应结果
	return response;
}


std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> TemplateFileController::execDownloadFile(const String& filename)
{
	// 构建文件全路径
	std::string fullPath = "public/static/" + URIUtil::urlDecode(filename.getValue(""));

	// 读取文件
	auto fstring = String::loadFromFile(fullPath.c_str());

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// 影响成功结果
	return response;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> TemplateFileController::execHtmlFile(std::shared_ptr<IncomingRequest> request)
{
	// 获取文件路径
	auto filename = request->getPathTail();

	// 构建文件全路径
	std::string fullPath = "public/" + filename.getValue("");

	// 读取文件
	auto fstring = String::loadFromFile(fullPath.c_str());

	// 判断是否读取成功
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

	// 创建响应对象
	auto response = createResponse(Status::CODE_200, fstring);

	// 根据文件不同类型设置不同响应头，有可能HTML中包含js和css文件，图片暂不处理
	if (filename->find(".js") != string::npos)
		response->putHeader(Header::CONTENT_TYPE, "text/javascript; charset=utf-8");
	else if (filename->find(".css") != string::npos)
		response->putHeader(Header::CONTENT_TYPE, "text/css");
	else
		response->putHeader(Header::CONTENT_TYPE, "text/html");

	// 响应结果
	return response;
}
