#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wangye
 @Date: 2023/10/20 14:59:38

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
#ifndef _MENUINFODTO_H_
#define _MENUINFODTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 菜单信息修改DTO
 */
class MenuInfoDTO : public oatpp::DTO
{
	DTO_INIT(MenuInfoDTO, DTO);
	//---------最上方header(修改用的DTO可能不需要传header那一块的数据，显示的VO里有就行)
	// 图标名称（当作图标地址使用）
	//API_DTO_FIELD_DEFAULT(String, icon, ZH_WORDS_GETTER("menuinfo.header.menuicon"));
	// 唯一编码
	API_DTO_FIELD_DEFAULT(String, menu_id, ZH_WORDS_GETTER("menuinfo.field.id"));
	// 菜单名称
	API_DTO_FIELD_DEFAULT(String, menu_name, ZH_WORDS_GETTER("menuinfo.field.orgname"));
	//// 菜单简称
	//API_DTO_FIELD_DEFAULT(String, orgabbreviation, ZH_WORDS_GETTER("menuinfo.field.orgabbreviation"));
	//// 图标名称（当作图标地址使用）
	//API_DTO_FIELD_DEFAULT(String, orgicon, ZH_WORDS_GETTER("menuinfo.header.orgicon"));
	//// 排序值
	//API_DTO_FIELD_DEFAULT(UInt64, orgsortingvalue, ZH_WORDS_GETTER("menuinfo.field.orgsortingvalue"));
	//// 菜单描述
	//API_DTO_FIELD_DEFAULT(String, orgdescription, ZH_WORDS_GETTER("menuinfo.field.orgdescription"));
	// 菜单类别
	API_DTO_FIELD_DEFAULT(UInt64, menu_type, ZH_WORDS_GETTER("menuinfo.field.orgcategory"));
	// 上级菜单
	API_DTO_FIELD_DEFAULT(String, parent_id, ZH_WORDS_GETTER("menuinfo.field.orgup"));
	//// 管理者
	//API_DTO_FIELD_DEFAULT(String, manager, ZH_WORDS_GETTER("menuinfo.field.manager"));
	// 
	// 
	// 
    //是否按钮
	API_DTO_FIELD_DEFAULT(UInt64, is_button, ZH_WORDS_GETTER("menuinfo.default.null"));
	//权限标识
	API_DTO_FIELD_DEFAULT(String, permission, ZH_WORDS_GETTER("menuinfo.default.null"));
	//菜单状态（1启用 0停用）
	API_DTO_FIELD_DEFAULT(UInt64, status, ZH_WORDS_GETTER("menuinfo.default.null"));
	//所在层数，用于快速查询同层结点 
	API_DTO_FIELD_DEFAULT(UInt64, level, ZH_WORDS_GETTER("menuinfo.default.null"));
	//外链跳转页面对应URL
	API_DTO_FIELD_DEFAULT(String, link_url, ZH_WORDS_GETTER("menuinfo.default.null"));
	//备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("menuinfo.default.null"));
	//创建者ID
	API_DTO_FIELD_DEFAULT(String, creator_id, ZH_WORDS_GETTER("menuinfo.default.null"));
	//创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("menuinfo.default.null"));
	//更新者ID
	API_DTO_FIELD_DEFAULT(String, updater_id, ZH_WORDS_GETTER("menuinfo.default.null"));
	//更新时间 
	API_DTO_FIELD_DEFAULT(String, update_time, ZH_WORDS_GETTER("menuinfo.default.null"));

};
/**
 * 示例分页传输对象
 */
class MenuInfoPageDTO : public PageDTO<MenuInfoDTO::Wrapper>
{
	DTO_INIT(MenuInfoPageDTO, PageDTO<MenuInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MENUINFODTO_H_
