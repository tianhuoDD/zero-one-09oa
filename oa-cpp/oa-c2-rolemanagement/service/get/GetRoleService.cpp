#include "stdafx.h"
#include"GetRoleService.h"
#include "dao/get/GetRoleDAO.h"
#include "domain/do/get/GetRoleDO.h"
#include"domain/dto/get/GetroleDTO.h"
#include"domain/vo/get/GetroleVO.h"

GetroleVO::Wrapper GetRoleService::GetRoleById(const string roleId)
{
	//�������ض���
	auto ans = GetroleVO::createShared();
	//����dao����ѯ����DO
	GetRoleDAO dao;
	list<GetRoleDO> result = dao.selectById(roleId);
	// ֱ�ӽ�DOת����VO
	for (GetRoleDO sub : result)
	{
		// �������
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
//	//�������ض���
//	auto ans = GetroleVO::createShared();
//	//����dao����ѯ����DO
//	GetRoleDAO dao;
//	list<GetRoleDO> result = dao.selectByName(roleName);
//	// ֱ�ӽ�DOת����VO
//	for (GetRoleDO sub : result)
//	{
//		// �������
//		ans->name = sub.getName();
//		ans->key = sub.getKey();
//		ans->refer = sub.getRefer();
//
//	}
//	return ans;
//
//}

