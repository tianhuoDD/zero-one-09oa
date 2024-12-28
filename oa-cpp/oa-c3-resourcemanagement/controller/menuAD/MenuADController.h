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
#ifndef _USERCONTROLLER_H_
#define _USERCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/menuAD/MenuADDTO.h"
#include "domain/GlobalInclude.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class MenuADController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(MenuADController);

public:
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addMenu) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("menu.addmenu.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/resource-management/add-menu", addMenu, BODY_DTO(MenuADDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddMenu(dto));
	}

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(deletMenu) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("menu.deletmenu.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "menu_id", ZH_WORDS_GETTER("menu.info.menu_id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/resource-management/delet-menu/{menu_id}", deletMenu, PATH(String, menu_id), execRemoveMenu(menu_id));

private:
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddMenu(const MenuADDTO::Wrapper& dto);
	
	// 3.3 ��ʾɾ������
	StringJsonVO::Wrapper execRemoveMenu(const string& id);

};
	

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_