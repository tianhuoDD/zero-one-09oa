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
#include "MettingRoomListService.h"
#include "../../../dao/metting/mettingroomlist/MettingRoomListDAO.h"



MettingRoomListPageDTO::Wrapper MettingRoomListService::listAll(const MettingRoomListQuery::Wrapper& query)
{
	auto pages = MettingRoomListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	MettingRoomListDAO dao;
	uint64_t count = dao.count(query);

	if (count <= 0)
	{
		return pages;
	}


	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<MettingRoomListDO> result = dao.selectWithPage(query);
	for (MettingRoomListDO sub : result)
	{
		auto dto = MettingRoomListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Ids, mettingname, Names, mettingbuild, Build, mettingfloor, Floor, mettingcapacity, capacity, mettingroomnumber, Roomnumber, mettingdis, Dis, mettingdevice, Device, mettingavailable, Available, meeting,Meetings);
			pages->addData(dto);
	}

	return pages;
}