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
 * ʾ�������ݿ����ʵ��
 */
class MyFileDAO : public BaseDAO
{
public:

	// ͨ��������ѯ����
	list<MyFileDO> selectStoragebyxid(const string& xid);
	list<MyFileDO> selectNamebyxid(const string& xid);
	uint64_t insert(const MyFileDO& iObj);
	uint64_t update(const MyFileDO& uObj);
	uint64_t insertlog(const FileLogDO& iObj);
	uint64_t insertDeletelog(const FileLogDO& iObj);
	// ͨ��IDɾ������
	int deleteById(const string& id);

	//Yu
	// ͳ����������
	uint64_t count(const FileInfoQUERY::Wrapper& query, const string& xid);
	// ��ҳ��ѯ����
	list<folder_queryDO> selectWithPage(const FileInfoQUERY::Wrapper& query, const string& xid);
	// ͳ����������
	uint64_t count_null(const FileInfoQUERY::Wrapper& query, const string& xid);
	// ��ҳ��ѯ����
	list<folder_queryDO> selectWithPage_null(const FileInfoQUERY::Wrapper& query, const string& xid);
	// ��������
	uint64_t insert(const file_folderDO& iObj);
};
#endif // !_MYFILE_DAO_
