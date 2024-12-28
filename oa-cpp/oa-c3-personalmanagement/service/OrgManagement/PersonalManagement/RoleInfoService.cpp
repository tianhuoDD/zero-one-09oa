#include "stdafx.h"
#include "RoleInfoService.h"
#include "dao/OrgManagement/PersonalManagement/RoleInfoDAO.h"
RoleInfoPageDTO::Wrapper RoleInfoService::listAll(const RoleInfoQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RoleInfoPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	RoleInfoDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<org_roleDO> result = dao.selectWithPage(query);
	//将DO转换成DTO
	for (org_roleDO sub : result)
	{
		auto dto = RoleInfoDTO::createShared();
		dto->xname = sub.getXname();
		dto->xdistinguishedName = sub.getXdistinguishedName();
		dto->xdescription = sub.getXdescription();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
			pages->addData(dto);

	}
	return pages;
}

