#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/16 17:02:58

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
#ifndef _MENUUSEAUTORITYVO_H_
#define _MENUUSEAUTORITYVO_H_
#include "../../../GlobalInclude.h"
#include "../../../dto/mymenu/useautority/MenuUseAutorityDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)



//class MenuUseAutorityVO : public oatpp::DTO
//{
//	DTO_INIT(MenuUseAutorityVO, DTO);
//	//����Ψһ��ʶ��Ȩ��ID
//	API_DTO_FIELD_DEFAULT(UInt64, Aid, ZH_WORDS_GETTER("menu.authority.field.id"));
//	//�˵�ID
//	API_DTO_FIELD_DEFAULT(UInt64, Mid, ZH_WORDS_GETTER("menu.setting.field.id"));
//	//�˵�����Ȩ������
//	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("menu.authority.field.name"));
//	//�˵�����Ȩ��ӵ����
//	API_DTO_FIELD_DEFAULT(UInt64, userid, ZH_WORDS_GETTER("menu.authority.field.userid"));
//	//�˵�Ȩ������
//	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("menu.authority.field.type"));
//	//�˵�Ȩ��״̬  ���������ر�
//	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("menu.authority.field.status"));
//
//
//};

/**
 * ����һ��ʾ���˵���ʾJsonVO����������Ӧ��ǰ��
 */
class MenuUseAutorityJsonVO : public JsonVO<MenuUseAutorityDTO::Wrapper>
{
	DTO_INIT(MenuUseAutorityJsonVO, JsonVO<MenuUseAutorityDTO::Wrapper>);

};

class MenuUseAutorityPageJsonVO : public JsonVO<MenuUseAutorityPageDTO::Wrapper> {
	DTO_INIT(MenuUseAutorityPageJsonVO, JsonVO<MenuUseAutorityPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUVO_H_