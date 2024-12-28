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
#include "GetShareService.h"
#include "dao/getting/file/GetShareFilesDAO.h"
#include "dao/getting/file/GetShareUsersDAO.h"


GetShareFilesPageDTO::Wrapper GetShareService::listAll_file(const GetShareFilesQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GetShareFilesPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	GetShareFilesDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<file_attachmentDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (file_attachmentDO sub : result)
	{
		auto dto = GetShareFilesDTO::createShared();
		file_attachmentDO temp;
		temp.getXlength();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xname, Xname, xperson, Xperson, xlength, Xlength, xcreateTime, XcreateTime, xupdateTime, XupdateTime);
		pages->addData(dto);
	}
	return pages;
}

GetShareUsersPageDTO::Wrapper GetShareService::listAll_user(const GetShareUserQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GetShareUsersPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	GetShareUsersDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<file_attachment_sharelistDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (file_attachment_sharelistDO sub : result)
	{
		auto dto = GetShareUsersDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xperson, XshareList, ATTACHMENT_XID, attachment_xid);
		pages->addData(dto);
	}
	return pages;
}
