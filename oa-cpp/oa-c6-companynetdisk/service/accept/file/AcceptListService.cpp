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
#include "AcceptListService.h"
#include "../../../dao/accept/file/AcceptFileListDAO.h"
#include "../../../dao/accept/file/AcceptUserListDAO.h"

//��ȡ�ļ��б�
AcceptFilesPageDTO::Wrapper AcceptListService::file_listAll(const AcceptFileListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = AcceptFilesPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	AcceptFileListDAO dao;
	uint64_t count = dao.file_count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<file_attachmentDO> result = dao.file_selectWithPage(query);
	// ��DOת����DTO
	for (file_attachmentDO sub : result)
	{
		auto dto = AcceptFileListDTO::createShared();
		file_attachmentDO temp;
		temp.getXlength();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xname, Xname, xunique, Xperson, xcreateTime, XcreateTime, xlastupdateTime, XlastUpdateTime, xlength, Xlength)
			pages->addData(dto);
	}
	return pages;
}


AcceptUsersPageDTO::Wrapper AcceptListService::user_listAll(const AcceptUserListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = AcceptUsersPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	AcceptUserListDAO dao;
	uint64_t count = dao.user_count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<file_attachment_editorlistDO> result = dao.user_selectWithPage(query);
	// ��DOת����DTO
	for (file_attachment_editorlistDO sub : result)
	{
		auto dto = AcceptUserListDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		//dto->xperson = sub.getXeditorList();
		//dto->xunique = sub.getAttachment_Xid();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xperson, XeditorList, ATTACHMENT_XID, attachment_xid);
		pages->addData(dto);
	}
	return pages;
}
