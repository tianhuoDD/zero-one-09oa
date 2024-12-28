#include "stdafx.h"
#include "PutDAO.h"
#include"PutMapper.h"
#include <sstream>


int PutDAO::update(const PutDO& uObj)
{
	string sql = "UPDATE `cms_form` SET `xappicon`=?, `xallPeopleViem`=?, `xallPeoplePublish`=?, `xcreatorPerson`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s", uObj.getXappicon(), uObj.getXallPeopleViem(), uObj.getXallPeoplePublish(), uObj.getXcreatorPerson());
}


