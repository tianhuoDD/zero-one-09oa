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

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class GetShareFilesController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(GetShareFilesController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryShareFilesByXunique) {
		// ����ӿڱ��� - ��ȡ�����ļ��б�
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Myfile.file.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetShareFilesPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// �����ļ��ϴ��˲�ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "xperson", ZH_WORDS_GETTER("Myfile.filed.xperson"), "hhh@1434@P", true);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/companynetdisk/query-filelist-by-fileid", queryShareFilesByXunique, QUERIES(QueryParams, param), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪqueryShareFilesByXname����ģ��
		API_HANDLER_QUERY_PARAM(sharefileQuery, GetShareFilesQuery, param);
		//��ȡ���ص�xid
		sharefileQuery->xid = authObject->getPayload().getId();
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execqueryShareFilesByXunique(sharefileQuery));
	}

private:
	GetShareFilesPageJsonVO::Wrapper execqueryShareFilesByXunique(const GetShareFilesQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _GETSHAREFILESCONTROLLER_H_
