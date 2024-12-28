#include "GroupListService.h"
#include "stdafx.h"
#include "../../dao/get/GroupListDAO.h"
GroupListPageDTO::Wrapper GroupListService::listAll(const GroupListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = GroupListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// ��ѯ����������
	GroupListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<GroupListDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
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
	// ��װDO����
	GroupListDO data;
	data.setId(dto->id.getValue(""));
	data.setName(dto->name.getValue(""));
	data.setDescribe(dto->describe.getValue(""));
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
		// ִ���������
	GroupListDAO dao;
	return dao.insert(data);
}
