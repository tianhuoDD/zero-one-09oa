#include "stdafx.h"
#include "OrgUnitService.h"
#include "../dao/OrgUnitDAO.h"

/*
OrgUnitPageDTO::Wrapper OrgUnitService::listAll(const OrgUnitQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = OrgUnitPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	OrgUnitDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<OrgUnitDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (OrgUnitDO sub : result)
	{
		auto dto = OrgUnitDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, unit_xname, Unit_xname, xunique, Xunique, xtypeList, XtypeList, xshortName, XshortName, xdescription, Xdescription, person_xname, Person_xname, xsuperior, Xsuperior, xorderNumber, XorderNumber)
			pages->addData(dto);

	}
	return pages;
}
*/

OrgUnitDTO::Wrapper OrgUnitService::listOne(const OrgUnitQuery::Wrapper& query)
{
	OrgUnitDAO dao;
	list<OrgUnitDO> result = dao.selectByName(query->unit_xname);
	// 将DO转换成DTO
	auto dto = OrgUnitDTO::createShared();
	for (OrgUnitDO sub : result)
	{
		
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, unit_xname, Unit_xname, xunique, Xunique, xtypeList, XtypeList, xshortName, XshortName, xdescription, Xdescription, person_xname, Person_xname, xsuperior, Xsuperior, xorderNumber, XorderNumber)


	}
	return dto;
}

bool OrgUnitService::updateData(const OrgUnitDTO::Wrapper& dto)
{
	// 组装DO数据
	OrgUnitDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xid, xid, Unit_xname, unit_xname, Xunique, xunique, XtypeList, xtypeList, XshortName, xshortName, Xdescription, xdescription, Person_xname, person_xname, Xsuperior, xsuperior, XorderNumber, xorderNumber)
		// 执行数据修改
		OrgUnitDAO dao;
	return dao.update(data) == 1;
}
