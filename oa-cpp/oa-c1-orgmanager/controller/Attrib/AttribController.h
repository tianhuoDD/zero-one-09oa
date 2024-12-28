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
#ifndef _ATTRIB_CONTROLLER_
#define _ATTRIB_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Attrib/AttribQuery.h"
#include "domain/dto/Attrib/AttribDTO.h"
#include "domain/vo/Attrib/AttribVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class AttribController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(AttribController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	/*ENDPOINT_INFO(queryAttrib) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Attrib.query-all.title"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AttribPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("Attrib.query-all.name"), " ", false);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "id", ZH_WORDS_GETTER("Attrib.query-all.id"), 1, false);
	}//ɾ����mediator�Ĳ�ѯ����
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/Attrib", queryAttrib, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, AttribQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAttrib(userQuery));//, authObject->getPayload()
	}
	*/
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addAttrib) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Attrib.add-all.title"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/c1-org/Attrib", addAttrib, BODY_DTO(AttribDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddAttrib(dto));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("Attrib.modify-all.title"), modifyAttrib, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c1-org/Attrib", modifyAttrib, BODY_DTO(AttribDTO::Wrapper, dto), execModifyAttrib(dto));

	//// 3.1 ����ɾ���ӿ�����
	//ENDPOINT_INFO(removeAttrib) {
	//	// �������ͷ��������Լ���Ȩ֧��
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("Attrib.delete-all.title"), Uint64JsonVO::Wrapper);
	//	// ��������·������˵��
	//	API_DEF_ADD_PATH_PARAMS(String, "name", ZH_WORDS_GETTER("Attrib.delete-all.name"), "", true);
	//	API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("Attrib.delete-all.id"), 1, true);
	//	API_DEF_ADD_PATH_PARAMS(String, "value", ZH_WORDS_GETTER("Attrib.delete-all.attrib"), "", true);
	//}
	//// 3.2 ����ɾ���ӿڴ���
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/Attrib", removeAttrib, PATH(UInt64, id), execRemoveAttrib(id));

	//// 3.1 �����������ʽ������õĽӿ�1����
	//ENDPOINT_INFO(queryOne) {
	//	// �������ͷ��������Լ���Ȩ֧��
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("sample.query-one.summary"), SampleJsonVO::Wrapper);
	//	// ��������·������˵��
	//	API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.id"), 1, true);
	//}
	//// 3.2 �����������ʽ������õĽӿ�1����
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/sample/query-one", queryOne, QUERY(UInt64, id), execQueryOne(id, authObject->getPayload()));

	//// 3.1 �����������ʽ������õĽӿ�2����
	//ENDPOINT_INFO(queryAll) {
	//	// �������ͷ��������Լ���Ȩ֧��
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("sample.query-all.summary"), SamplePageJsonVO::Wrapper);
	//	// �����ҳ��ѯ��������
	//	API_DEF_ADD_PAGE_PARAMS();
	//	// ����������ѯ��������
	//	API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
	//}
	//// 3.2 �����������ʽ������õĽӿ�1����
	//API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/sample/query-all", queryAll, SampleQuery, execQueryAll(query, authObject->getPayload()));
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	AttribPageJsonVO::Wrapper execQueryAttrib(const AttribQuery::Wrapper& query);//, const PayloadDTO& payload
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddAttrib(const AttribDTO::Wrapper& dto);
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyAttrib(const AttribDTO::Wrapper& dto);
	//// 3.3 ��ʾɾ������
	//Uint64JsonVO::Wrapper execRemoveAttrib(const UInt64& id);
	//// 3.3 ��������ʽ�������1
	//AttribJsonVO::Wrapper execQueryOne(const UInt64& id, const PayloadDTO& payload);
	//// 3.3 ��������ʽ�������2
	//AttribPageJsonVO::Wrapper execQueryAll(const AttribQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_