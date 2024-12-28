#include "stdafx.h"
#include "SearchDutyDAO.h"
#include "SearchDutyMapper.h"
#include <sstream>
#include <cassert>

unsigned char FromHex(unsigned char x)
{
	unsigned char y;
	if (x >= 'A' && x <= 'Z') y = x - 'A' + 10;
	else if (x >= 'a' && x <= 'z') y = x - 'a' + 10;
	else if (x >= '0' && x <= '9') y = x - '0';
	else assert(0);
	return y;
}
std::list<pair<org_unitdutyDO, org_unitDO>> SearchDutyDAO::selectDuty(const oatpp::String& query)
{
	std::string strTemp = "";
	size_t length = query.getValue("").length();
	for (size_t i = 0; i < length; i++)
	{
		if (query.getValue("")[i] == '+') strTemp += ' ';
		else if (query.getValue("")[i] == '%')
		{
			assert(i + 2 < length);
			unsigned char high = FromHex((unsigned char)query.getValue("")[++i]);
			unsigned char low = FromHex((unsigned char)query.getValue("")[++i]);
			strTemp += high * 16 + low;
		}
		else strTemp += query.getValue("")[i];
	}
	stringstream sql;
	sql << "SELECT org_unitduty.xname,xlevelName FROM org_unitduty,org_unit ";
	sql << "WHERE org_unitduty.xunit=org_unit.xid";
	SqlParams params;
	if (!query->empty()) {
		sql << " AND (org_unitduty.xname LIKE '%"<< strTemp << "%'";
		//SQLPARAMS_PUSH(params, "s", std::string, query.getValue(""));
		sql << " OR org_unitduty.xpinyin LIKE '%"<< strTemp <<"%'";
		//SQLPARAMS_PUSH(params, "s", std::string, query.getValue(""));
		sql << " OR org_unitduty.xpinyinInitial LIKE '%"<< strTemp <<"%')";
		//SQLPARAMS_PUSH(params, "s", std::string, query.getValue(""));
	}
	SearchDutyMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<pair<org_unitdutyDO, org_unitDO>, SearchDutyMapper>(sqlStr, mapper);
}

