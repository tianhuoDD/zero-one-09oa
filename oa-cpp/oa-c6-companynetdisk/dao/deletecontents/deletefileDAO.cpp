#include "stdafx.h"
#include "deletefileDAO.h"
#include <sstream>

//������Ŀ¼���ļ�
int deletefileDAO::update(const file_deleteDO& uObj)
{
	string sql = "UPDATE `file_attachment` SET `xname`=?,`xupdateTime`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getXname(), uObj.getXupdateTime(), uObj.getXid());

}