/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/31 19:53:10

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

#ifndef _LIST_PERSONAL_IDETITYSERVICE_
#define _LIST_PERSONAL_IDETITYSERVICE_
#include "stdafx.h"
#include "list_personal_identityService.h"
#include "../../domain/do/list/org_identityDO.h"
#include "../../dao/list/list_personal_identityDAO.h"
#include "../../domain/dto/list/list_personal_identityDTO.h"

listPageDTO::Wrapper list_personal_identityService::listAll(const list_personal_identityQuery::Wrapper& query)
{
	// �������ض���
	auto pages = listPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	list_personal_identityDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{

		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<org_identityDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (org_identityDO sub : result)
	{
		auto dto = list_personal_identityDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xname, Xname, xunitName, XunitName, xid, Xid, xdistinguishedName, XdistinguishedName, xmajor, Xmajor)
			pages->addData(dto);

	}
	return pages;
}







#endif // !_LIST_PERSONAL_IDETITYSERVICE_
