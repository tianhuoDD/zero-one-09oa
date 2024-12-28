/*
 Copyright Zero One Star. All rights reserved.

 @Author: wangye
 @Date: 2024/10/24 15:13:11

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
#include "stdafx.h"
#include "MenuInfoService.h"
#include "../../dao/menuAD/MenuInfoDAO.h"  


uint64_t MenuInfoService::saveData(const MenuInfoDTO::Wrapper& dto)
{
	// 组装DO数据
	MenuInfoDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	//*这里按照实际情况应该是和DAO.cpp里的sql查询语句去对应参数数量和格式还有顺序,具体的同上
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Menu_Id, menu_id, Menu_Name, menu_name, Menu_Type, menu_type, Parent_Id, parent_id)
		// 执行数据添加
		MenuInfoDAO dao;
	return dao.insert(data);
}

bool MenuInfoService::updateData(const MenuInfoDTO::Wrapper& dto)
{
	// 组装DO数据
	MenuInfoDO data;
	// 	data.setId(dto->menu_id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Menu_Id, menu_id, Menu_Name, menu_name, Menu_Type, menu_type, Parent_Id, parent_id)
		// 执行数据修改
		MenuInfoDAO dao;
	return dao.update(data) == 1;
}

bool MenuInfoService::removeData(uint64_t menu_id)
{
	MenuInfoDAO dao;
	return dao.deleteById(menu_id) == 1;
}


MenuInfoDTO::Wrapper MenuInfoService::queryData(const string& menu_id)
{
	MenuInfoDAO dao;
	list<MenuInfoDO> result = dao.selectById(menu_id);
	
	auto dto= MenuInfoDTO::createShared();
	
	MenuInfoDO sub = result.front();

	ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, menu_id, Menu_Id, menu_name, Menu_Name, menu_type, Menu_Type, parent_id, Parent_Id)

	return dto;
	//return 1;
}