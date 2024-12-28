#include "stdafx.h"
#include "UserLoginConfigurationService.h"
#include "../../dao/userloginconfiguration/UserLoginConfigurationDAO.h"
#include "../../Macros.h"
UserLoginConfigurationDTO::Wrapper UserLoginConfigurationService::listAll(const String& username)
{

	
	//根据用户名查询数据
	UserLoginConfigurationDAO dao;

	list<UserLoginConfigurationDO> result = dao.selectByUserName(username);

	//根据username查找，只会有一条数据返回
	auto dto = UserLoginConfigurationDTO::createShared();

	// 将DO转换成DTO
	for (UserLoginConfigurationDO sub : result)
	{
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		//Id, id, UserName, username, Password, password, LastLoginTime, lastlogintime, EmailAddress, emailaddress, MobilePhone,mobilephone, LoginAttempts, loginattempts, Permission, permission, IpAddress, ipaddress)
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, username, UserName, password, Password, lastlogintime, LastLoginTime, emailaddress, EmailAddress, mobilephone, MobilePhone, loginattempts, LoginAttempts, permission, Permission, ipaddress, IpAddress);
			
	}
	return dto;
}

uint64_t UserLoginConfigurationService::saveData(const UserLoginConfigurationDTO::Wrapper& dto)
{
	// 组装DO数据
	UserLoginConfigurationDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id ,UserName, username, Password, password, LastLoginTime, lastlogintime, EmailAddress, emailaddress, MobilePhone, mobilephone, LoginAttempts, loginattempts, Permission, permission, IpAddress, ipaddress);
		// 执行数据添加
	UserLoginConfigurationDAO dao;
	return dao.insert(data);
}

bool UserLoginConfigurationService::updateData(const UserLoginConfigurationDTO::Wrapper& dto)
{
	// 组装DO数据
	UserLoginConfigurationDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, UserName, username, Password, password, LastLoginTime, lastlogintime, EmailAddress, emailaddress, MobilePhone, mobilephone, LoginAttempts, loginattempts, Permission, permission, IpAddress, ipaddress);
	// 执行数据修改
	UserLoginConfigurationDAO dao;
	return dao.update(data) == 1;
}

bool UserLoginConfigurationService::removeData(string username)
{
	UserLoginConfigurationDAO dao;
	return dao.deleteByUserName(username) == 1;
}
