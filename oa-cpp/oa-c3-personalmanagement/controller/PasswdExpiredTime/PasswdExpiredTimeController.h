#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/10/20 17:53:33

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
#ifndef _PASSWDEXPIREDTIME_H_
#define _PASSWDEXPIREDTIME_H_

#include "stdafx.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/PasswdExpiredTime/PasswdExpiredTimeDTO.h"
#include "domain/query/PasswdExpiredTime/PasswdExpiredTimeQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class PasswdExpiredTimeController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(PasswdExpiredTimeController)
public: // ����ӿ�
	
	// �������뵽��ʱ��ӿ�����
	ENDPOINT_INFO(passwdExipredTime) {
		// �ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("personal-management.passwd-expired-time.title"));
		
		// ������Ȩ����
		API_DEF_ADD_AUTH();

		// ��Ӧ��ʽ
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);

		// �������
		API_DEF_ADD_QUERY_PARAMS(String, "id",
			ZH_WORDS_GETTER("personal-management.passwd-expired-time.field.id"),
			"1", true);

		API_DEF_ADD_QUERY_PARAMS(String, "date",
			ZH_WORDS_GETTER("personal-management.passwd-expired-time.field.date"),
			"yyyy-mm-dd", true);
	}

	// ���ýӿڴ���
	ENDPOINT(API_M_PUT, "/personal-management/passwd-expired-time",
		passwdExipredTime, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪPasswdExpiredTimeQuery
		API_HANDLER_QUERY_PARAM(query, PasswdExpiredTimeQuery, queryParams);

		// ����ִ�к���
		API_HANDLER_RESP_VO(execSetPasswdExipredTime(query, authObject->getPayload()));
	}

private: // ����ӿ�ִ�к���
	StringJsonVO::Wrapper execSetPasswdExipredTime(const PasswdExpiredTimeQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PASSWDEXPIREDTIME_H_