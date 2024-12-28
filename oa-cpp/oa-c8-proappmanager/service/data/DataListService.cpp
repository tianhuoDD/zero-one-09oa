#include "stdafx.h"
#include "DataListService.h"
#include "dao/data/DataListDAO.h"
#include "domain/do/data/DataListDO.h"

DataListPageDTO::Wrapper DataListService::listAll(const DataListQuery::Wrapper& query) {
	// �������ض���
	auto pages = DataListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	DataListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages; // ���û��������ֱ�ӷ��ؿ�ҳ
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	std::list<DataListDO> result = dao.selectWithPage(query);

	// �� DO ת���� DTO
	for (const auto& sub : result) {
		auto dto = DataListDTO::createShared();
		// ʹ�ú�����ֶ�ӳ��
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, dataid, DataId, appid, Application, name, Name, alias, Alias, description, Description, creatTime, CreatTime, updateTime, UpdateTime);
		pages->addData(dto);
	}
	return pages;
}
