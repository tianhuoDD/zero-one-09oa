#include "stdafx.h"
#include "ApplicationDAO.h"
#include "ApplicationTypesMapper.h"
#include "ApplicationPropertiesMapper.h"
#include "ApplicationMapper.h"
#include "ApplicationNameMapper.h"

list<ApplicationTypesDO> ApplicationDAO::selectAppTypes() {
	string sqlStr = "SELECT xapplicationCategory, COUNT(*) AS xcount FROM pp_e_application GROUP BY xapplicationCategory";
	ApplicationTypesMapper mapper;
	return sqlSession->executeQuery<ApplicationTypesDO, ApplicationTypesMapper>(sqlStr, mapper);
}

list<ApplicationPropertiesDO> ApplicationDAO::selectAppProperties(const string& id) {
	stringstream sql;
	sql << "SELECT xid, xicon, xcreateTime, xcreatorPerson, xdescription, xlastUpdatePerson, xlastUpdateTime, xname, xupdateTime, xproperties, xalias, xapplicationCategory FROM pp_e_application WHERE xid = ?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, id);
	ApplicationPropertiesMapper mapper;
	return sqlSession->executeQuery<ApplicationPropertiesDO, ApplicationPropertiesMapper>(sql.str(), mapper, params);
}

list<AvailableGroupListDO> ApplicationDAO::selectAvailableGroupList(const string& appid) {
	string sqlStr = "SELECT * FROM pp_e_application_availablegrouplist WHERE APPLICATION_XID = ?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, appid);
	AvailableGroupListMapper mapper;
	return sqlSession->executeQuery<AvailableGroupListDO, AvailableGroupListMapper>(sqlStr, mapper, params);
	/*auto tmpRes = sqlSession->executeQuery<AvailableGroupListDO, AvailableGroupListMapper>(sqlStr, mapper, params);
	string sqlStrSub = "SELECT xdistinguishedName FROM org_group WHERE xid = ?";
	for (auto& i : tmpRes) {
		auto res = sqlSession->executeQuery<ApplicationNameDO, ApplicationNameMapper>(sqlStrSub, ApplicationNameMapper(), "%s", i.getXavailableGroupList());
		if (res.size() > 0) {
			i.setXavailableGroupList(res.front().getName());
		} else cout << "DAO error: no such group\n";
	}
	return tmpRes;*/
}

list<AvailableIdentityListDO> ApplicationDAO::selectAvailableIdentityList(const string& appid) {
	string sqlStr = "SELECT * FROM pp_e_application_availableidentitylist WHERE APPLICATION_XID = ?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, appid);
	AvailableIdentityListMapper mapper;
	return sqlSession->executeQuery<AvailableIdentityListDO, AvailableIdentityListMapper>(sqlStr, mapper, params);
	/*auto tmpRes = sqlSession->executeQuery<AvailableIdentityListDO, AvailableIdentityListMapper>(sqlStr, mapper, params);
	string sqlStrSub = "SELECT xdistinguishedName FROM org_identity WHERE xid = ?";
	for (auto& i : tmpRes) {
		auto res = sqlSession->executeQuery<ApplicationNameDO, ApplicationNameMapper>(sqlStrSub, ApplicationNameMapper(), "%s", i.getXavailableIdentityList());
		if (res.size() > 0) {
			i.setXavailableIdentityList(res.front().getName());
		} else cout << "DAO error: no such identity\n";
	}
	return tmpRes;*/
}

list<AvailableUnitListDO> ApplicationDAO::selectAvailableUnitList(const string& appid) {
	string sqlStr = "SELECT * FROM pp_e_application_availableunitlist WHERE APPLICATION_XID = ?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, appid);
	AvailableUnitListMapper mapper;
	return sqlSession->executeQuery<AvailableUnitListDO, AvailableUnitListMapper>(sqlStr, mapper, params);
	/*auto tmpRes = sqlSession->executeQuery<AvailableUnitListDO, AvailableUnitListMapper>(sqlStr, mapper, params);
	string sqlStrSub = "SELECT xdistinguishedName FROM org_unit WHERE xid = ?";
	for (auto& i : tmpRes) {
		auto res = sqlSession->executeQuery<ApplicationNameDO, ApplicationNameMapper>(sqlStrSub, ApplicationNameMapper(), "%s", i.getXavailableUnitList());
		if (res.size() > 0) {
			i.setXavailableUnitList(res.front().getName());
		} else cout << "DAO error: no such unit\n";
	}
	return tmpRes;*/
}

list<ControllerListDO> ApplicationDAO::selectControllerList(const string& appid) {
	string sqlStr = "SELECT * FROM pp_e_application_controllerlist WHERE APPLICATION_XID = ?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, appid);
	ControllerListMapper mapper;
	return sqlSession->executeQuery<ControllerListDO, ControllerListMapper>(sqlStr, mapper, params);
	/*auto tmpRes = sqlSession->executeQuery<ControllerListDO, ControllerListMapper>(sqlStr, mapper, params);
	string sqlStrSub = "SELECT xdistinguishedName FROM org_person WHERE xid = ?";
	for (auto& i : tmpRes) {
		auto res = sqlSession->executeQuery<ApplicationNameDO, ApplicationNameMapper>(sqlStrSub, ApplicationNameMapper(), "%s", i.getXcontrollerList());
		if (res.size() > 0) {
			i.setXcontrollerList(res.front().getName());
		} else cout << "DAO error: no such person\n";
	}
	return tmpRes;*/
}

int ApplicationDAO::updateAppProperties(const ApplicationPropertiesDO& obj) {
	string sqlStr = "UPDATE pp_e_application SET xicon = ?, xalias = ?, xapplicationCategory = ?, xdescription = ?, xlastUpdatePerson = ?, xlastUpdateTime = ?, xname = ?, xupdateTime = ?, xproperties = ? WHERE xid = ?";
	return sqlSession->executeUpdate(sqlStr, "%s%s%s%s%s%dt%s%dt%s%s", obj.getXicon(), obj.getXalias(), obj.getXapplicationCategory(), obj.getXdescription(), obj.getXlastUpdatePerson(), obj.getXlastUpdateTime(), obj.getXname(), obj.getXupdateTime(), obj.getXproperties(), obj.getXid());
}

int ApplicationDAO::insertAvailableIdentity(const AvailableIdentityListDO& obj) {
	string sqlStr = "INSERT INTO pp_e_application_availableidentitylist (APPLICATION_XID, XORDERCOLUMN, XAVAILABLEIDENTITYLIST) VALUES (?, ?, ?)";
	return sqlSession->executeUpdate(sqlStr, "%s%i%s", obj.getXid(), obj.getXorderColumn(), obj.getXavailableIdentityList());
}

int ApplicationDAO::insertAvailableGroup(const AvailableGroupListDO& obj) {
	string sqlStr = "INSERT INTO pp_e_application_availablegrouplist (APPLICATION_XID, XORDERCOLUMN, XAVAILABLEGROUPLIST) VALUES (?, ?, ?)";
	return sqlSession->executeUpdate(sqlStr, "%s%i%s", obj.getXid(), obj.getXorderColumn(), obj.getXavailableGroupList());
}

int ApplicationDAO::insertController(const ControllerListDO& obj) {
	string sqlStr = "INSERT INTO pp_e_application_controllerlist (APPLICATION_XID, XORDERCOLUMN, XCONTROLLERLIST) VALUES (?, ?, ?)";
	return sqlSession->executeUpdate(sqlStr, "%s%i%s", obj.getXid(), obj.getXorderColumn(), obj.getXcontrollerList());
}

int ApplicationDAO::insertAvailableUnit(const AvailableUnitListDO& obj) {
	string sqlStr = "INSERT INTO pp_e_application_availableunitlist (APPLICATION_XID, XORDERCOLUMN, XAVAILABLEUNITLIST) VALUES (?, ?, ?)";
	return sqlSession->executeUpdate(sqlStr, "%s%i%s", obj.getXid(), obj.getXorderColumn(), obj.getXavailableUnitList());
}



list<ApplicationNameDO> ApplicationDAO::selectAvailableIdentityId(const string& identityName) {
	string sqlStr = "SELECT xid FROM org_identity WHERE xdistinguishedName = ?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, identityName);
	ApplicationNameMapper mapper;
	return sqlSession->executeQuery<ApplicationNameDO, ApplicationNameMapper>(sqlStr, mapper, params);
}

list<ApplicationNameDO> ApplicationDAO::selectAvailableGroupId(const string& groupName) {
	string sqlStr = "SELECT xid FROM org_group WHERE xdistinguishedName = ?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, groupName);
	ApplicationNameMapper mapper;
	return sqlSession->executeQuery<ApplicationNameDO, ApplicationNameMapper>(sqlStr, mapper, params);
}

list<ApplicationNameDO> ApplicationDAO::selectAvailableUnitId(const string& unitName) {
	string sqlStr = "SELECT xid FROM org_unit WHERE xdistinguishedName = ?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, unitName);
	ApplicationNameMapper mapper;
	return sqlSession->executeQuery<ApplicationNameDO, ApplicationNameMapper>(sqlStr, mapper, params);

}

list<ApplicationNameDO> ApplicationDAO::selectControllerId(const string& controllerName) {
	string sqlStr = "SELECT xid FROM org_person WHERE xdistinguishedName = ?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, controllerName);
	ApplicationNameMapper mapper;
	return sqlSession->executeQuery<ApplicationNameDO, ApplicationNameMapper>(sqlStr, mapper, params);
}

int ApplicationDAO::deleteAvailableIdentity(const string& appId) {
	string sqlStr = "DELETE FROM pp_e_application_availableidentitylist WHERE APPLICATION_XID = ?";
	return sqlSession->executeUpdate(sqlStr, "%s", appId);
}

int ApplicationDAO::deleteAvailableGroup(const string& appId) {
	string sqlStr = "DELETE FROM pp_e_application_availablegrouplist WHERE APPLICATION_XID = ?";
	return sqlSession->executeUpdate(sqlStr, "%s", appId);
}

int ApplicationDAO::deleteController(const string& appId) {
	string sqlStr = "DELETE FROM pp_e_application_controllerlist WHERE APPLICATION_XID = ?";
	return sqlSession->executeUpdate(sqlStr, "%s", appId);
}

int ApplicationDAO::deleteAvailableUnit(const string& appId) {
	string sqlStr = "DELETE FROM pp_e_application_availableunitlist WHERE APPLICATION_XID = ?";
	return sqlSession->executeUpdate(sqlStr, "%s", appId);
}

int ApplicationDAO::updateProp(const string& appId, const string& propJson) {
	string sqlStr = "UPDATE pp_e_application SET xproperties = ? WHERE xid = ?";
	return sqlSession->executeUpdate(sqlStr, "%s%s", propJson, appId);
}


#define APPLICATION_TERAM_PARSE(query,sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->xid) { \
	sql << " AND `xid`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xid.getValue("")); \
} \
if (query->xname) { \
	sql << " AND `xname`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xname.getValue("")); \
} \
if (query->xalias) { \
	sql << " AND xalias=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xalias.getValue("")); \
} \
if (query->xapplicationCategory) { \
	sql << " AND xapplicationCategory=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xapplicationCategory.getValue("")); \
}


//uint64_t 表示在用户查询条件下，count(*)的总条数
uint64_t ApplicationDAO::count(const ApplicationQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `zo_oa`.`pp_e_application` ";
	APPLICATION_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ApplicationDO> ApplicationDAO::selectWithPage(const ApplicationQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT xname,xalias,xapplicationCategory ,xdescription,xid,xcreateTime,xsequence,xupdateTime,xdistributeFactor,\
			xcreatorPerson,xicon,xiconHue,xlastUpdatePerson,\
			xlastUpdateTime,xproperties FROM `zo_oa`.`pp_e_application` ";
	APPLICATION_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	//select * from pp_e_application where 1=1 and xname = "?" and xalias ="?" and xapplicationCategory = "?"
	//limit 3,10
	//std::vector<SqlParam> params
	//{ (s,"xname"),(s,"xalias"),(s,"xapplicationCategory")}
	ApplicationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ApplicationDO, ApplicationMapper>(sqlStr, mapper, params);
}

std::list<ApplicationNameDO> ApplicationDAO::selectApplicationName()
{
	stringstream sql;
	sql << "SELECT xname FROM `zo_oa`.`pp_e_application`";
	ApplicationNameMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ApplicationNameDO, ApplicationNameMapper>(sqlStr, mapper);
}

uint64_t ApplicationDAO::insert(const ApplicationDO& iObj)
{
	string sql= "INSERT INTO `zo_oa`.`pp_e_application` (`xname`, `xalias`, `xapplicationCategory`, `xdescription`, `xid` , `xcreateTime`, `xsequence`,`xupdateTime`,`xcreatorPerson`,`xlastUpdatePerson`,`xlastUpdateTime` , `xproperties`, `xicon` , `xiconHue`,`xdistributeFactor` ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, null, null, null)";

	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%s%s%s%s", iObj.getName(), iObj.getAlias(), iObj.getApplicationCategory()
									,iObj.getDescription(),iObj.getId(),iObj.getCreateTime(),iObj.getSequence(),iObj.getUpdateTime()
									, iObj.getCreatorPerson(), iObj.getLastUpdatePerson(), iObj.getLastUpdateTime()
									,iObj.getProperties());
	
}


uint64_t ApplicationDAO::deleteById(std::string id)
{
	ApplicationDAO dao;
	string sql = "DELETE FROM `zo_oa`.`pp_e_application` WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}

