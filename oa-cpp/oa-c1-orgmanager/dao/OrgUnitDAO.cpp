#include "stdafx.h"
#include "OrgUnitDAO.h"
#include "OrgUnitMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define ORGUNIT_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->unit_xname) { \
		sql << " AND o.`xname`=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->unit_xname.getValue("")); \
}

/*
uint64_t OrgUnitDAO::count(const OrgUnitQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM org_unit o "
		<< "LEFT JOIN org_person p ON o.xid = p.xid "  // 修改为使用 xid 连接 org_unit 和 org_person
		<< "LEFT JOIN org_unit_typelist t ON o.xid = t.UNIT_XID";  // 修改为使用 xid 连接 org_unit 和 org_unit_typelist
	ORGUNIT_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<OrgUnitDO> OrgUnitDAO::selectWithPage(const OrgUnitQuery::Wrapper& query)
{
	stringstream sql;
	// 进行联表查询
	sql << "SELECT o.xid, o.xname as unit_xname, o.xunique, t.xtypeList, o.xshortName, "
		<< "o.xdescription, p.xname as person_xname, o.xsuperior, o.xorderNumber "
		<< "FROM org_unit o "
		<< "LEFT JOIN org_person p ON o.xid = p.xid "  // 使用 xid 连接 org_unit 和 org_person
		<< "LEFT JOIN org_unit_typelist t ON o.xid = t.UNIT_XID";  // 使用 xid 连接 org_unit 和 org_unit_typelist


	ORGUNIT_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	OrgUnitMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<OrgUnitDO, OrgUnitMapper>(sqlStr, mapper, params);
}
*/

std::list<OrgUnitDO> OrgUnitDAO::selectByName(const string& unit_xname)
{
	// 在查询中加入org_person和org_unit_typelist表
	string sql = "SELECT o.xid, o.xname as unit_xname, o.xunique, t.xtypeList, o.xshortName, "
				 "o.xdescription, p.xname as person_xname, o.xsuperior, o.xorderNumber "
				 "FROM org_unit o "
				 "LEFT JOIN org_person p ON o.xid = p.xid "  // 使用 xid 连接 org_unit 和 org_person
				 "LEFT JOIN org_unit_typelist t ON o.xid = t.UNIT_XID "  // 使用 xid 连接 org_unit 和 org_unit_typelist
				 "WHERE o.`xname` LIKE CONCAT('%',?,'%')";

	OrgUnitMapper mapper;
	return sqlSession->executeQuery<OrgUnitDO, OrgUnitMapper>(sql, mapper, "%s", unit_xname);
}


int OrgUnitDAO::update(const OrgUnitDO& uObj)
{
	// 更新 org_unit 表中的字段
	string sqlOrgUnit = "UPDATE `org_unit` SET `xname`=?, `xunique`=?, `xshortName`=?, "
		"`xdescription`=?, `xsuperior`=?, `xorderNumber`=? WHERE `xid`=?";

	sqlSession->executeUpdate(sqlOrgUnit, "%s%s%s%s%s%i%s",
		uObj.getUnit_xname(), uObj.getXunique(), uObj.getXshortName(),
		uObj.getXdescription(), uObj.getXsuperior(), uObj.getXorderNumber(),  // 使用 %d 来处理整数类型
		uObj.getXid());

	// 更新 org_person 表中的 xname 字段
	string sqlOrgPerson = "UPDATE `org_person` SET `xname`=? WHERE `xid`=?";

	sqlSession->executeUpdate(sqlOrgPerson, "%s%s", uObj.getPerson_xname(), uObj.getXid());

	// 更新 org_unit_typelist 表中的 xtypeList 字段
	string sqlOrgUnitTypeList = "UPDATE `org_unit_typelist` SET `xtypeList`=? WHERE `UNIT_XID`=?";  // 使用 UNIT_XID 来更新

	sqlSession->executeUpdate(sqlOrgUnitTypeList, "%s%s", uObj.getXtypeList(), uObj.getXid());

	return 1; // 假设所有更新都成功
}