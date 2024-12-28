#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wangye
 @Date: 2024/10/20 16:17:49

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
#ifndef _MENUINFOCONTROLLER_H_
#define _MENUINFOCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/menuinfo/MenuInfoVO.h"
#include "domain/dto/menuinfo/MenuInfoDTO.h"
#include "domain/query/menuinfo/MenuInfoQuery.h"
#include "../ApiDeclarativeServicesHelper.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MenuInfoController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(MenuInfoController);
public: // ����ӿ�
	// ��ȡ�˵���Ϣ�ӿ�
	//// 1.1 �����ѯ�ӿڴ���
	////* �ϸ���arch-demo��д�ķ�ʽ  *�������д���Ĳ��������� �ӿڵ�ַ + �ӿڵ�����Ҳ���Ƿ����� + ��ѯ����
	//ENDPOINT_INFO(queryMenuInfo) {
	//	// �������ͷ��������Լ���Ȩ֧��
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("menuinfo.get.summary"), MenuInfoJsonVO::Wrapper);
	//	// ��������·������˵��
	//	API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("menuinfo.field.id"), 007, true);
	//}
	//// 1.2 �����ѯ�ӿڴ���
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/query-menuinfo/queryone", queryMenuInfo, QUERY(UInt64, id), executeQueryMenuInfo(id, authObject->getPayload()));

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryMenuInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("menuinfo.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(MenuInfoJsonVO);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "resource-management/query-menuinfo/queryone/{menu_id}", queryMenuInfo, PATH(String, menu_id), API_HANDLER_AUTH_PARAME) {
		// ������ͷ���ȡid
		//String menu_id = authObject->getPayload().getId();
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeQueryMenuInfo(menu_id));
	}


	
	// *�޸Ĳ˵���Ϣ�ӿڣ��޸Ľӿ���Ҫ�Ǹñ��˽ӿڷ���ֵ�����͸ĳ���StringJsonVO���±�privateҲ���Ÿı䣬����controller.cpp��ĺ��������ķ������ͣ�����Ҫ������һ���иı䣩
	// 2.1 �����޸Ĳ˵���Ϣ�ӿ����� *�������д���Ĳ��������� ����ע�� + �ӿڵ�����Ҳ���Ƿ����� + ��Ӧ���
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("menuinfo.put.summary"), modifyMenuInfo, StringJsonVO::Wrapper);  //*StringJsonVO���StringJsonVO ���Ƿ���һ���ɹ�ʱ��Ψһ��ʶ�� ����1 ���������StringJsonVO�Ǿ��Ƿ���һ�������ݵ�menu_id
	// 2.2 �����޸Ĳ˵���Ϣ�ӿڴ��� *�������д���Ĳ��������� �ӿ�·�� + �ӿڵ�����Ҳ���Ƿ����� + �޸�ʱ�õ���DTO + �޸Ĳ�����Ӧ��ִ�к���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "resource-management/post-menuinfo", modifyMenuInfo, BODY_DTO(MenuInfoDTO::Wrapper, dto), executeModifyMenuInfo(dto));



private: // ����ӿ�ִ�к���
	// ִ�л�ȡ�˵���Ϣ *����menu_id���Ͳ���
	MenuInfoJsonVO::Wrapper executeQueryMenuInfo(const String& menu_id);
	// ִ���޸Ĳ˵���Ϣ *����DTO���Ͳ���
	StringJsonVO::Wrapper executeModifyMenuInfo(const MenuInfoDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_MENUINFOCONTROLLER_H_