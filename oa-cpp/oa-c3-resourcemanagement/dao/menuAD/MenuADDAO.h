#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _MENU_DAO_
#define _MENU_DAO_
#include "BaseDAO.h"
#include "../../domain/do/menuinfo/MenuInfoDO.h"

/**
 * 示例表数据库操作实现
 */
class MenuDAO : public BaseDAO
{
public:
	// 插入数据
	uint64_t Insert(const MenuInfoDO& iObj);

	// 查找子菜单
	list<MenuInfoDO> SearchChild(string id);

	// 通过ID删除数据
	int DeleteById(string id);

	
};
#endif // !_SAMPLE_DAO_
