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
#ifndef _ORGMEM_CONTROLLER_
#define _ORGMEM_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
//#include "domain/query/sample/SampleQuery.h"
#include "domain/dto/OrgMemDTO.h"
#include "domain/vo/OrgMemVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class OrgMemController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(OrgMemController);
	// 3 ����ӿ�
public:
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addOrgMem) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("add.orgmem"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/c1-org/addorgmem", addOrgMem, BODY_DTO(OrgMemDTO::Wrapper, dto)) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddOrgMem(dto));
	}

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeOrgMem) {
		// �������ͷ��������Լ���Ȩ֧��
		//API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("delete.orgmem"), Uint64JsonVO::Wrapper);
		info->summary = ZH_WORDS_GETTER("delete.orgmem");
		info->addResponse<Uint64JsonVO::Wrapper>(Status::CODE_200, "application/json");
		//API_DEF_ADD_QUERY_PARAMS(String, "orgID", ZH_WORDS_GETTER("sample.field.id"), "[\"1\", \"2\"]", true);
		// ��������·������˵��
		
	}
	// 3.1 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/c1-org/removeorgmem", removeOrgMem, BODY_DTO(OrgMemDTO::Wrapper, dto)) {
		API_HANDLER_RESP_VO(execRemoveOrgMem(dto));
	}

	//3.2 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeJobMem) {
		// �������ͷ��������Լ���Ȩ֧��
		//API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("delete.jobmem"), Uint64JsonVO::Wrapper);
		info->summary = ZH_WORDS_GETTER("delete.jobmem");
		info->addResponse<Uint64JsonVO::Wrapper>(Status::CODE_200, "application/json");
		// ��������·������˵��
		//API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("sample.field.id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/c1-org/removejobmem/{personID}/{dutyID}", removeJobMem, PATH(String, personID), PATH(String, dutyID)) {
		API_HANDLER_RESP_VO(execRemoveJobMem(personID, dutyID));
	}
	ENDPOINT_INFO(addJobMem) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("add.jobmem"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/c1-org/addjobmem/{personID}/{dutyID}", addJobMem, PATH(String, personID),PATH(String, dutyID)) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddJobMem(personID, dutyID));
	}
	
private:
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveOrgMem(const OrgMemDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execRemoveJobMem(const string& personID, const string& dutyID);
	Uint64JsonVO::Wrapper execAddJobMem(const string& personID, const string& dutyID);
	Uint64JsonVO::Wrapper execAddOrgMem(const OrgMemDTO::Wrapper& dto);
};


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_