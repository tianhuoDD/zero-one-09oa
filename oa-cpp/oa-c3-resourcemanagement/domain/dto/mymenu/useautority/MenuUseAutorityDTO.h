#pragma once

/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _MENUUSEAUTORITY_DTO_
#define _MENUUSEAUTORITY_DTO_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class MenuUseAutorityDTO : public oatpp::DTO
{
	DTO_INIT(MenuUseAutorityDTO, DTO);
	// 角色工号
	API_DTO_FIELD_DEFAULT(String, role_id, ZH_WORDS_GETTER("suixin.usepower.role_id"));
	//菜单权限
	API_DTO_FIELD_DEFAULT(String, menulist, ZH_WORDS_GETTER("suixin.usepower.menulist"));
	// 排序号(可选)
	API_DTO_FIELD_DEFAULT(Int32, xorderColumn, ZH_WORDS_GETTER("suixin.usepower.xorderColumn"));


	////子节点数据组
	//API_DTO_FIELD(List<MenuDTO::Wrapper>, children, ZH_WORDS_GETTER("user.field.menusub"), false, {});

};


class MenuUseAutorityPageDTO : public PageDTO<MenuUseAutorityDTO::Wrapper>
{
	DTO_INIT(MenuUseAutorityPageDTO, PageDTO<MenuUseAutorityDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_