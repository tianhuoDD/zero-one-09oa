/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "OrgMemDAO.h"
//#include "OrgMemMapper.h"
#include <sstream>

int OrgMemDAO::deleteById(string orgID, string personID)
{
	stringstream sqlDelete, sqlDelete2,sqlDelete3;
	sqlDelete<<"SELECT xorderColumn INTO @deleted_xorderColumn FROM org_group_personlist WHERE `GROUP_XID`=" << orgID << " AND `xpersonList`=" << personID << ";";
	sqlDelete2 << "DELETE FROM `org_group_personlist` WHERE `GROUP_XID`=" << orgID << " AND `xpersonList`=" << personID << ";";
	sqlDelete3 << "UPDATE org_group_personlist SET xorderColumn = xorderColumn - 1 WHERE xorderColumn > @deleted_xorderColumn;";
	return sqlSession->execute(sqlDelete3.str())+ sqlSession->execute(sqlDelete2.str())+ sqlSession->execute(sqlDelete.str());

}
int OrgJobDAO::add(string personID,string dutyID) {
	{
		stringstream sqlAdd,sqlAdd2;		
		sqlAdd << "INSERT INTO org_unitduty_identitylist VALUES (" << dutyID << "," << personID << ",-1);";
		sqlAdd2 << "UPDATE org_unitduty_identitylist SET xorderColumn = xorderColumn + 1;";
		return sqlSession->execute(sqlAdd2.str())+ sqlSession->execute(sqlAdd.str());
	}
}
int OrgJobDAO::deleteById(string personID, string dutyID)
{
	stringstream sqlDelete, sqlDelete2,sqlDelete3;
	sqlDelete<<"SELECT xorderColumn INTO @deleted_xorderColumn FROM org_unitduty_identitylist WHERE `UNITDUTY_XID`=" << dutyID << " AND `xidentityList`=" << personID << ";";
	sqlDelete2 << "DELETE FROM `org_unitduty_identitylist` WHERE `UNITDUTY_XID`=" << dutyID << " AND `xidentityList`=" << personID << ";";
	sqlDelete3 << "UPDATE org_unitduty_identitylist SET xorderColumn = xorderColumn - 1 WHERE xorderColumn > @deleted_xorderColumn;";
	return sqlSession->execute(sqlDelete3.str())+ sqlSession->execute(sqlDelete2.str())+ sqlSession->execute(sqlDelete.str());
}