#include "stdafx.h"
#include "DataListService.h"
#include "dao/data/DataListDAO.h"
#include "domain/do/data/DataListDO.h"

DataListPageDTO::Wrapper DataListService::listAll(const DataListQuery::Wrapper& query) {
	// 构建返回对象
	auto pages = DataListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	DataListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages; // 如果没有数据则直接返回空页
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	std::list<DataListDO> result = dao.selectWithPage(query);

	// 将 DO 转换成 DTO
	for (const auto& sub : result) {
		auto dto = DataListDTO::createShared();
		// 使用宏进行字段映射
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, dataid, DataId, appid, Application, name, Name, alias, Alias, description, Description, creatTime, CreatTime, updateTime, UpdateTime);
		pages->addData(dto);
	}
	return pages;
}
