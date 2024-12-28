/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "MenuADService.h"
#include "../../dao/menuAD/MenuADDAO.h"
#include<queue>



uint64_t MenuADService::saveData(const MenuADDTO::Wrapper& dto)
{
	// 组装DO数据
	MenuInfoDO data;
// 	data.setName(dto->name.getValue(""));
// 	data.setSex(dto->sex.getValue(""));
// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Menu_Id, menu_id, Menu_Name, menu_name, Menu_Type, menu_type, Parent_Id, parent_id,
		Permission, permission, Status, status, Level, level, Link_Url, link_url, Remark, remark,
		Creator_Id, creator_id, Updater_Id, updater_id
	)
	
	// 执行数据添加
	MenuDAO dao;
	return dao.Insert(data);
}

bool MenuADService::removeData(string id)
{
	MenuDAO dao;
	return dao.DeleteById(id) == 1;
}
