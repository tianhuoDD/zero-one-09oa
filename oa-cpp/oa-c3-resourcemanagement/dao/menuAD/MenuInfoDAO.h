#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wangye
 @Date: 2024/10/25 14:23:49

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
#ifndef _MENUINFO_DAO_
#define _MENUINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/menuinfo/MenuInfoDO.h"
#include "../../domain/query/menuinfo/MenuInfoQuery.h"

/**
 * 示例表数据库操作实现
 */
class MenuInfoDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const MenuInfoQuery::Wrapper& query);
	// 分页查询数据
	list<MenuInfoDO> selectWithPage(const MenuInfoQuery::Wrapper& query);
	// 通过名称查询数据
	list<MenuInfoDO> selectByName(const string& menu_name);
	 //*通过menu_id查询数据,自己写的不一定用得上
	list<MenuInfoDO> selectById(const string& menu_id);
	// 插入数据
	uint64_t insert(const MenuInfoDO& iObj);
	// 修改数据
	int update(const MenuInfoDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t menu_id);
};
#endif // !_MENUINFO_DAO_
