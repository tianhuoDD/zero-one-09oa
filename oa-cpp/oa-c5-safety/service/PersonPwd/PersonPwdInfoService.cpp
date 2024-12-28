#include "stdafx.h"
#include "PersonPwdInfoService.h"
#include "../../dao/PersonPwd/PersonPwdInfoDAO.h"
#include "../../Macros.h"
PersonPwdInfoDTO::Wrapper PersonPwdInfoService::ListAll(const String& id)
{
	PersonPwdInfoDAO dao;

	list<PersonPwdInfoDO> result = dao.selectById(id);
	//����id����
	auto dto = PersonPwdInfoDTO::createShared();
	// ��DOת����DTO
	for (PersonPwdInfoDO sub : result)
	{
		
	//	// 		dto->id = sub.getId();
	//	// 		dto->name = sub.getName();
	//	// 		dto->sex = sub.getSex();
	//	// 		dto->age = sub.getAge();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id,password,Password);
	}
	return dto;
}