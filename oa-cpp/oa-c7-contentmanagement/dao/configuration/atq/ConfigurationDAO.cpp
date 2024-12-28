#include "stdafx.h"
#include "ConfigurationDAO.h"
#include "ConfigurationMapper.h"
#include <sstream>

list<ConfigurationDO> ConfigurationDAO::selectById(const string& id)
{
	string sql = "SELECT xappId, xid, xalias,xname,xdata,xsequence,xdescription,xeditor,xproperties FROM cms_form WHERE `xid` LIKE CONCAT('%',?,'%')";
	ConfigurationMapper mapper;
	return sqlSession->executeQuery<ConfigurationDO, ConfigurationMapper>(sql, mapper, "%s", id);
}

int ConfigurationDAO::insert(const ConfigurationDO& iObj)
{
	string sql = "INSERT INTO `cms_form` (`xappId`, `xid`, `xalias`,`xname`,`xdata`,`xsequence`,`xdescription`,`xeditor`,`xproperties`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s",iObj.getXcreatorUnitName(), iObj.getXappId(), iObj.getXalias(), iObj.getXdocumentType(), iObj.getXsendNotify(), iObj.getProcess(), iObj.getRange(), iObj.getXcreatorPerson(), iObj.getXmanagePerson());
}

int ConfigurationDAO::update(const ConfigurationDO& uObj)
{
    string sql = "UPDATE `cms_form` SET `xappId`=?, `xalias`=?, `xname`=?, `xdata`=?, `xsequence`=?, `xdescription`=?, `xeditor`=?, `xproperties`=? WHERE `xid`=?";
    return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s", uObj.getXcreatorUnitName(), uObj.getXalias(), uObj.getXdocumentType(), uObj.getXsendNotify(), uObj.getProcess(), uObj.getRange(), uObj.getXcreatorPerson(), uObj.getXmanagePerson(), uObj.getXappId());
}

int ConfigurationDAO::deleteById(string id)
{
	string sql = "DELETE FROM `cms_form` WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}
