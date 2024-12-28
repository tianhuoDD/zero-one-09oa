#include "stdafx.h"
#include"PutService.h"
#include "../../domain/do/New/PutDO.h"
#include "../../dao/Put/PutDAO.h"
bool PutService::updateData(const PutDTO::Wrapper& dto)
{
	// 组装DO数据
	PutDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Xappicon, xappicon, XallPeopleViem, xallPeopleViem, XallPeoplePublish, xallPeoplePublish, XcreatorPerson, xcreatorPerson)
		// 执行数据修改
		PutDAO dao;
	return dao.update(data) == 1;
}

