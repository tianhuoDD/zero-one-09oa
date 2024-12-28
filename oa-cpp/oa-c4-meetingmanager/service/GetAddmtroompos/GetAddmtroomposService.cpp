#include "stdafx.h"
#include "GetAddmtroomposService.h"
#include "../../dao/GetAddmtroompos/GetAddmtroomposDAO.h"

GetmtroomposPageDTO::Wrapper GetAddmtroomposService::listAll(const GetmtroomposQuery::Wrapper& query)
{
	// �������ض���
	auto pages = GetmtroomposPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	GetAddmtroomposDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<class GetAddmtroomposDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (GetAddmtroomposDO sub : result)
	{
		auto dto = GetmtroomposDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xaddress, Xaddress, xname, Xname);
			pages->addData(dto);

	}
	return pages;
}

bool GetAddmtroomposService::insertData(const AddmtroomposDTO::Wrapper& dto)
{
	// ��װDO����
	GetAddmtroomposDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, XcreateTime,xcreateTime,XupdateTime,xupdateTime,Xaddress, xaddress, Xname, xname, Xpinyin, xpinyin, XpinyinInitial, xpinyinInitial)
		// ִ�������޸�
	GetAddmtroomposDAO dao;
	return dao.insert(data) == 1;
}
