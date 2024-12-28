#pragma once

#ifndef _MYFILE_DAO_
#define _MYFILE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/myfile/MyFileDO.h"
#include "../../domain/do/file/file_operation_logDO.h"

#include "../../domain/do/file/file_attachment2DO.h"
#include "../../domain/do/file/file_attachmentDO.h"
#include "../../domain/do/folder/file_folderDO.h"
#include "../../domain/do/folder/folder_queryDO.h"
#include "../../domain/query/myfile/FileInfoQUERY.h"

/**
 * 示例表数据库操作实现
 */
class MyFileDAO : public BaseDAO
{
public:

	// 通过姓名查询数据
	list<MyFileDO> selectStoragebyxid(const string& xid);
	list<MyFileDO> selectNamebyxid(const string& xid);
	uint64_t insert(const MyFileDO& iObj);
	uint64_t update(const MyFileDO& uObj);
	uint64_t insertlog(const FileLogDO& iObj);
	uint64_t insertDeletelog(const FileLogDO& iObj);
	// 通过ID删除数据
	int deleteById(const string& id);

	//Yu
	// 统计数据条数
	uint64_t count(const FileInfoQUERY::Wrapper& query, const string& xid);
	// 分页查询数据
	list<folder_queryDO> selectWithPage(const FileInfoQUERY::Wrapper& query, const string& xid);
	// 统计数据条数
	uint64_t count_null(const FileInfoQUERY::Wrapper& query, const string& xid);
	// 分页查询数据
	list<folder_queryDO> selectWithPage_null(const FileInfoQUERY::Wrapper& query, const string& xid);
	// 插入数据
	uint64_t insert(const file_folderDO& iObj);
};
#endif // !_MYFILE_DAO_
