#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wangye
 @Date: 2024/10/25 11:52:32

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
#ifndef _MENUINFO_DO_
#define _MENUINFO_DO_
#include "../DoInclude.h"

/**
 * MenuInfo数据库实体类
 */
class MenuInfoDO
{
	// 编号
	CC_SYNTHESIZE(string, menu_id, Menu_Id);
	// 组织名称
	CC_SYNTHESIZE(string, menu_name, Menu_Name);
	// 组织类别即菜单类型(1为普通菜单2为目录3为内嵌iFrame4为外链跳转)
	CC_SYNTHESIZE(uint64_t, menu_type, Menu_Type);
	//上级组织
	CC_SYNTHESIZE(string, parent_id, Parent_Id);
	//是否按钮
	CC_SYNTHESIZE(uint64_t, is_button, Is_Button);
	//权限标识
	CC_SYNTHESIZE(string, permission, Permission);
	//菜单状态（1启用 0停用）
	CC_SYNTHESIZE(uint64_t, status, Status);
	//所在层数，用于快速查询同层结点 
	CC_SYNTHESIZE(uint64_t, level, Level);
	//外链跳转页面对应URL
	CC_SYNTHESIZE(string, link_url, Link_Url);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//创建者ID
	CC_SYNTHESIZE(string, creator_id, Creator_Id);
	//创建时间
	CC_SYNTHESIZE(string, create_time, Create_Time);
	//更新者ID
	CC_SYNTHESIZE(string, updater_id, Updater_Id);
	//更新时间 
	CC_SYNTHESIZE(string, update_time, Update_Time);
	//菜单图片
	CC_SYNTHESIZE(string, icon, Icon);


public:
	MenuInfoDO() {}
	MenuInfoDO(string menu_id, string menu_name, uint64_t menu_type, uint64_t is_button, string parent_id, string permission, uint64_t status, uint64_t level, string link_url, string remark, string creator_id, string create_time, string updater_id, string update_time) {
		this->menu_id = menu_id;
		this->menu_name = menu_name;
		this->menu_type = menu_type;
		this->is_button = is_button;
		this->parent_id = parent_id;
		this->permission = permission;
		this->status = status;
		this->level = level;
		this->link_url = link_url;
		this->remark = remark;
		this->creator_id = creator_id;
		this->create_time = create_time;
		this->updater_id = updater_id;
		this->update_time = update_time;
	}
};

#endif // !_MENUINFO_DO_
