#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/01 17:39:36

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
#ifndef _MENUSETTINGCONTROLLER_H_
#define _MENUSETTINGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/mymenu/nametree/MyMenuInfoJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/query/mymenu/nametree/MyMenuInfoQuery.h"



#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class MenuSettingController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(MenuSettingController);
public:
	//��ȡ�˵���Ϣ
	ENDPOINT_INFO(MenuInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("suixin.menuinfo.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(MyMenuInfoJsonVO);
		//// ����������ѯ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "menu_name", ZH_WORDS_GETTER("menu.setting.field.id"), "name", false);

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/resource-management/menu-nametree", MenuInfo, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {/*, API_HANDLER_AUTH_PARAME*/
		//// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(menuinfoQuery, MyMenuInfoQuery, queryParams);
		// ����ִ�к�����Ӧ��� 
		API_HANDLER_RESP_VO(execMenuInfo(menuinfoQuery, authObject->getPayload()));/* , authObject->getPayload()*/
	}
private:
	MyMenuInfoJsonVO::Wrapper execMenuInfo(const MyMenuInfoQuery::Wrapper& query, const PayloadDTO& payload); /*, const PayloadDTO& payload*/
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_