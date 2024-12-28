#include "stdafx.h"
#include "QueryUserService.h"
#include "dao/user/UserDAO.h"

UserPageDTO::Wrapper UserService::listAll(const UserQuery::Wrapper& query)
{
	auto pages = UserPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	UserDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<UserDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (UserDO sub : result)
	{
		auto dto = UserDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, phone, Phone, mail, Mail)
			pages->addData(dto);

	}
	return pages;
}