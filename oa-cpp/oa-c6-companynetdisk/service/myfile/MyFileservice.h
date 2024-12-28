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
 * 示例服务实现，演示基础的示例服务实现
 */
class MyFileservice
{
public:
	string QuaryStoragebyId(string xid);
	string QuaryNamebyId(string xid);
	uint64_t saveData(const MyfileDTO::Wrapper& dto);
	uint64_t ModifyData(const MyfileDTO::Wrapper& dto);
	//插入日志数据
	uint64_t insertLogData(const FileLogDTO::Wrapper& dto);
	uint64_t insertLogDeleteData(const FileLogDTO::Wrapper& ddto);
	// 通过ID删除数据
	bool removeData(string id);
	//修改数据 
	bool updateData(const MyfileDTO::Wrapper& dto);

	// 分页查询所有数据
	FolderQueryPageDTO::Wrapper listAll(const FileInfoQUERY::Wrapper& query, const string& id);
	// 保存数据
	uint64_t saveData(const FolderAddDTO::Wrapper& dto);

};

#endif // !_SAMPLE_SERVICE_

