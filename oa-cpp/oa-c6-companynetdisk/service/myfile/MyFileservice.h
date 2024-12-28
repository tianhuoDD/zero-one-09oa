#pragma once
#ifndef _MMYFILEEE_SERVICE_
#define _MMYFILEEE_SERVICE_
#include <list>
#include <algorithm>
#include "../../domain/vo/myfile/MyfileVO.h"
#include "../../domain/dto/myfile/MyfileDTO.h"
#include "../../domain/dto/myfile/FilelogDTO.h"
#include "../../domain/dto/myfile/FileInfoDTO.h"
#include "../../domain/vo/myfile/FileInfoVO.h"
#include "../../domain/query/myfile/FileInfoQUERY.h"
#include "../../domain/dto/folder/folderaddDTO.h"
#include "../../domain/do/folder/folder_queryDO.h"
#include "../lib-common/include/SimpleDateTimeFormat.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class MyFileservice
{
public:
	string QuaryStoragebyId(string xid);
	string QuaryNamebyId(string xid);
	uint64_t saveData(const MyfileDTO::Wrapper& dto);
	uint64_t ModifyData(const MyfileDTO::Wrapper& dto);
	//������־����
	uint64_t insertLogData(const FileLogDTO::Wrapper& dto);
	uint64_t insertLogDeleteData(const FileLogDTO::Wrapper& ddto);
	// ͨ��IDɾ������
	bool removeData(string id);
	//�޸����� 
	bool updateData(const MyfileDTO::Wrapper& dto);

	// ��ҳ��ѯ��������
	FolderQueryPageDTO::Wrapper listAll(const FileInfoQUERY::Wrapper& query, const string& id);
	// ��������
	uint64_t saveData(const FolderAddDTO::Wrapper& dto);

};

#endif // !_SAMPLE_SERVICE_

