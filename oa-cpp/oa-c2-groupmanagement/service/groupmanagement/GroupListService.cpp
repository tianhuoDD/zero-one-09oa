#include "GroupListService.h"
#include "stdafx.h"
#include "../../dao/get/GroupListDAO.h"
GroupListPageDTO::Wrapper GroupListService::listAll(const GroupListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GroupListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// 查询数据总条数
	GroupListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<GroupListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (GroupListDO sub : result)
	{
		auto dto = GroupListDTO::createShared();
		dto->id = sub.getId();
		dto->name = sub.getName();
		dto->describe = sub.getDescribe();
		
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, );
		pages->addData(dto);

	}
	return pages;
}

uint64_t GroupListService::saveData(const GroupListDTO::Wrapper& dto)
{
	// 组装DO数据
	GroupListDO data;
	data.setId(dto->id.getValue(""));
	data.setName(dto->name.getValue(""));
	data.setDescribe(dto->describe.getValue(""));
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
		// 执行数据添加
	GroupListDAO dao;
	return dao.insert(data);
}
