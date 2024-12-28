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
#ifndef _MYFILE_CONTROLLER_
#define _MYFILE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/myfile/MyfileDTO.h"
#include "domain/vo/myfile/MyfileVO.h"
#include "domain/vo/myfile/FileInfoVO.h"
#include "domain/dto/myfile/FileInfoDTO.h"
#include "domain/query/myfile/FileInfoQUERY.h"
#include "domain/dto/folder/folderaddDTO.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class MyfileController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// Xhaizi
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(MyfileController);
	// 3 定义接口
public:
	// 3.1 定义一个单文件上传
	// 定义描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("myfile.summary.upload"), uploadFile, Uint64JsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/companynetdisk/myfile-upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request, authObject->getPayload()));

	//下载接口
	ENDPOINT_INFO(downloadFile) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("myfile.summary.download"), StringJsonVO::Wrapper);
		// 定义其他路径参数说明
		//API_DEF_ADD_PATH_PARAMS(String, "xid", ZH_WORDS_GETTER("myfile.filed.xid"), "2111", true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/companynetdisk/myfile-download/{xid}", downloadFile, PATH(String, xid), execDownloadFile(xid));

	//3.3 定义删除文件
	ENDPOINT_INFO(removeSample) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("myfile.summary.delete"), StringJsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "xid", ZH_WORDS_GETTER("myfile.filed.xid"), "2111", true);
	}
	// 3.3 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/companynetdisk/myfile-delete/{xid}", removeSample, PATH(String, xid), execRemoveSample(xid, authObject->getPayload()));

	// 3.4 定义替换文件接口处理
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("myfile.summary.replacement"), modifyMyfile, Uint64JsonVO::Wrapper);
	// 3.2 定义替换接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/companynetdisk/modify-myfile", modifyMyfile, REQUEST(std::shared_ptr<IncomingRequest>, request), execModifySample(request, authObject->getPayload()));

	// Yu
	// 获取指定目录内容列表接口
	ENDPOINT_INFO(queryFileInfo) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Myfile.get.summary_folder"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(FileInfoPageJsonVO);
		// 添加分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 添加其他查询参数描述
		//目录id
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("Myfile.folder.xid"), "123456", false);
	}
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/companynetdisk/folder-query", queryFileInfo, FileInfoQUERY, executeQueryFileInfo(query));
	/////Myfile-get/folder-info   QueryParams, queryParams,
	//ENDPOINT(API_M_GET, "companynetdisk/folder-query/{xid}", queryFileInfo, QUERIES(QueryParams, queryParams), PATH(String, xid), API_HANDLER_AUTH_PARAME) {
	//	// 解析查询参数为Query领域模型
	//	API_HANDLER_QUERY_PARAM(fileQuery, FileInfoQUERY, queryParams);
	//	// 呼叫执行函数响应结果
	//	API_HANDLER_RESP_VO(executeQueryFileInfo(fileQuery, authObject->getPayload(), xid));
	//}
	

	
	// 添加目录接口
	ENDPOINT_INFO(addFolder) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Myfile.add.summary_folder"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/companynetdisk/folder-add", addFolder, BODY_DTO(FolderAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeAddFileInfo(dto));
	}

private:
	//	Xhaizi
	// 1、执行单文件上传处理
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request, const  PayloadDTO& payload);
	// 2、执行文件下载处理
	StringJsonVO::Wrapper execDownloadFile(const String& xid);
	// 3、 演示删除文件
	StringJsonVO::Wrapper execRemoveSample(const String& xid, const  PayloadDTO& payload);
	// 4、 演示替换文件
	StringJsonVO::Wrapper execModifySample(std::shared_ptr<IncomingRequest> request, const  PayloadDTO& payload);


	//	Yu
	// 获取指定目录内容列表
	FileInfoPageJsonVO::Wrapper executeQueryFileInfo(const FileInfoQUERY::Wrapper& query);
	// 添加目录
	Uint64JsonVO::Wrapper executeAddFileInfo(const FolderAddDTO::Wrapper& dto);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MYFILE_CONTROLLER_