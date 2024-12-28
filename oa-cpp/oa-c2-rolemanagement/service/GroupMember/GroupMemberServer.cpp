#include "stdafx.h"
#include "GroupMemberServer.h"
#include "dao/GroupMember/GroupMemberDAO.h"
#include "domain/do/GroupMember/GroupMemberDO.h"
//#include "domain/dto/GroupMember/GetGroupMemberDTO.h"

GetGroupMemberPageDTO::Wrapper GroupMemberService::listAll(const GroupMemberQuery::Wrapper& query)
{
	// �������ض���
	auto pages = GetGroupMemberPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	GroupMemberDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<GroupMemberDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (GroupMemberDO sub : result)
	{
		auto dto = GetGroupMemberDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, groupname, Groupname, groupnameA, GroupnameA, groupdes, Groupdes)
			pages->addData(dto);

	}
	return pages;
}
