/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 23�� ������ 20:32:15 CST
*/
#include "stdafx.h"
#include "IDmemberQueryService.h"
#include "dao/GroupManagement/GroupManagementDAO/IDmemberDAO.h"
#include "domain/do/get/IDmemberDO.h"
#include "Macros.h"

IDmemberPageDTO::Wrapper IDmemberQueryService::listAll(const IDmemberQuery::Wrapper& query)
{
	 //�������ض���
	auto pages = IDmemberPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	IDmemberDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<IDmemberDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (IDmemberDO sub : result)
	{
		auto dto = IDmemberDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, GROUP_XID,Group_xid,xidentityList, Xidentity_list, xorderColumn, Xorder_column);
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, group_xid, GROUP_XID);
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xorder_column, xorderColumn);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto,sub, xname,Xname, xunitLevelName, Xunit_level_name)
		pages->addData(dto);

	}
	return pages;
}