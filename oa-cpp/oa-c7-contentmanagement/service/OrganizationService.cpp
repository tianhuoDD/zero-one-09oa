/*
 Copyright Zero One Star. All rights reserved.

 @Author: Rif
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
#include "OrganizationService.h"

OrganizationNamePageDTO::Wrapper OrganizationService::queryOrg(const OrgQuery::Wrapper& query)
{
	// �������ض���
	auto pages = OrganizationNamePageDTO::createShared();

	//// ��ѯ����������
	OrganizationDAO dao;
	uint64_t count = dao.countName(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<OrganizationNameDO> result = dao.selectByName(query);
	//// ��DOת����DTO
	for (OrganizationNameDO sub : result)
	{
		auto dto = OrganizationNameDTO::createShared();
		dto->xid = sub.getId();
		dto->xname = sub.getName();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Id, xname, Name);
		pages->addData(dto);
	}
	return pages;
}

OrganizationMemberPageDTO::Wrapper OrganizationService::queryOrgMem(const OrgQuery::Wrapper& query)
{
	cout << "ENTER queryPer" << endl;
	//�������ض���
	auto pages = OrganizationMemberPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	OrganizationDAO dao;
	uint64_t count = dao.countMember(query);
	cout << "Pages:" << count << endl;
	if (count <= 0)
	{
		return {};
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<OrganizationMemberDO> result = dao.selectByNameMember(query);
	//��DOת����DTO
	for (OrganizationMemberDO sub : result)
	{
		auto dto = OrganizationMemberDTO::createShared();
		dto->xid = sub.getId();
		dto->xname = sub.getName();
		dto->xemployee = sub.getXEmployee();
		pages->addData(dto);
	}

	return pages;
}
