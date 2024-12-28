#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: dingfengchuan
 @Date: 2024��11��1��

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
 * ʾ���˵����ݴ������
 */
class ResourcetreeDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(ResourcetreeDTO, DTO);
	// �˵���ID
	API_DTO_FIELD_DEFAULT(String, menu_id, ZH_WORDS_GETTER("menu.info.menu_id"));
	// �˵�����
	API_DTO_FIELD_DEFAULT(String, menu_name, ZH_WORDS_GETTER("menu.info.menu_name"));
	// ���˵�ID
	API_DTO_FIELD_DEFAULT(String, parent_id, ZH_WORDS_GETTER("menu.info.parent_id"));
	// �˵�����
	API_DTO_FIELD_DEFAULT(UInt64, menu_type, ZH_WORDS_GETTER("menu.info.menu_type"));
	// �Ƿ񰴼� is_button
	API_DTO_FIELD_DEFAULT(UInt64, is_button, ZH_WORDS_GETTER("menu.info.is_button"));
	// ��� level
	API_DTO_FIELD_DEFAULT(UInt64, level, ZH_WORDS_GETTER("menu.info.level"));
	// ����URL link_url
	API_DTO_FIELD_DEFAULT(String, link_url, ZH_WORDS_GETTER("menu.info.link_url"));
	// ͼ�� icon
	API_DTO_FIELD_DEFAULT(String, icon, ZH_WORDS_GETTER("menu.info.icon"));
	// �Ӳ˵�
	API_DTO_FIELD(List<ResourcetreeDTO::Wrapper>, children, ZH_WORDS_GETTER("resource.get.field.children"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<ResourcetreeDTO>(child), Wrapper::Class::getType()));
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUDTO_H_