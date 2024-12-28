#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wangye
 @Date: 2024/10/24 23:36:29

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
#ifndef _MENUINFO_QUERY_
#define _MENUINFO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  * 参考arch-demo写的，同时MenuInfoQuery.h里的是分页查询的逻辑可能需要以后具体改
 */
class MenuInfoQuery : public PageQuery
{
	DTO_INIT(MenuInfoQuery, PageQuery);
	// 名称
	DTO_FIELD(String, menu_name);
	DTO_FIELD_INFO(menu_name) {
		info->description = ZH_WORDS_GETTER("menuinfo.field.orgname");
	}
	// 唯一编号
	DTO_FIELD(String, menu_id);
	DTO_FIELD_INFO(menu_id) {
		info->description = ZH_WORDS_GETTER("menuinfo.field.id");
	}
	//// 简称
	//DTO_FIELD(String, orgabbreviation);
	//DTO_FIELD_INFO(orgabbreviation) {
	//	info->description = ZH_WORDS_GETTER("menuinfo.field.orgabbreviation");
	//}
	//// 排序值
	//DTO_FIELD(UInt64, sortingvalue);
	//DTO_FIELD_INFO(sortingvalue) {
	//	info->description = ZH_WORDS_GETTER("menuinfo.field.sortingvalue");
	//}
	//// 图标位置
	//DTO_FIELD(String, orgicon);
	//DTO_FIELD_INFO(orgicon) {
	//	info->description = ZH_WORDS_GETTER("menuinfo.field.orgicon");
	//}
	//// 组织描述
	//DTO_FIELD(String, orgdescription);
	//DTO_FIELD_INFO(orgdescription) {
	//	info->description = ZH_WORDS_GETTER("menuinfo.field.orgdescription");
	//}
	// 组织类别
	DTO_FIELD(UInt64, menu_type);
	DTO_FIELD_INFO(menu_type) {
		info->description = ZH_WORDS_GETTER("menuinfo.field.orgcategory");
	}
	// 上级组织
	DTO_FIELD(String, parent_id);
	DTO_FIELD_INFO(parent_id) {
		info->description = ZH_WORDS_GETTER("menuinfo.field.orgup");
	}
	//// 管理者名
	//DTO_FIELD(String, manager);
	//DTO_FIELD_INFO(manager) {
	//	info->description = ZH_WORDS_GETTER("menuinfo.field.manager");
	//}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MENUINFO_QUERY_