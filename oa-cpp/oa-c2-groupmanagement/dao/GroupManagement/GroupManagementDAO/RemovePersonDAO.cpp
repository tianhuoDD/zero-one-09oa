/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 26日 星期六 09:37:55 CST
*/
#include "stdafx.h"
#include "RemovePersonDAO.h"
#include "RemovePersonMapper.h"
#include <sstream>

int RemovePersonDAO::deleteByXgroup_Xperson(const string& group_person)
{
	string GROUP_XID = "";
	string xpersonList = "";
	int pos = group_person.find('_');
	GROUP_XID = group_person.substr(0, pos);
	//cout << "pos = " << pos << endl;
	//cout << "GROUP_XID = " << GROUP_XID << endl;
	xpersonList = group_person.substr(pos+1, group_person.size() - pos-1);
	//cout << "xpersonList = " << xpersonList << endl;
	string sql = "DELETE FROM `org_group_personlist` WHERE `GROUP_XID`=? AND `xpersonList`=?";
	return sqlSession->executeUpdate(sql, "%s%s", GROUP_XID, xpersonList);
}