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
#ifndef _MENUAD_DTO_
#define _MENUAD_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class MenuADDTO : public oatpp::DTO
{
	DTO_INIT(MenuADDTO, DTO);

	// 编号
	DTO_FIELD(String, menu_id);
	DTO_FIELD_INFO(menu_id) {
		info->description = ZH_WORDS_GETTER("menu.info.id");
	}

	// 组织名称
	DTO_FIELD(String, menu_name);
	DTO_FIELD_INFO(menu_name) {
		info->description = ZH_WORDS_GETTER("menu.info.name");
	}

	// 组织类别
	DTO_FIELD(UInt64, menu_type);
	DTO_FIELD_INFO(menu_type) {
		info->description = ZH_WORDS_GETTER("menu.info.menu_type");
	}

	/* 是否按钮
	DTO_FIELD(UInt64, is_button);
	DTO_FIELD_INFO(is_button) {
		info->description = ZH_WORDS_GETTER("menu.info.is_button");
	}*/

	// 上级组织
	DTO_FIELD(String, parent_id);
	DTO_FIELD_INFO(parent_id) {
		info->description = ZH_WORDS_GETTER("menu.info.parent_id");
	}

	// 权限标识
	DTO_FIELD(String, permission);
	DTO_FIELD_INFO(permission) {
		info->description = ZH_WORDS_GETTER("menu.info.permission");
	}

	// 菜单状态
	DTO_FIELD(UInt64, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("menu.info.status");
	}

	// 所在层数
	DTO_FIELD(UInt64, level);
	DTO_FIELD_INFO(level) {
		info->description = ZH_WORDS_GETTER("menu.info.level");
	}

	// 外链跳转页面对应URL
	DTO_FIELD(String, link_url);
	DTO_FIELD_INFO(link_url) {
		info->description = ZH_WORDS_GETTER("menu.info.link_url");
	}

	// 备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("menu.info.remark");
	}

	// 创建者ID
	DTO_FIELD(String, creator_id);
	DTO_FIELD_INFO(creator_id) {
		info->description = ZH_WORDS_GETTER("menu.info.creator_id");
	}

	//// 创建时间
	//DTO_FIELD(String, create_time);
	//DTO_FIELD_INFO(create_time) {
	//	info->description = ZH_WORDS_GETTER("menu.info.create_time");
	//}

	// 更新者ID
	DTO_FIELD(String, updater_id);
	DTO_FIELD_INFO(updater_id) {
		info->description = ZH_WORDS_GETTER("menu.info.updater_id");
	}

	/* 更新时间
	DTO_FIELD(String, update_time);
	DTO_FIELD_INFO(update_time) {
		info->description = ZH_WORDS_GETTER("menu.info.update_time");
	}*/

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_