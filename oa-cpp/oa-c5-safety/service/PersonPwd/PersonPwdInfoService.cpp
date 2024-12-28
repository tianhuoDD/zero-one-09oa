#include "stdafx.h"
#include "PersonPwdInfoService.h"
#include "../../dao/PersonPwd/PersonPwdInfoDAO.h"
#include "../../Macros.h"
PersonPwdInfoDTO::Wrapper PersonPwdInfoService::ListAll(const String& id)
{
	PersonPwdInfoDAO dao;

	list<PersonPwdInfoDO> result = dao.selectById(id);
	//根据id查找
	auto dto = PersonPwdInfoDTO::createShared();
	// 将DO转换成DTO
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