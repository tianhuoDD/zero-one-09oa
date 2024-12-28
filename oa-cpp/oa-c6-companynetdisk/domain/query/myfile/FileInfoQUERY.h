#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _FileInfoQUERY_H_
#define _FileInfoQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询对象
 */
class FileInfoQUERY : public PageQuery
{
	DTO_INIT(FileInfoQUERY, PageQuery);
	// 目录id
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("Myfile.folder.xid"), false, "{xid}");
	//// 目录名
	//API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("Myfile.filed.xname"));
	//// 目录序列号
	//API_DTO_FIELD_DEFAULT(String, xsequence, ZH_WORDS_GETTER("Myfile.filed.xsequence"));
	//// 目录大小
	//API_DTO_FIELD_DEFAULT(UInt64, xlength, ZH_WORDS_GETTER("Myfile.filed.xlength"));
	//// 目录类型
	//API_DTO_FIELD_DEFAULT(String, xtype, ZH_WORDS_GETTER("Myfile.filed.xtype"));
	//// 目录创建时间
	//API_DTO_FIELD_DEFAULT(String, xcreateTime, ZH_WORDS_GETTER("Myfile.filed.xcreateTime"));
	//// 目录更新时间
	//API_DTO_FIELD_DEFAULT(String, xupdateTime, ZH_WORDS_GETTER("Myfile.filed.xupdateTime"));
	//// 目录所有者
	//API_DTO_FIELD_DEFAULT(String, xperson, ZH_WORDS_GETTER("Myfile.filed.xperson"));
	//// 目录状态
	//API_DTO_FIELD_DEFAULT(String, xstatus, ZH_WORDS_GETTER("Myfile.filed.xstatus"));
	//// 目录下文件id
	//API_DTO_FIELD_DEFAULT(String, xfileid, ZH_WORDS_GETTER("Myfile.filed.xfileid"));
	//// 目录下文件类型
	//API_DTO_FIELD_DEFAULT(String, xfileType, ZH_WORDS_GETTER("Myfile.filed.xfileType"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_FileInfoQUEY_H_