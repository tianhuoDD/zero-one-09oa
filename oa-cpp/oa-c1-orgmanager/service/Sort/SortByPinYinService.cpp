#include "stdafx.h"
#include "SortByPinYinService.h"
#include "../../dao/Sort/SortByPinYinDAO.h"
//query
SortByPinYinPageDTO::Wrapper SortByPinYinService::listAll(const SortByPinYinQuery::Wrapper& query)
{
	// �������ض���
	auto pages = SortByPinYinPageDTO::createShared();
	pages->pageIndex = query->pageIndex;//1
	pages->pageSize = query->pageSize;//2

	// ��ѯ����������
	SortByPinYinDAO dao;
	uint64_t count = dao.count(query);//����
	if (count <= 0)//��ѯ��������
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;//3��������
	pages->calcPages();//4
	list<SortByPinYinDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
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
			xunique,Xunique);//��DAO�����ݽ���cv
		pages->addData(dto);//5(��ʾ��ѯ���)
	}
	return pages;
}