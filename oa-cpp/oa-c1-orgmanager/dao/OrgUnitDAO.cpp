#include "stdafx.h"
#include "OrgUnitDAO.h"
#include "OrgUnitMapper.h"
#include <sstream>

//�������������꣬�����ظ�����
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
		<< "LEFT JOIN org_person p ON o.xid = p.xid "  // �޸�Ϊʹ�� xid ���� org_unit �� org_person
		<< "LEFT JOIN org_unit_typelist t ON o.xid = t.UNIT_XID";  // �޸�Ϊʹ�� xid ���� org_unit �� org_unit_typelist
	ORGUNIT_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<OrgUnitDO> OrgUnitDAO::selectWithPage(const OrgUnitQuery::Wrapper& query)
{
	stringstream sql;
	// ���������ѯ
	sql << "SELECT o.xid, o.xname as unit_xname, o.xunique, t.xtypeList, o.xshortName, "
		<< "o.xdescription, p.xname as person_xname, o.xsuperior, o.xorderNumber "
		<< "FROM org_unit o "
		<< "LEFT JOIN org_person p ON o.xid = p.xid "  // ʹ�� xid ���� org_unit �� org_person
		<< "LEFT JOIN org_unit_typelist t ON o.xid = t.UNIT_XID";  // ʹ�� xid ���� org_unit �� org_unit_typelist


	ORGUNIT_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	OrgUnitMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<OrgUnitDO, OrgUnitMapper>(sqlStr, mapper, params);
}
*/

std::list<OrgUnitDO> OrgUnitDAO::selectByName(const string& unit_xname)
{
	// �ڲ�ѯ�м���org_person��org_unit_typelist��
	string sql = "SELECT o.xid, o.xname as unit_xname, o.xunique, t.xtypeList, o.xshortName, "
				 "o.xdescription, p.xname as person_xname, o.xsuperior, o.xorderNumber "
				 "FROM org_unit o "
				 "LEFT JOIN org_person p ON o.xid = p.xid "  // ʹ�� xid ���� org_unit �� org_person
				 "LEFT JOIN org_unit_typelist t ON o.xid = t.UNIT_XID "  // ʹ�� xid ���� org_unit �� org_unit_typelist
				 "WHERE o.`xname` LIKE CONCAT('%',?,'%')";

	OrgUnitMapper mapper;
	return sqlSession->executeQuery<OrgUnitDO, OrgUnitMapper>(sql, mapper, "%s", unit_xname);
}


int OrgUnitDAO::update(const OrgUnitDO& uObj)
{
	// ���� org_unit ���е��ֶ�
	string sqlOrgUnit = "UPDATE `org_unit` SET `xname`=?, `xunique`=?, `xshortName`=?, "
		"`xdescription`=?, `xsuperior`=?, `xorderNumber`=? WHERE `xid`=?";

	sqlSession->executeUpdate(sqlOrgUnit, "%s%s%s%s%s%i%s",
		uObj.getUnit_xname(), uObj.getXunique(), uObj.getXshortName(),
		uObj.getXdescription(), uObj.getXsuperior(), uObj.getXorderNumber(),  // ʹ�� %d ��������������
		uObj.getXid());

	// ���� org_person ���е� xname �ֶ�
	string sqlOrgPerson = "UPDATE `org_person` SET `xname`=? WHERE `xid`=?";

	sqlSession->executeUpdate(sqlOrgPerson, "%s%s", uObj.getPerson_xname(), uObj.getXid());

	// ���� org_unit_typelist ���е� xtypeList �ֶ�
	string sqlOrgUnitTypeList = "UPDATE `org_unit_typelist` SET `xtypeList`=? WHERE `UNIT_XID`=?";  // ʹ�� UNIT_XID ������

	sqlSession->executeUpdate(sqlOrgUnitTypeList, "%s%s", uObj.getXtypeList(), uObj.getXid());

	return 1; // �������и��¶��ɹ�
}