#include "stdafx.h"
#include "ModifyGroupInfoService.h"
#include "domain/dto/group/GroupDTO.h"
#include <dao/group/GroupDAO.h>

//SamplePageDTO::Wrapper SampleService::listAll(const SampleQuery::Wrapper& query)
//{
//	// 构建返回对象
//	auto pages = SamplePageDTO::createShared();
//	pages->pageIndex = query->pageIndex;
//	pages->pageSize = query->pageSize;
//
//	// 查询数据总条数
//	SampleDAO dao;
//	uint64_t count = dao.count(query);
//	if (count <= 0)
//	{
//		return pages;
//	}
//
//	// 分页查询数据
//	pages->total = count;
//	pages->calcPages();
//	list<SampleDO> result = dao.selectWithPage(query);
//	// 将DO转换成DTO
//	for (SampleDO sub : result)
//	{
//		auto dto = SampleDTO::createShared();
//		// 		dto->id = sub.getId();
//		// 		dto->name = sub.getName();
//		// 		dto->sex = sub.getSex();
//		// 		dto->age = sub.getAge();
//		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
//			pages->addData(dto);
//
//	}
//	return pages;
//}

//uint64_t ModifyGroupService::saveData(const GroupDTO::Wrapper& dto)
//{
//	// 组装DO数据
//	SampleDO data;
//	// 	data.setName(dto->name.getValue(""));
//	// 	data.setSex(dto->sex.getValue(""));
//	// 	data.setAge(dto->age.getValue(1));
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Id, id, Info, Info)
//		// 执行数据添加
//		GroupDAO dao;
//	return dao.insert(data);
//}

bool ModifyGroupInfoService::updateData(const GroupDTO::Wrapper& dto)
{
	// 组装DO数据
	GroupDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Info, info, Id, id)
		// 执行数据修改
		GroupDAO dao;
	return dao.update(data) == 1;
}

//bool SampleService::removeData(uint64_t id)
//{
//	SampleDAO dao;
//	return dao.deleteById(id) == 1;
//}
