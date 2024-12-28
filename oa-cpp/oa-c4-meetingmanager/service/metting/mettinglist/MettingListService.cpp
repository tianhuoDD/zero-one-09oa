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
#include "MettingListService.h"
#include "../../../dao/metting/mettinglist/MettingListDAO.h"
#include "../lib-common/include/SimpleDateTimeFormat.h"

MettingListPageDTO::Wrapper MettingListService::listAll(const MettingListQuery::Wrapper& query)
{
	auto pages = MettingListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	MettingListDAO dao;
	uint64_t count = dao.count(query);

	if (count <= 0)
	{
		return pages;
	}

	// query-date
	// auto Time = SimpleDateTimeFormat();
	// string time = Time.format("%H:%M");
	// 
	// if (query->time.getValue(0) < time)
	// {
	// 
	// }

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<MettingListDO> result = dao.selectWithPage(query);
	for (MettingListDO sub : result)
	{
		auto dto = MettingListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Names, date1, Dates, timestart, Timestart, timeend, Timeend, title1, Title, mettingroom, Mtroom)
			pages->addData(dto);
	}

	return pages;
}
