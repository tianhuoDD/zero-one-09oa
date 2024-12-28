#include "stdafx.h"
#include "FormDAO.h"
#include "FormMapper.h"
#include "FormNameMapper.h"
#include <sstream>

uint64_t FormDAO::insertToForm(const FormDO& data) {
	string sql = "INSERT INTO `pp_e_form` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xalias`, `xapplication`, `xcategory`, `xdata`, `xdescription`, `xhasMobile`, `xicon`, `xlastUpdatePerson`, `xlastUpdateTime`, `xmobileData`, `xname`, `xproperties`) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%dt%s%dt%s%s%s%s%s%b%s%s%dt%s%s%s", data.getId(), data.getCreateTime(), data.getSequence(), data.getUpdateTime(), data.getAlias(), data.getApplication(), data.getCategory(), data.getData(), data.getDescription(), data.getHasMobile(), data.getIcon(), data.getLastUpdatePerson(), data.getLastUpdateTime(), data.getMobileData(), data.getName(), data.getProperties());
}

int FormDAO::update(const FormDO& data) {
	string sql = "UPDATE `pp_e_form` SET `xupdateTime`=?, `xalias`=?, `xcategory`=?, `xdata`=?, `xdescription`=?, `xhasMobile`=?, `xicon`=?, `xlastUpdatePerson`=?, `xlastUpdateTime`=?, `xmobileData`=?, `xname`=?, `xproperties`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%dt%s%s%s%s%b%s%s%dt%s%s%s%s", data.getUpdateTime(), data.getAlias(), data.getCategory(), data.getData(), data.getDescription(), data.getHasMobile(), data.getIcon(), data.getLastUpdatePerson(), data.getLastUpdateTime(), data.getMobileData(), data.getName(), data.getProperties(), data.getId());
}

int FormDAO::deleteById(const oatpp::String& id) {
	string sql = "DELETE FROM `pp_e_form` WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%s", string(id->c_str()));
}

uint64_t FormDAO::insertToFormVersion(const FormDO& data) {
	string sql = "INSERT INTO `pp_e_formversion` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdata`, `xform`, `xperson`) VALUES(?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%dt%s%dt%s%s%s", data.getId(), data.getCreateTime(), data.getSequence(), data.getUpdateTime(), data.getData(), data.getForm(), data.getPerson());
}

int FormDAO::deleteVersionByFormId(const string& formId) {
	string sql = "DELETE FROM `pp_e_formversion` WHERE `xform`=?";
	return sqlSession->executeUpdate(sql, "%s", formId);
}

//定义条件解析宏，减少重复代码
//防止sql注入问题
#define FORM_TREAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->xcategory) { \
	sql << " AND `xcategory`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xcategory.getValue("")); \
} \
if (query->xapplication) { \
	sql << " AND xapplication=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xapplication.getValue("")); \
} 


// 查询当前应用所有分类
list<FormDO> FormDAO::selectcategoryAndnumByApp(const char* xapplication)
{
	stringstream sql;
	sql << "SELECT xcategory,COUNT(*) AS xnum FROM pp_e_form WHERE `xapplication` = ? GROUP BY xcategory";
	FormCategoryMapper mapper;
	std::string std_str(xapplication);
	return sqlSession->executeQuery<FormDO, FormCategoryMapper>(sql.str(), mapper, "%s", std_str);
}

// 根据标识id查询表单详情
list<FormDO> FormDAO::selectInfoById(const char* xid)
{
	stringstream sql;
	sql << "SELECT xid,xname,xcategory,xalias,xdescription,xdata,xapplication,xupdateTime,xcreateTime,xlastUpdatePerson,xlastUpdateTime,xhasMobile,xmobileData,xproperties,xicon FROM pp_e_form WHERE `xid` = ?";
	FormInfoMapper mapper;
	std::string std_str(xid);
	return sqlSession->executeQuery<FormDO, FormInfoMapper>(sql.str(), mapper, "%s", std_str);
}

// 统计数据条数
uint64_t FormDAO::count(const FormListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pp_e_form";
	FORM_TREAM_PARSE(query, sql);
	return sqlSession->executeQueryNumerical(sql.str(), params);
}

// 分页查询数据
list<FormDO> FormDAO::selectFormWithPage(const FormListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT xid,xname,xcategory,xalias,xdescription,xapplication,xcreateTime,xupdateTime,xlastUpdatePerson,xlastUpdateTime,xhasMobile,xicon FROM pp_e_form";
	FORM_TREAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	FormListMapper mapper;
	return sqlSession->executeQuery<FormDO, FormListMapper>(sql.str(), mapper,params);
}

list<FormNameDO> FormDAO::selectNameById(const string& xid) {
	stringstream sql;
	sql << "SELECT xname FROM pp_e_form WHERE `xid` = ?";
	FormNameMapper mapper;
	return sqlSession->executeQuery<FormNameDO, FormNameMapper>(sql.str(), mapper, "%s", xid);
}
