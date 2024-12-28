#include "stdafx.h"
#include "MyFileDAO.h"
#include "MyFileMapper.h"
#include <sstream>


//定义条件解析宏，减少重复代码
//#define MYFILE_TERAM_PARSE(query, sql) \
//SqlParams params; \
//sql<<" WHERE 1=1"; \
//if (query->xid) { \
//	sql << " AND `xid`=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->xid.getValue("")); \
//} \
//if (query->xname) { \
//	sql << " AND xname=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->xname.getValue("")); \
//} \
//if (query->xsequence) { \
//	sql << " AND xsequence=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->xsequence.getValue("")); \
//} \
//if (query->xcreateTime) { \
//	sql << " AND xcreateTime=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->xcreateTime.getValue("")); \
//} \
//if (query->xupdateTime) { \
//	sql << " AND xupdateTime=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->xupdateTime.getValue("")); \
//}\
//if (query->xperson) { \
//	sql << " AND xperson=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->xperson.getValue("")); \
//} \


int MyFileDAO::deleteById(const string& xid)
{
	string sql = "DELETE FROM `file_attachment` WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%s", xid);
}

uint64_t MyFileDAO::insert(const MyFileDO& iObj)
{
	string sql = "INSERT INTO `file_attachment`  (`xid`,`xcreateTime`, `xupdateTime`, `xextension`, `xfolder`,\
 	`xlastUpdatePerson`, `xlastUpdateTime`, `xlength`, `xname`, `xperson`,`xstorage`) \
    VALUES (?, NOW(), NOW(), ?, ?,?, NOW(), ?, ?,?,?)";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%i%s%s%s", iObj.getXid(), iObj.getXextension(), iObj.getXfolder(), iObj.getXlastUpdatePerson(), iObj.getXlength(), \
		iObj.getXname(), iObj.getXperson(), iObj.getXstorage());
}
uint64_t MyFileDAO::update(const MyFileDO& uObj)
{
	string sql = "UPDATE `file_attachment` SET `xcreateTime`=NOW(),`xupdateTime`=NOW(),`xextension`=?,`xlastUpdatePerson`=?,\
    `xlastUpdateTime`=NOW(),`xlength`=?,`xname`=?, `xperson`=?,`xstorage`=?  WHERE `xid`=?";

	return sqlSession->executeUpdate(sql, "%s%s%i%s%s%s%s", uObj.getXextension(), uObj.getXlastUpdatePerson(), uObj.getXlength(), \
		uObj.getXname(), uObj.getXperson(), uObj.getXstorage(), uObj.getXid());
}

uint64_t MyFileDAO::insertlog(const FileLogDO& iObj)
{
	//cout << iObj.getXid() <<" "<< iObj.getXFromPerson() << " " << iObj.getXToPerson() << " " << iObj.getFile_attachment_id() << endl;
	string sql = "INSERT INTO `file_operation_log`  (`xOperationType`, `xOperationTime`,`xid`,`xFromPerson`,`xToPerson`,`file_attachment_id`) VALUES (4,NOW(),?,?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s", iObj.getXid(), iObj.getXFromPerson(), iObj.getXToPerson(), iObj.getFile_attachment_id());
}

uint64_t MyFileDAO::insertDeletelog(const FileLogDO& iObj)
{
	string sql = "INSERT INTO `file_operation_log`  (`xOperationType`, `xOperationTime`,`xid`,`xFromPerson`,`xToPerson`,`file_attachment_id`) VALUES (3,NOW(),?,?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s", iObj.getXid(), iObj.getXFromPerson(), iObj.getXToPerson(), iObj.getFile_attachment_id());
}


std::list<MyFileDO> MyFileDAO::selectStoragebyxid(const string& xid)
{
	std::cout << "The value of xid is: " << xid << std::endl;

	stringstream sql;
	sql << "SELECT xstorage FROM file_attachment WHERE xid= " << xid;
	MyFileMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MyFileDO, MyFileMapper>(sqlStr, mapper);
}

std::list<MyFileDO> MyFileDAO::selectNamebyxid(const string& xid)
{
	stringstream sql;
	sql << "SELECT xname FROM file_attachment WHERE xid= " << xid;
	MyFileMapperN mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MyFileDO, MyFileMapperN>(sqlStr, mapper);
}

//INSERT INTO `file_attachment` (`xid`,`xcreateTime`, `xupdateTime`, `xextension`, `xfolder`,\
//	`xlastUpdatePerson`, `xlastUpdateTime`, `xlength`, `xname`, `xperson`) \
//	VALUES("1223223", NOW(), NOW(), CONCAT(DATE_FORMAT(NOW(), '%Y%m%d%H%i%s'), \
//		"2AACC3"), "a", NOW(), NOW(), 12, "a", "a")
//printf("%s\n", fn.c_str());
//printf("%s\n", dto->xname.getValue("").c_str());

//Yu
uint64_t MyFileDAO::count(const FileInfoQUERY::Wrapper& query, const string& xid)
{
	stringstream sql;
	sql << "SELECT "
		<< "(SELECT COUNT(*) FROM file_attachment WHERE xfolder = ?) + "
		<< "(SELECT COUNT(*) FROM file_folder WHERE xsuperior = ?) ";
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sql.str(), "%s%s", xid, xid);
}

list<folder_queryDO> MyFileDAO::selectWithPage(const FileInfoQUERY::Wrapper& query, const string& xid)
{
	stringstream sql;
	sql << "(SELECT fa.xid AS id, fa.xcreateTime AS createTime, fa.xsequence AS sequence, "
		<< "fa.xupdateTime AS updateTime, fa.xdeepPath AS deepPath, fa.xextension AS extension, "
		<< "fa.xlastUpdatePerson AS lastUpdatePerson, fa.xlastUpdateTime AS lastUpdateTime, "
		<< "fa.xlength AS length, fa.xname AS name, fa.xperson AS person, fa.xstorage AS storage, "
		<< "NULL AS folder_Xid, NULL AS folder_XcreateTime, NULL AS folder_Xsequence, "
		<< "NULL AS folder_XupdateTime, NULL AS folder_Xname, NULL AS folder_Xperson "
		<< "FROM file_attachment fa "
		<< "WHERE fa.xfolder = ?) "
		<< "UNION ALL "
		<< "(SELECT NULL AS id, NULL AS createTime, NULL AS sequence, "
		<< "NULL AS updateTime, NULL AS deepPath, NULL AS extension, "
		<< "NULL AS lastUpdatePerson, NULL AS lastUpdateTime, NULL AS length, NULL AS name, "
		<< "NULL AS person, NULL AS storage, "
		<< "ff.xid AS folder_Xid, ff.xcreateTime AS folder_XcreateTime, ff.xsequence AS folder_Xsequence, "
		<< "ff.xupdateTime AS folder_XupdateTime, ff.xname AS folder_Xname, ff.xperson AS folder_Xperson "
		<< "FROM file_folder ff "
		<< "WHERE ff.xsuperior = ?) "
		<< "LIMIT " << ((query->pageIndex - 1) * query->pageSize) << ", " << query->pageSize;
	MyfileMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<folder_queryDO, MyfileMapper>(sqlStr, mapper, "%s%s", xid, xid);
}


uint64_t MyFileDAO::count_null(const FileInfoQUERY::Wrapper& query, const string& xid)
{
	stringstream sql;
	sql << "SELECT "
		<< "(SELECT COUNT(*) FROM file_attachment WHERE xfolder = '') + "
		<< "(SELECT COUNT(*) FROM file_folder WHERE xsuperior = '') ";
	string sqlStr = sql.str();
	cout << sqlStr << endl;
	return sqlSession->executeQueryNumerical(sqlStr);
}

list<folder_queryDO> MyFileDAO::selectWithPage_null(const FileInfoQUERY::Wrapper& query, const string& xid)
{
	stringstream sql;
	sql << "(SELECT fa.xid AS id, fa.xcreateTime AS createTime, fa.xsequence AS sequence, "
		<< "fa.xupdateTime AS updateTime, fa.xdeepPath AS deepPath, fa.xextension AS extension, "
		<< "fa.xlastUpdatePerson AS lastUpdatePerson, fa.xlastUpdateTime AS lastUpdateTime, "
		<< "fa.xlength AS length, fa.xname AS name, fa.xperson AS person, fa.xstorage AS storage, "
		<< "NULL AS folder_Xid, NULL AS folder_XcreateTime, NULL AS folder_Xsequence, "
		<< "NULL AS folder_XupdateTime, NULL AS folder_Xname, NULL AS folder_Xperson "
		<< "FROM file_attachment fa "
		<< "WHERE fa.xfolder = '') "
		<< "UNION ALL "
		<< "(SELECT NULL AS id, NULL AS createTime, NULL AS sequence, "
		<< "NULL AS updateTime, NULL AS deepPath, NULL AS extension, "
		<< "NULL AS lastUpdatePerson, NULL AS lastUpdateTime, NULL AS length, NULL AS name, "
		<< "NULL AS person, NULL AS storage, "
		<< "ff.xid AS folder_Xid, ff.xcreateTime AS folder_XcreateTime, ff.xsequence AS folder_Xsequence, "
		<< "ff.xupdateTime AS folder_XupdateTime, ff.xname AS folder_Xname, ff.xperson AS folder_Xperson "
		<< "FROM file_folder ff "
		<< "WHERE ff.xsuperior = '') "
		<< "LIMIT " << ((query->pageIndex - 1) * query->pageSize) << ", " << query->pageSize;
	MyfileMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<folder_queryDO, MyfileMapper>(sqlStr, mapper);
}


uint64_t MyFileDAO::insert(const file_folderDO& iObj)
{
	string sql = "INSERT INTO `file_folder`  (`xid`, `xsuperior`, `xname`,`xperson`,`xcreateTime`,`xupdateTime`,`xsequence`) VALUES (?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s", iObj.getXid(), iObj.getXsuperior(), iObj.getXname(), iObj.getXperson(),iObj.getXcreateTime(),iObj.getXupdateTime(),iObj.getXsequence());
}