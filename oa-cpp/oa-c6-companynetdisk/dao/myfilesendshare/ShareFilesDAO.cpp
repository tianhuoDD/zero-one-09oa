/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "ShareFilesDAO.h"
#include"ShareFilesMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
//SqlParams params;

uint64_t ShareFilesDAO::insert(const file_attachment_sharelistDO& iObj)
{
	string sql = "INSERT INTO `file_attachment_sharelist` (`ATTACHMENT_XID`, `xshareList`, `xorderColumn`) VALUES (?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%i", iObj.getattachment_xid(), iObj.getXshareList(), iObj.getXorderColumn());
}
uint64_t ShareFilesDAO::insertsharelog(const FileLogDO& iObj)
{
	string sql = "INSERT INTO `file_operation_log`  (`xOperationType`, `xOperationTime`,`xid`,`xFromPerson`,`xToPerson`,`file_attachment_id`) VALUES (2,NOW(),?,?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s", iObj.getXid(), iObj.getXFromPerson(), iObj.getXToPerson(), iObj.getFile_attachment_id());
}