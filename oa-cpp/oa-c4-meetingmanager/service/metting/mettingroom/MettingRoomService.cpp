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
#include "MettingRoomService.h"
#include "../../../dao/metting/mettingroom/MettingRoomDAO.h"



MettingBuildPageDTO::Wrapper MettingRoomService::listAll()
{
	auto pages = MettingBuildPageDTO::createShared();
	MettingRoomDAO dao;
	list<MettingBuildDO> result = dao.select();
	for (MettingBuildDO sub : result)
	{
		auto dto = MettingBuildDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, mettingbuild, Build);
		pages->addData(dto);
	}

	return pages;
}

uint64_t MettingRoomService::saveData(const MettingRoomDTO::Wrapper& dto)
{
	// 组装DO数据
	MettingRoomDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Ids, id, Names, name, Build, location, Floor, floor, capacity, capacity, Roomnumber, housenumber, Dis, extnumber, Device, device, Available, status);
	// 执行数据添加
	MettingRoomDAO dao;
	return dao.insert(data);
}
