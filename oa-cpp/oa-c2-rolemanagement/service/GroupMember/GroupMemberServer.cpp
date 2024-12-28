#include "stdafx.h"
#include "GroupMemberServer.h"
#include "dao/GroupMember/GroupMemberDAO.h"
#include "domain/do/GroupMember/GroupMemberDO.h"
//#include "domain/dto/GroupMember/GetGroupMemberDTO.h"

GetGroupMemberPageDTO::Wrapper GroupMemberService::listAll(const GroupMemberQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GetGroupMemberPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	GroupMemberDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<GroupMemberDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
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
