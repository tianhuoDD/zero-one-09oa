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
#ifndef _MettingRoomList_CONTROLLER_
#define _MettingRoomList_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/metting/mettingroomlist/MettingRoomListQuery.h"
#include "domain/dto/metting/mettingroomlist/MettingRoomListDTO.h"
#include "domain/vo/metting/mettingroomlist/MettingRoomListVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class MettingRoomListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(MettingRoomListController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryroomlist) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("mettingroom.query"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(MettingRoomListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// date
		API_DEF_ADD_QUERY_PARAMS(String, "date1", ZH_WORDS_GETTER("mettingroom.date"), "2024-11-1 22:00:00", false);
		// time
		API_DEF_ADD_QUERY_PARAMS(String, "time1", ZH_WORDS_GETTER("mettingroom.time"), "2205", false);
		// build
		API_DEF_ADD_QUERY_PARAMS(String, "build", ZH_WORDS_GETTER("mettingroom.build"), "123", false);

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/meeting/meetingroom/query-roomlist", queryroomlist, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, MettingRoomListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryRoomList(query));
	}

	


private:
	// 3.3 ��ʾ��ҳ��ѯ����
	MettingRoomListPageJsonVO::Wrapper execQueryRoomList(const MettingRoomListQuery::Wrapper& query);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MettingRoomList_CONTROLLER_