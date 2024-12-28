#include "stdafx.h"
#include "DutySettingDAO.h"
#include <sstream>

int DutySettingDAO::deleteByIdentity(const DutySettingDTO::Wrapper& dto)
{
	string sql = "DELETE FROM org_unitduty_identitylist WHERE xidentityList='"+ dto->xidentity.getValue("") +"'";
	return sqlSession->executeUpdate(sql);
}

int DutySettingDAO::insert(const list<org_unitduty_identitylistDO>& data)
{
	int res = 0;
	for (auto& it : data) {
		string sql = "INSERT INTO org_unitduty_identitylist (UNITDUTY_XID, xidentityList, xorderColumn) VALUES ('"+ it.getUNITDUTY_XID() + "','" + it.getXidentityList() + "', 0)";
		res+= sqlSession->executeUpdate(sql);
	}
	return res;
}
