#include "stdafx.h"
#include "deletecontentsDAO.h"
#include <sstream>
//删除目录
int contentsDAO::deleteById(string xid)
{

	string sql1 = "DELETE FROM `file_folder` WHERE `xid`= ? ";
	string sql2 = "DELETE FROM `file_attachment` WHERE `xfolder`= ?";
	//string sql = sql1.str();
	//cout << sql << endl;
	int row = sqlSession->executeUpdate(sql1, "%s", xid);
	//cout << row << endl;
	if (!row) return row;
	else
	{
		row = sqlSession->executeUpdate(sql2, "%s", xid);
	}
	cout << row << endl;
	return row;
}
//重命名目录或文件
int contentsDAO::update(const file_folderDO& uObj)
{
	string sql = "UPDATE `file_folder` SET `xname`=?,`xupdateTime`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getXname(), uObj.getXupdateTime(), uObj.getXid());

}