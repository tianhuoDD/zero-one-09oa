#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: dingfengchuan
 @Date: 2024年11月1日

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
#ifndef _MENUDTO_H_
#define _MENUDTO_H_

#include "../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例菜单数据传输对象
 */
class ResourcetreeDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(ResourcetreeDTO, DTO);
	// 菜单名ID
	API_DTO_FIELD_DEFAULT(String, menu_id, ZH_WORDS_GETTER("menu.info.menu_id"));
	// 菜单名称
	API_DTO_FIELD_DEFAULT(String, menu_name, ZH_WORDS_GETTER("menu.info.menu_name"));
	// 父菜单ID
	API_DTO_FIELD_DEFAULT(String, parent_id, ZH_WORDS_GETTER("menu.info.parent_id"));
	// 菜单类型
	API_DTO_FIELD_DEFAULT(UInt64, menu_type, ZH_WORDS_GETTER("menu.info.menu_type"));
	// 是否按键 is_button
	API_DTO_FIELD_DEFAULT(UInt64, is_button, ZH_WORDS_GETTER("menu.info.is_button"));
	// 层次 level
	API_DTO_FIELD_DEFAULT(UInt64, level, ZH_WORDS_GETTER("menu.info.level"));
	// 外链URL link_url
	API_DTO_FIELD_DEFAULT(String, link_url, ZH_WORDS_GETTER("menu.info.link_url"));
	// 图标 icon
	API_DTO_FIELD_DEFAULT(String, icon, ZH_WORDS_GETTER("menu.info.icon"));
	// 子菜单
	API_DTO_FIELD(List<ResourcetreeDTO::Wrapper>, children, ZH_WORDS_GETTER("resource.get.field.children"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<ResourcetreeDTO>(child), Wrapper::Class::getType()));
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUDTO_H_