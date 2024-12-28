










































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
#include "PersonService.h"


PersonInfoPageDTO::Wrapper PersonService::queryPer(const PersonQuery::Wrapper& query)
{
	//cout << "ENTER queryPer"<<endl;
	// 构建返回对象
	auto pages = PersonInfoPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	PersonInfoDAO dao;
	uint64_t count = dao.count(query);
	cout << "Pages:" << count << endl;
	if (count <= 0)
	{
		return {};
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<PersonInfoDO> result = dao.selectWithPage(query);
	 //将DO转换成DTO
	for (PersonInfoDO sub : result)
	{
		auto dto = PersonInfoDTO::createShared();
		dto->xid = sub.getId();
		dto->xname = sub.getName();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Id, xname, Name);
		pages->addData(dto);
	}

	return pages;
	//return {};
}