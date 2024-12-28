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
#ifndef _RESOURCETREE_MAPPER_
#define _RESOURCETREE_MAPPER_

#include "tree/TreeNodeMapper.h"
#include "domain/do/menuinfo/MenuInfoDO.h"
#include "domain/dto/resource-tree-permissios/ResourcetreeDTO.h"
#include "Mapper.h"
/**
 * 演示菜单数据字段匹配实现
 */
class TreeResourceMapper : public TreeNodeMapper<MenuInfoDO>
{
public:
	shared_ptr<TreeNode> objectMapper(MenuInfoDO* source) const override
	{
		// 创建结果数据对象
		auto res = make_shared<ResourcetreeDTO>();
		// 计算层级结构属性映射
		res->_id(source->getMenu_Id());
		res->_pid(source->getParent_Id());
		// 扩展属性映射
		res->menu_id = source->getMenu_Id();
		res->menu_name = source->getMenu_Name();
		res->parent_id = source->getParent_Id();
		res->menu_type = source->getMenu_Type();
		res->is_button = source->getIs_Button();
		res->level = source->getLevel();
		res->link_url = source->getLink_Url();
		res->icon = source->getIcon();
		return res;
	}
};

class ResourcetreeMapper : public Mapper<MenuInfoDO>
{
public:
	MenuInfoDO mapper(ResultSet* resultSet) const override
	{
		// 创建结果数据对象
		MenuInfoDO data;
		data.setMenu_Id(resultSet->getString(1));
		data.setMenu_Name(resultSet->getString(2));
		data.setParent_Id(resultSet->getString(3));
		data.setMenu_Type(resultSet->getInt(4));
		data.setIs_Button(resultSet->getInt(5));
		data.setLevel(resultSet->getInt(6));
		data.setLink_Url(resultSet->getString(7));
		data.setIcon(resultSet->getString(8));
		return data;
	}
};

#endif // !_TREEMENUMAPPER_H_