#include "stdafx.h"
#include "QueryRoleService.h"
#include "dao/rolemanagement/RoleManagementDAO/get/queryrole/QueryRoleDAO.h"

#include "dao/get/queryrole/QueryRoleDAO.h"

QueryRolePageDTO::Wrapper QueryRoleService::listAll(const QueryRoleQuery::Wrapper& query) {
	// �������ض���
	auto pages = QueryRolePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	QueryRoleDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<OrgRoleDO> result = dao.selectWithPage(query);

	// ��DOת����DTO
	for (OrgRoleDO sub : result)
	{
		auto dto = QueryRoleDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid,xname, XName,xunique,XUnique);
		pages->addData(dto);
	}
	return pages;
}