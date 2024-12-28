#include "stdafx.h"
#include "./FormService.h"

GetFormPageDTO::Wrapper FormService::queryForms(const FormQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GetFormPageDTO::createShared();
	// 根据栏目id查询数据
	FormDAO dao;
	list<FormDO> result = dao.selectByAppId(query);
	//// 将DO转换成DTO
	for (FormDO sub : result)
	{
		auto dto = GetFormDTO::createShared();
		dto->xid = sub.getId();
		dto->xupdateTime = sub.getUpdateTime();
		dto->xalias = sub.getAlias();
		dto->xdescription = sub.getDescription();
		pages->addData(dto);
	}
	return pages;
}
