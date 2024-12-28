#include "stdafx.h"
#include "SortByPinYinService.h"
#include "../../dao/Sort/SortByPinYinDAO.h"
//query
SortByPinYinPageDTO::Wrapper SortByPinYinService::listAll(const SortByPinYinQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = SortByPinYinPageDTO::createShared();
	pages->pageIndex = query->pageIndex;//1
	pages->pageSize = query->pageSize;//2

	// 查询数据总条数
	SortByPinYinDAO dao;
	uint64_t count = dao.count(query);//总数
	if (count <= 0)//查询不到数据
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;//3（总数）
	pages->calcPages();//4
	list<SortByPinYinDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (SortByPinYinDO sub : result)
	{
		auto dto = SortByPinYinDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();   
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, 
			xid, Xid, 
			name, Name, 
			shuxing, Shuxing, 
			value, Value, 
			miaoshu, Miaoshu, 
			xorderNumber, XorderNumber,
			xpinyin,Xpinyin,
			xunique,Xunique);//将DAO的数据进行cv
		pages->addData(dto);//5(显示查询结果)
	}
	return pages;
}