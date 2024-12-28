﻿#pragma once

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
#ifndef _MYMENUINFO_DTO_
#define _MYMENUINFO_DTO_
#include "../../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class MyMenuInfoDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(MyMenuInfoDTO, DTO);
	// 编号
	API_DTO_FIELD_DEFAULT(String, menu_id, ZH_WORDS_GETTER("suixin.menuinfo.menu_id"));
	// 组织名称
	API_DTO_FIELD_DEFAULT(String, menu_name, ZH_WORDS_GETTER("suixin.menuinfo.menu_name"));
	//上级组织
	API_DTO_FIELD_DEFAULT(String, parent_id, ZH_WORDS_GETTER("suixin.menuinfo.parent_id"));
	//所在层数，用于快速查询同层结点 
	API_DTO_FIELD_DEFAULT(Int64, level, ZH_WORDS_GETTER("suixin.menuinfo.level"));
	/*图片*/
	API_DTO_FIELD_DEFAULT(String, icon, ZH_WORDS_GETTER("suixin.menuinfo.icon"));
	 //子菜单
	API_DTO_FIELD(List<MyMenuInfoDTO::Wrapper>, children, ZH_WORDS_GETTER("suixin.menuinfo.children"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<MyMenuInfoDTO>(child), Wrapper::Class::getType()));
	}

};



class MyMenuInfoPageDTO : PageDTO<MyMenuInfoDTO::Wrapper>
{
	DTO_INIT(MyMenuInfoPageDTO, PageDTO<MyMenuInfoDTO::Wrapper>);

	API_DTO_FIELD_DEFAULT(String, menu_id, ZH_WORDS_GETTER("menu.setting.field.id"));
	// 组织名称
	API_DTO_FIELD_DEFAULT(String, menu_name, ZH_WORDS_GETTER("menu.setting.field.id"));
	//上级组织
	API_DTO_FIELD_DEFAULT(String, parent_id, ZH_WORDS_GETTER("menu.setting.field.id"));
	//所在层数，用于快速查询同层结点 
	API_DTO_FIELD_DEFAULT(Int64, level, ZH_WORDS_GETTER("menu.setting.field.id"));
	/*图片*/
	API_DTO_FIELD_DEFAULT(String, icon, ZH_WORDS_GETTER("suixin.menuinfo.icon"));

	API_DTO_FIELD(List<MyMenuInfoPageDTO::Wrapper>, children, ZH_WORDS_GETTER("menu.setting.field.id"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child)
	{
		children->push_back(Wrapper(dynamic_pointer_cast<MyMenuInfoPageDTO>(child), Wrapper::Class::getType()));
	}
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_