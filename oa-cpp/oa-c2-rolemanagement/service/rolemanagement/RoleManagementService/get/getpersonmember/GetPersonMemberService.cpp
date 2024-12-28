#include"stdafx.h"
#include "GetPersonMemberService.h"
#include"dao/get/getpersonmember/GetPersonMemberDAO.h"
#include"domain/do/get/getpersonmember/GetPersonMemberDO.h"
GetPersonMemberPageDTO::Wrapper GetPersonMemberService::listAll(const GetPersonMemberQuery::Wrapper& query)
{
	
	// �������ض���
	auto pages = GetPersonMemberPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	GetPersonMemberDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
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
	// ��DOת����DTO
	/*for (GetPersonMemberDO sub : result)
	{
		

	}*/
	
	return pages;
}