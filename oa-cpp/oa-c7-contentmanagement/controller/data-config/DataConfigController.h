#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/21 21:14:51

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
#ifndef _ADDDATACONFIGCONTROLLER_H_
#define _ADDDATACONFIGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/data-config/DataConfigVO.h"
#include "domain/dto/data-config/DataConfigDTO.h"
#include "../../../lib-oatpp/include/ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class DataConfigController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(DataConfigController);
public: // ����ӿ�
	 //��ȡ������������ӿ�
	ENDPOINT_INFO(queryDataConfig) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("data-config.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DataConfigJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("data-config.field.xid"), "x40b75ee6-3348-405d-a854-be99e7e9ab13id", true);
	}
	ENDPOINT(API_M_GET, "/data/get-dataconfig", queryDataConfig, QUERY(String,id), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryDataConfig(id));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addDataConfig) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("data-config.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/data/add-dataconfig", addDataConfig, BODY_DTO(AddDataConfigDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddDataConfig(dto));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("data-config.put.summary"), modifyDataConfig, StringJsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/data/modify-dataconfig", modifyDataConfig, BODY_DTO(ModifyDataConfigDTO::Wrapper, dto), execModifyDataConfig(dto));

private: // ����ӿ�ִ�к���
	// ִ�л�ȡ������������
	DataConfigJsonVO::Wrapper execQueryDataConfig(const String& id);

	//ִ��������������
	StringJsonVO::Wrapper execAddDataConfig(const AddDataConfigDTO::Wrapper& dto);

	//ִ���޸���������
	StringJsonVO::Wrapper execModifyDataConfig(const ModifyDataConfigDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ADDDATACONFIGCONTROLLER_H_
