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
#ifndef _GETSHAREUSERSCONTROLLER_H_
#define _GETSHAREUSERSCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/getting/file/GetShareUsersVO.h"
#include "domain/query/getting/file/GetShareUsersQuery.h"
#include "domain/dto/getting/file/GetShareUsersDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class GetShareUsersController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(GetShareUsersController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryShareUsersByXunique) {
		// ����ӿڱ��� - ��ȡ�û��б�
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Myfile.user.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetShareUsersPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// �����ļ�����ѯ
		//API_DEF_ADD_QUERY_PARAMS(String, "xunique", ZH_WORDS_GETTER("Myfile.user.shareid"), "123", true);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/companynetdisk/query-userlist-by-fileid", queryShareUsersByXunique, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(shareuserQuery, GetShareUserQuery, params);
		//�Ӹ��ػ�ȡ��¼�û���id
		shareuserQuery->xid = authObject->getPayload().getId();
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execqueryShareUsersByXunique(shareuserQuery));
	}

private:
	GetShareUsersPageJsonVO::Wrapper execqueryShareUsersByXunique(const GetShareUserQuery::Wrapper& query);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _GETSHAREUSERSCONTROLLER_H_