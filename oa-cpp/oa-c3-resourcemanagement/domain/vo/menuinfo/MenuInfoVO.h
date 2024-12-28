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
#ifndef _MENUINFO_VO_
#define _MENUINFO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/menuinfo/MenuInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 菜单信息显示对象
 */
//class MenuInfoVO : public oatpp::DTO
//{
//	DTO_INIT(MenuInfoVO, DTO);
//	//---------最上方header(修改用的DTO可能不需要传header那一块的数据，显示的VO里有就行)
//	//// 图标名称(当作图标地址使用)
//	//API_DTO_FIELD(String, icon, ZH_WORDS_GETTER("menuinfo.header.orgicon"), false, "NULL");
//	// 菜单名称
//	API_DTO_FIELD(String, menu_name, ZH_WORDS_GETTER("menuinfo.header.orgname"), true, "01 ju xing");
//	//// 菜单简称
//	//API_DTO_FIELD(String, orgabbreviation1, ZH_WORDS_GETTER("menuinfo.header.orgabbreviation"), true, "01 xing qiu");
//	//--------下方一系列菜单信息
//	// 唯一编码
//	API_DTO_FIELD(String, menu_id, ZH_WORDS_GETTER("menuinfo.field.id"), true,"007");
//	// 菜单类别
//	API_DTO_FIELD(UInt64, menu_type, ZH_WORDS_GETTER("menuinfo.field.orgcategory"), true, 1);
//	//// 菜单简称
//	//API_DTO_FIELD(String, orgabbreviation2, ZH_WORDS_GETTER("menuinfo.field.orgabbreviation"), false, "01 xing qiu");
//	//// 菜单描述
//	//API_DTO_FIELD(String, orgdescription, ZH_WORDS_GETTER("menuinfo.field.orgdescription"), false, "zan shi mei you");
//	//// 管理者
//	//API_DTO_FIELD(String, manager, ZH_WORDS_GETTER("menuinfo.field.manager"), false, "mei you guan li");
//	// 上级菜单
//	API_DTO_FIELD(String, parent_id, ZH_WORDS_GETTER("menuinfo.field.orgup"), false, "zan wu cai dan");
//	//// 排序值
//	//API_DTO_FIELD(UInt64, sortingvalue, ZH_WORDS_GETTER("menuinfo.field.sortingvalue"), true, 006);
//};





/**
 * 菜单信息显示VO，用于响应给客户端的Json对象
 */
class MenuInfoJsonVO : public JsonVO<MenuInfoDTO::Wrapper> {
	DTO_INIT(MenuInfoJsonVO, JsonVO<MenuInfoDTO::Wrapper>);

};
//*在改的新增的要用到的类
//class MenuInfoListJsonVO : public JsonVO<MenuInfoListVO::Wrapper> {
//	DTO_INIT(MenuInfoListJsonVO, JsonVO<MenuInfoListVO::Wrapper>);
//	
//};

/**
 *  *分页显示JsonVO，用于响应给客户端的Json对象 严格按照arch-demo写的，为了给menuinfoctroller.cpp提供定义
 */
class MenuInfoPageJsonVO : public JsonVO<MenuInfoPageDTO::Wrapper> {
	DTO_INIT(MenuInfoPageJsonVO, JsonVO<MenuInfoPageDTO::Wrapper>);
};





#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUINFO_VO_