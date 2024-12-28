#include"stdafx.h"
#include "GetPersonMemberService.h"
#include"dao/get/getpersonmember/GetPersonMemberDAO.h"
#include"domain/do/get/getpersonmember/GetPersonMemberDO.h"
GetPersonMemberPageDTO::Wrapper GetPersonMemberService::listAll(const GetPersonMemberQuery::Wrapper& query)
{
	
	// 构建返回对象
	auto pages = GetPersonMemberPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	GetPersonMemberDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<GetPersonMemberDO> result = dao.selectWithPage(query);

	for (auto item : result)
	{
		std::cout << item.getXgroupList() << std::endl;
	}

	list<GetPersonMemberDTO> re = dao.selectGroupMemberWithPage(result);

	for (auto sub : re)
	{
		auto dto = GetPersonMemberDTO::createShared();
		dto->xname = sub.xname;
		dto->xdescription = sub.xdescription;
		dto->xdistinguishedName = sub.xdistinguishedName;
		dto->role_xid = query->ROLE_XID;
		dto->xgroupList = sub.xgroupList;
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, role_xid, ROLE_XID, xgroupList, XgroupList, xorderColumn, XorderColumn)
			pages->addData(dto);
	}
	// 将DO转换成DTO
	/*for (GetPersonMemberDO sub : result)
	{
		

	}*/
	
	return pages;
}