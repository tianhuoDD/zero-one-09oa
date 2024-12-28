#include "stdafx.h"
#include "rolemanagementService.h"
#include "../../dao/rolemanagement/rolemanagementDAO.h"
#include "../../controller/groupmanagement/GroupManagementController.h"
#include "../../domain/do/get/OrgGroupGrouplist/OrgGroupGrouplistDO.h"
#include "../../domain/do/get/OrgGroupUnitlist/OrgGroupUnitlistDO.h"
#include "../../domain/do/put/OrgGroupIdentitylist/OrgGroupIdentitylistDO.h"
//#include "../../../oa-cpp/lib-oatpp\include\domain\dto\PageDTO.h"
#include "Macros.h"

//群组成员表
GetGroupMembersPageQuery::Wrapper rolemanagementService::listAllG(const GetGroupMembersQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GetGroupMembersPageQuery::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	rolemanagementDAO dao;
	uint64_t count = dao.countG(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<OrgGroupGrouplistDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
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

//组织成员表
GetOrganizationMembersPageQuery::Wrapper rolemanagementService::listAllO(const GetOrganizationMembersQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GetOrganizationMembersPageQuery::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	rolemanagementDAO dao;
	uint64_t count = dao.countO(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<OrgGroupUnitlistDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
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
	// 组装DO数据
	OrgGroupIdentitylistDO data;
	
	data.setGroupxid(dto->groupxid.getValue({})); data.setXidentityList(dto->xidentityList.getValue({}));
		// 执行数据添加
		rolemanagementDAO dao;
	return dao.insert(data);
}

bool rolemanagementService::removeData(string groupxid)
{
	cout << groupxid << endl;
	rolemanagementDAO dao;
	return dao.deleteById(groupxid) == 1;
}
