#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/23 23:08:13

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
#ifndef _ORG_MENULISTDO_
#define _ORG_MENULISTDO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class org_menulistDO
{
	// 角色工号
	CC_SYNTHESIZE(string, role_id, Role_id);
	// 菜单权限
	CC_SYNTHESIZE(string, menuList, MenuList);
	// 排序号
	CC_SYNTHESIZE(int32_t, xorderColumn, XorderColumn);
public:
	org_menulistDO() {
		role_id = "";
		menuList = "";
		xorderColumn = -1;
	}
};


#endif // !_ORG_MENULISTDO_
