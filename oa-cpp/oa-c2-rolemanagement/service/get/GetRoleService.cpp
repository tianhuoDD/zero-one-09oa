#include "stdafx.h"
#include"GetRoleService.h"
#include "dao/get/GetRoleDAO.h"
#include "domain/do/get/GetRoleDO.h"
#include"domain/dto/get/GetroleDTO.h"
#include"domain/vo/get/GetroleVO.h"

GetroleVO::Wrapper GetRoleService::GetRoleById(const string roleId)
{
	//构建返回对象
	auto ans = GetroleVO::createShared();
	//创建dao，查询返回DO
	GetRoleDAO dao;
	list<GetRoleDO> result = dao.selectById(roleId);
	// 直接将DO转换成VO
	for (GetRoleDO sub : result)
	{
		// 填充数据
		ans->name = sub.getName();
		ans->key = sub.getKey();
		ans->refer = sub.getRefer();
		ans->fullName = sub.getFullname();
		ans->startTime = sub.getStartTime();
		ans->endTime = sub.getEndTime();
		


	}
	return ans;
}
//
//GetroleVO::Wrapper GetRoleService::GetRoleByName(const string roleName)
//{
//	//构建返回对象
//	auto ans = GetroleVO::createShared();
//	//创建dao，查询返回DO
//	GetRoleDAO dao;
//	list<GetRoleDO> result = dao.selectByName(roleName);
//	// 直接将DO转换成VO
//	for (GetRoleDO sub : result)
//	{
//		// 填充数据
//		ans->name = sub.getName();
//		ans->key = sub.getKey();
//		ans->refer = sub.getRefer();
//
//	}
//	return ans;
//
//}

