#ifndef _PersonalManageDAO_CPP_
#define _PersonalManageDAO_CPP_
#include "stdafx.h"
#include "PersonalManageDAO.h"
#include "PersonalManageMapper.h"
#include <sstream>


org_personDO PersonalManageDAO::selectbyxunique(const string& xunique)
{
	PersonalManageMapper mapper;
	int count = 0;
	std::string sql_hasxunique = "SELECT COUNT(*) FROM org_person WHERE xunique = ? "; 
	count = sqlSession->executeQueryNumerical(sql_hasxunique, "%s", xunique); 
	if (count == 0) {
		throw std::invalid_argument("the xunique does not exist");
	}
	string sql = "SELECT xunique, xname, xmobile, xofficePhone, xgenderType, xmail, xqq, xweixin, xboardDate, xipAddress, xsubjectSecurityClearance, xemployee, xbirthday, xdescription, xstatus, xsuperior, xid FROM org_person WHERE xunique = ?";
	return sqlSession->executeQuery<org_personDO, PersonalManageMapper>(sql,mapper,"%s", xunique).front();
}

bool PersonalManageDAO::update(const org_personDO& uObj)
{
	int count = 0;
	std::string sql_hasxunique = "SELECT COUNT(*) FROM org_person WHERE xunique = ? AND xid != ?";
	count = sqlSession->executeQueryNumerical(sql_hasxunique, "%s%s", uObj.getXunique(), uObj.getXid());
	if (count > 0) {
		throw std::invalid_argument("the xunique already exists");
	}
	string sql = "UPDATE org_person SET `xpassword`= ?,`xupdatetime`= ?,`xdistinguishedName`= ?, `xunique` = ?, `xname` = ?, `xmobile` = ?, `xofficePhone` = ?, `xgenderType` = ?, `xmail` = ?, `xqq` = ?, `xweixin` = ?, `xboardDate` = COALESCE(NULLIF(?, ''), NULL), `xipAddress` = ?, `xsubjectSecurityClearance` = ?, `xemployee` = ?, `xbirthday` = COALESCE(NULLIF(?, ''), NULL), `xdescription` = ?, `xsuperior` = ? WHERE `xid` = ?";
	auto res = sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%i%s%s%s%s%s",
		uObj.getXpassword(), uObj.getXupdateTime(),uObj.getXdistinguishedName(), 
		uObj.getXunique(), uObj.getXname(), uObj.getXmobile(), uObj.getXofficePhone(),
		uObj.getXgenderType(), uObj.getXmail(), uObj.getXqq(),
		uObj.getXweixin(), uObj.getXboardDate(),
		uObj.getXipAddress(), uObj.getXsubjectSecurityClearance(), uObj.getXemployee(),
		uObj.getXbirthday(), uObj.getXdescription(),
		uObj.getXsuperior(), uObj.getXid());
	return res;
}

#endif // !_PersonalManageDAO_CPP_

