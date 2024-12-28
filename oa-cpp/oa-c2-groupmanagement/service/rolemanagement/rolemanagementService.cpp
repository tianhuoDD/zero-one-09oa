#include "stdafx.h"
#include "rolemanagementService.h"
#include "../../dao/rolemanagement/rolemanagementDAO.h"
#include "../../controller/groupmanagement/GroupManagementController.h"
#include "../../domain/do/get/OrgGroupGrouplist/OrgGroupGrouplistDO.h"
#include "../../domain/do/get/OrgGroupUnitlist/OrgGroupUnitlistDO.h"
#include "../../domain/do/put/OrgGroupIdentitylist/OrgGroupIdentitylistDO.h"
//#include "../../../oa-cpp/lib-oatpp\include\domain\dto\PageDTO.h"
#include "Macros.h"

//Ⱥ���Ա��
GetGroupMembersPageQuery::Wrapper rolemanagementService::listAllG(const GetGroupMembersQuery::Wrapper& query)
{
	// �������ض���
	auto pages = GetGroupMembersPageQuery::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	rolemanagementDAO dao;
	uint64_t count = dao.countG(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<OrgGroupGrouplistDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (OrgGroupGrouplistDO sub : result)
	{
		auto dto = GetGroupMembersQuery::createShared();
		dto->name = sub.getName();
		dto->allname = sub.getAllname();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, allname, Allname)
			pages->addData(dto);

	}
	return pages;
}

//��֯��Ա��
GetOrganizationMembersPageQuery::Wrapper rolemanagementService::listAllO(const GetOrganizationMembersQuery::Wrapper& query)
{
	// �������ض���
	auto pages = GetOrganizationMembersPageQuery::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	rolemanagementDAO dao;
	uint64_t count = dao.countO(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<OrgGroupUnitlistDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (OrgGroupUnitlistDO sub : result)
	{
		auto dto = GetOrganizationMembersQuery::createShared();
		dto->name = sub.getName();
		dto->xunitList = sub.getXunitList();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, xunitList, XunitList)
			//pages->addData(dto);

	}
	return pages;
}

uint64_t rolemanagementService::saveData(const AddOrRemoveIdentityMembersDTO::Wrapper& dto)
{
	// ��װDO����
	OrgGroupIdentitylistDO data;
	
	data.setGroupxid(dto->groupxid.getValue({})); data.setXidentityList(dto->xidentityList.getValue({}));
		// ִ���������
		rolemanagementDAO dao;
	return dao.insert(data);
}

bool rolemanagementService::removeData(string groupxid)
{
	cout << groupxid << endl;
	rolemanagementDAO dao;
	return dao.deleteById(groupxid) == 1;
}
