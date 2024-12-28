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
#ifndef _MettingCreate_CONTROLLER_
#define _MettingCreate_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/metting/mettingcreate/MettingCreateQuery.h"
#include "domain/dto/metting/mettingcreate/MettingCreateDTO.h"
#include "domain/vo/metting/mettingCreate/MettingCreateVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class MettingCreateController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(MettingCreateController);
	// ����ӿ�
public:
	// ��������Ҳ�ѯ�ӿ�����
	ENDPOINT_INFO(queryroom) {
		// ����ӿڱ���
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("metting.cquery.room"), StringJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	// �����ѯ�ӿڴ���
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/metting/mettingcreate/room", queryroom, MettingRoomQuery, execQueryRoom());
	//
	//ENDPOINT(API_M_GET, "/metting/mettingcreate", queryroom, API_HANDLER_AUTH_PARAME) {API_HANDLER_RESP_VO(execQueryRoom());}

	// hoster query description
	ENDPOINT_INFO(queryhoster) {
		// ����ӿڱ���
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("metting.cquery.hoster"), MettingHostPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("metting.cqury.hoster"), "li ming", true);
	}
	// �����ѯ�ӿڴ���
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/metting/mettingcreate/host", queryhoster, MettingHosterQuery, execQueryHoster(query, authObject->getPayload()));
	// 
	//ENDPOINT(API_M_GET, "/metting/mettingcreate", queryhoster, QUERY(String, name), API_HANDLER_AUTH_PARAME){//����ִ�к�����Ӧ���API_HANDLER_RESP_VO(execQueryHoster(name));}

	//department query description
	ENDPOINT_INFO(querydepart) {
		// ����ӿڱ���
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("metting.cquery.department"), MettingDepartPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "depart", ZH_WORDS_GETTER("metting.cqury.depart"), "bu men", true);
	}
	//department query
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/metting/mettingcreate/depart", querydepart, MettingDepartQuery, execQueryDepart(query, authObject->getPayload()));
	// 
	//ENDPOINT(API_M_GET, "/metting/mettingcreate", querydepart, QUERY(String, depart), API_HANDLER_AUTH_PARAME) {// ����ִ�к�����Ӧ���API_HANDLER_RESP_VO(execQueryDepart(depart));}

	//member decription
	ENDPOINT_INFO(querymember) {
		// ����ӿڱ���
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("metting.cquery.member"), MettingMemebrPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "identify", ZH_WORDS_GETTER("metting.cqury.identify"), "ge ren/shen fen/zu zhi/qun ti", true);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("metting.cqury.name"), "zhang san", true);
	}
	//member query
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/metting/mettingcreate/member", querymember, MettingMemberQuery, execQueryDepart(query, authObject->getPayload()));
	// 
	//ENDPOINT(API_M_GET, "/metting/mettingcreate", querymember, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		//API_HANDLER_QUERY_PARAM(userQuery, MettingMemberQuery, queryParams);
		// ����ִ�к�����Ӧ���API_HANDLER_RESP_VO(execQueryMember(userQuery));}


	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(mettingcreate) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("metting.cquery.cmetting"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(MettingCreateJsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/metting/mettingcreate", mettingcreate, BODY_DTO(MettingCreateDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execMettingCreate(dto));
	}

	
private:
	Uint64JsonVO::Wrapper execMettingCreate(const MettingCreateDTO::Wrapper& dto);

	MettingRoomPageJsonVO::Wrapper execQueryRoom();

	MettingHostPageJsonVO::Wrapper execQueryHoster(const PageQuery::Wrapper& userquery, const PayloadDTO& payload);

	MettingDepartPageJsonVO::Wrapper execQueryDepart(const PageQuery::Wrapper& userquery, const PayloadDTO& payload);

	MettingMemebrPageJsonVO::Wrapper execQueryMember(const PageQuery::Wrapper& userquery, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MettingCreate_CONTROLLER_