#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: $DATE$ $HOUR$:$MINUTE$:$SECOND$

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
#ifndef _SENDFILESCONTROLLER_H_
#define _SENDFILESCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include"domain/query/PageQuery.h"
#include "domain/GlobalInclude.h"
#include"domain/dto/myfiles/SendFilesDTO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class SendFilesController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(SendFilesController);
public: // ����ӿ�

	//�����ļ��ӿ�
	ENDPOINT_INFO(sendfiles) {

		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Myfile.send.summary"));
		//info->summary = "�����ļ����û�������Ա༭";
		//info->addConsumes<Object<UserDto>>("application/json");
		info->addResponse<Object<StringJsonVO>>(Status::CODE_200, "application/json");//��������������response
		//info->addResponse<String>(Status::CODE_404, "text/plain");
		// params specific
		//info->queryParams["xid"].description = "wen jian id";
		//info->queryParams["xeditorList"].description = "shou jian ren id";
///����ӿڱ���
		//API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sample.post.summary"));
///����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		///������Ӧ������ʽ
				//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}


	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/companynetdisk/myfile-sendfiles", sendfiles, BODY_DTO(SendFilesDTO::Wrapper, condition), API_HANDLER_AUTH_PARAME) {

		// ����ִ�к�����Ӧ���
		//API_HANDLER_QUERY_PARAM(condition, SendFilesDTO, params);
		API_HANDLER_RESP_VO(executeSendFiles(condition, authObject->getPayload()));
	}

private: // ����ӿ�ִ�к���
	StringJsonVO::Wrapper executeSendFiles(const SendFilesDTO::Wrapper& condition, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_SENDFILESCONTROLLER_H_
