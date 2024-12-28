#include "stdafx.h"
#include "./FormService.h"

GetFormPageDTO::Wrapper FormService::queryForms(const FormQuery::Wrapper& query)
{
	// �������ض���
	auto pages = GetFormPageDTO::createShared();
	// ������Ŀid��ѯ����
	FormDAO dao;
	list<FormDO> result = dao.selectByAppId(query);
	//// ��DOת����DTO
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
