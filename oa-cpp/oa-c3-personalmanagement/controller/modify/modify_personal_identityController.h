#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/23 1:05:55

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
#ifndef _MODIFY_PERSONAL_IDENTITYCONTROLLER_
#define _MODIFY_PERSONAL_IDENTITYCONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/modify/modify_personal_identityDTO.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class modify_personalidentityController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(modify_personalidentityController);
	// 3 ����ӿ�
public:
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("sample.put.summary"), modifySample, StringJsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "personal-management/modify-personal-identity", modifySample, BODY_DTO(modify_personal_identityDTO::Wrapper, dto), execModify_personalidentity(dto));

private:
	// 3.3 ��ʾ�޸�����
	StringJsonVO::Wrapper execModify_personalidentity(const modify_personal_identityDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_