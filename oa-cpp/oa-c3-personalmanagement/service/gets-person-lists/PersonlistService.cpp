/*
 Copyright Zero One Star. All rights reserved.

 @Author: dingfengchuan
 @Date: 2024年11月1日

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
#include "PersonlistService.h"
#include "../../dao/gets-person-lists/PersonlistDAO.h"

PersonlistPageDTO::Wrapper PersonlistService::listPersonInfo(const PersonlistQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = PersonlistPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	PersonlistDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<org_personDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (org_personDO sub : result)
	{
		auto dto = PersonlistDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xname, Xname, xmobile, Xmobile, xicon, Xicon, xid, Xid, xunique, Xunique)
			pages->addData(dto);

	}
	return pages;
}