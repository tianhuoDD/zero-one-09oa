#include "stdafx.h"
#include "FormDAO.h"

int FormDAO::deleteById(string id)
{
	string sql = "DELETE FROM `cms_form` WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}

int FormDAO::update(const FormDO& uObj)
{	
	string sql = "UPDATE `cms_form` SET `xalias`=?, `xdescription`=?, `xeditor`=? ,`xname`=? ,`xproperties`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s", uObj.getAlias(), uObj.getDescription(), uObj.getEditor(), uObj.getFromName(), uObj.getProperties(),uObj.getId());
}
