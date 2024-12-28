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


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class MyfileController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// Xhaizi
	// 2 ����������������
	API_ACCESS_DECLARE(MyfileController);
	// 3 ����ӿ�
public:
	// 3.1 ����һ�����ļ��ϴ�
	// ��������
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("myfile.summary.upload"), uploadFile, Uint64JsonVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/companynetdisk/myfile-upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request, authObject->getPayload()));

	//���ؽӿ�
	ENDPOINT_INFO(downloadFile) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("myfile.summary.download"), StringJsonVO::Wrapper);
		// ��������·������˵��
		//API_DEF_ADD_PATH_PARAMS(String, "xid", ZH_WORDS_GETTER("myfile.filed.xid"), "2111", true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/companynetdisk/myfile-download/{xid}", downloadFile, PATH(String, xid), execDownloadFile(xid));

	//3.3 ����ɾ���ļ�
	ENDPOINT_INFO(removeSample) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("myfile.summary.delete"), StringJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "xid", ZH_WORDS_GETTER("myfile.filed.xid"), "2111", true);
	}
	// 3.3 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/companynetdisk/myfile-delete/{xid}", removeSample, PATH(String, xid), execRemoveSample(xid, authObject->getPayload()));

	// 3.4 �����滻�ļ��ӿڴ���
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("myfile.summary.replacement"), modifyMyfile, Uint64JsonVO::Wrapper);
	// 3.2 �����滻�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/companynetdisk/modify-myfile", modifyMyfile, REQUEST(std::shared_ptr<IncomingRequest>, request), execModifySample(request, authObject->getPayload()));

	// Yu
	// ��ȡָ��Ŀ¼�����б�ӿ�
	ENDPOINT_INFO(queryFileInfo) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Myfile.get.summary_folder"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(FileInfoPageJsonVO);
		// ��ӷ�ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ���������ѯ��������
		//Ŀ¼id
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("Myfile.folder.xid"), "123456", false);
	}
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/companynetdisk/folder-query", queryFileInfo, FileInfoQUERY, executeQueryFileInfo(query));
	/////Myfile-get/folder-info   QueryParams, queryParams,
	//ENDPOINT(API_M_GET, "companynetdisk/folder-query/{xid}", queryFileInfo, QUERIES(QueryParams, queryParams), PATH(String, xid), API_HANDLER_AUTH_PARAME) {
	//	// ������ѯ����ΪQuery����ģ��
	//	API_HANDLER_QUERY_PARAM(fileQuery, FileInfoQUERY, queryParams);
	//	// ����ִ�к�����Ӧ���
	//	API_HANDLER_RESP_VO(executeQueryFileInfo(fileQuery, authObject->getPayload(), xid));
	//}
	

	
	// ���Ŀ¼�ӿ�
	ENDPOINT_INFO(addFolder) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Myfile.add.summary_folder"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/companynetdisk/folder-add", addFolder, BODY_DTO(FolderAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeAddFileInfo(dto));
	}

private:
	//	Xhaizi
	// 1��ִ�е��ļ��ϴ�����
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request, const  PayloadDTO& payload);
	// 2��ִ���ļ����ش���
	StringJsonVO::Wrapper execDownloadFile(const String& xid);
	// 3�� ��ʾɾ���ļ�
	StringJsonVO::Wrapper execRemoveSample(const String& xid, const  PayloadDTO& payload);
	// 4�� ��ʾ�滻�ļ�
	StringJsonVO::Wrapper execModifySample(std::shared_ptr<IncomingRequest> request, const  PayloadDTO& payload);


	//	Yu
	// ��ȡָ��Ŀ¼�����б�
	FileInfoPageJsonVO::Wrapper executeQueryFileInfo(const FileInfoQUERY::Wrapper& query);
	// ���Ŀ¼
	Uint64JsonVO::Wrapper executeAddFileInfo(const FolderAddDTO::Wrapper& dto);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MYFILE_CONTROLLER_