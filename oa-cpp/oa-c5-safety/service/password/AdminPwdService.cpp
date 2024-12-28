#include "stdafx.h"
#include "AdminPwdService.h"
#include "../../Macros.h"
#include "domain/do/password/admin/AdminPwdDO.h"
#include "dao/password/AdminPwdDAO.h"

AdminPwdDTO::Wrapper AdminPwdService::listAll(const String& xid)
{
	AdminPwdDAO dao;

	list<AdminPwdDO> result = dao.selectByXId(xid);
	//根据xid查找
	auto dto = AdminPwdDTO::createShared();
	// 将DO转换成DTO
	for (AdminPwdDO sub : result)
	{
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Id, xoldpassword, OldPassword, xnewpassword, NewPassword, xconfirmpassword, ConfirmPassword, xchangePasswordTime, ChangePasswordTime, xpasswordExpiredTime, PasswordExpiredTime);
	}
	return dto;
}

uint64_t AdminPwdService::saveData(const AdminPwdDTO::Wrapper& dto)
{
	// 组装DO数据
	AdminPwdDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, xid, OldPassword, xoldpassword, NewPassword, xnewpassword, ConfirmPassword, xconfirmpassword, ChangePasswordTime, xchangePasswordTime, PasswordExpiredTime, xpasswordExpiredTime);
	// 执行数据添加
	AdminPwdDAO dao;
	return dao.insert(data);
}

bool AdminPwdService::updateData(const AdminPwdDTO::Wrapper& dto)
{
	// 组装DO数据
	AdminPwdDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, xid, OldPassword, xoldpassword, NewPassword, xnewpassword, ConfirmPassword, xconfirmpassword, ChangePasswordTime, xchangePasswordTime, PasswordExpiredTime, xpasswordExpiredTime);
	// 执行数据修改
	AdminPwdDAO dao;
	return dao.update(data) == 1;
}

bool AdminPwdService::removeData(string xid)
{
	AdminPwdDAO dao;
	return dao.deleteByXId(xid) == 1;
}
