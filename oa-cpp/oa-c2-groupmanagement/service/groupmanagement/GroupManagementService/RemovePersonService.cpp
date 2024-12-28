/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 26日 星期六 09:37:55 CST
*/
#include "stdafx.h"
#include "RemovePersonService.h"
#include "dao/GroupManagement/GroupManagementDAO/RemovePersonDAO.h"

bool RemovePersonService::removeData(const string& group_person)
{
	RemovePersonDAO dao;
	return dao.deleteByXgroup_Xperson(group_person) == 1;
}
