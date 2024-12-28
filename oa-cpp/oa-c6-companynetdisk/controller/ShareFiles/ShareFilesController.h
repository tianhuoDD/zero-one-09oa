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
#ifndef _SHAREFILESCONTROLLER_H_
#define _SHAREFILESCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include"domain/query/PageQuery.h"
#include "oatpp-swagger/Types.hpp"
#include "domain/GlobalInclude.h"
#include"domain/dto/myfiles/ShareFilesDTO.h"
#include "domain/dto/PayloadDTO.h" 
#include OATPP_CODEGEN_BEGIN(ApiController)

class ShareFilesController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ShareFilesController);
public:
	//	�����ļ��ӿ�
	ENDPOINT_INFO(sharefiles) {

		//��ѯ
		//API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("ShareFiles.field.xid"), "e785616", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "xshareList", ZH_WORDS_GETTER("file.shareid"), "888", false);

		API_DEF_ADD_AUTH();
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Myfile.share.summary"));
		info->addResponse<Object<StringJsonVO>>(Status::CODE_200, "application/json");

		//info->addResponse<String>(Status::CODE_404, "text/plain");
		// ����ӿڱ���
		//API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sample.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}

	ENDPOINT(API_M_POST, "/companynetdisk/myfile-sharefiles", sharefiles, BODY_DTO(ShareFilesDTO::Wrapper, params), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		//API_HANDLER_QUERY_PARAM(condition, ShareFilesDTO, params);
		API_HANDLER_RESP_VO(executeShareFiles(params, authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	StringJsonVO::Wrapper executeShareFiles(const ShareFilesDTO::Wrapper& params, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_SHAREFILESCONTROLLER_H_


