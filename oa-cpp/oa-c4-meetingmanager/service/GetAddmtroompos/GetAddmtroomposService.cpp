#include "stdafx.h"
#include "GetAddmtroomposService.h"
#include "../../dao/GetAddmtroompos/GetAddmtroomposDAO.h"

GetmtroomposPageDTO::Wrapper GetAddmtroomposService::listAll(const GetmtroomposQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GetmtroomposPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	GetAddmtroomposDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<class GetAddmtroomposDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
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
	// 组装DO数据
	GetAddmtroomposDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, XcreateTime,xcreateTime,XupdateTime,xupdateTime,Xaddress, xaddress, Xname, xname, Xpinyin, xpinyin, XpinyinInitial, xpinyinInitial)
		// 执行数据修改
	GetAddmtroomposDAO dao;
	return dao.insert(data) == 1;
}
