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
//	//数据唯一标识，权限ID
//	API_DTO_FIELD_DEFAULT(UInt64, Aid, ZH_WORDS_GETTER("menu.authority.field.id"));
//	//菜单ID
//	API_DTO_FIELD_DEFAULT(UInt64, Mid, ZH_WORDS_GETTER("menu.setting.field.id"));
//	//菜单功能权限名称
//	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("menu.authority.field.name"));
//	//菜单功能权限拥有者
//	API_DTO_FIELD_DEFAULT(UInt64, userid, ZH_WORDS_GETTER("menu.authority.field.userid"));
//	//菜单权限类型
//	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("menu.authority.field.type"));
//	//菜单权限状态  ：开启，关闭
//	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("menu.authority.field.status"));
//
//
//};

/**
 * 定义一个示例菜单显示JsonVO对象，用于响应给前端
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