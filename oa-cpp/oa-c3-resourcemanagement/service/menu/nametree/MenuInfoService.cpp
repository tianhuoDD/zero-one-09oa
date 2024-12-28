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
//#include "stdafx.h"
//#include "MenuInfoService.h"
//#include "../../../dao/menu/nametree/MenuInfoDAO.h"
//
//
//#include "domain/do/menuinfo/MenuInfoDO.h"
//MenuInfoDTO::Wrapper MenuInfoService::listAll(const MenuInfoQuery::Wrapper& query)
//{
//	/* 构建返回对象*/
//	auto pages = MenuInfoDTO::createShared();
//	//pages->pageIndex = query->pageIndex;
//	//pages->pageSize = query->pageSize;
//	 /*查询数据总条数*/
//	MenuInfoDAO dao;
//	uint64_t count = dao.count(query);
//	list<MenuInfoDO> result = dao.selectAll();
//	if (count <= 0)
//	{
//		return result;
//	}
//
//	 //分页查询数据
//	//pages->total = count;
//	//pages->calcPages();
//
//	// 将DO转换成DTO
//	return result;
//	for (MenuInfoDO sub : result)
//	{
//		auto dto = MenuInfoDTO::createShared();
//// 		dto->id = sub.getId();
//// 		dto->name = sub.getName();
//// 		dto->sex = sub.getSex();
//// 		dto->age = sub.getAge();
//		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, aid, Aid, mid, Mid, name, Name, userid, Userid, type, Type, status, Statuss)
//		pages->addData(dto);  
//		
//	}
//	return pages;
//}




//uint64_t MenuAutorityService::saveData(const MenuUseAutorityDTO::Wrapper& dto)
//{
//	// 组装DO数据
//	MenuUseAutorityDO data;
//// 	data.setName(dto->name.getValue(""));
//// 	data.setSex(dto->sex.getValue(""));
//// 	data.setAge(dto->age.getValue(1));
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Aid, aid, Mid, mid, Name, name, Userid, userid, Type, type, Statuss, status)
//	// 执行数据添加
//	MenuUseAutorityDAO dao;
//	return dao.insert(data);
//}
//
//bool MenuAutorityService::updateData(const MenuUseAutorityDTO::Wrapper& dto)
//{
//	// 组装DO数据
//	MenuUseAutorityDO data;
//// 	data.setId(dto->id.getValue(0));
//// 	data.setName(dto->name.getValue(""));
//// 	data.setSex(dto->sex.getValue(""));
//// 	data.setAge(dto->age.getValue(1));
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Aid, aid, Mid, mid, Name, name, Userid, userid, Type, type, Statuss, status)
//	// 执行数据修改
//	MenuUseAutorityDAO dao;
//	return dao.update(data) == 1;
//}
//
//bool MenuAutorityService::removeData(uint64_t id)
//{
//	MenuUseAutorityDAO dao;
//	return dao.deleteById(id) == 1;
//}
