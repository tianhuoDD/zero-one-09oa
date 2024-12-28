#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _FileInfoDTO_H_
#define _FileInfoDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
 //class FileInfoDTO : public oatpp::DTO
 //{
 //	DTO_INIT(FileInfoDTO, DTO);
 //	
 //};

 /**
  * 分页传输对象
  */
class FileInfoDTO : public oatpp::DTO
{
	DTO_INIT(FileInfoDTO, DTO);
	// 文件id,目录唯一标识
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("Myfile.file.id"), true, "0x0000000");
	// 文件创建时间
	API_DTO_FIELD(String, xcreateTime, ZH_WORDS_GETTER("Myfile.filed.xcreateTime"), true, "0");
	// 文件序列号
	API_DTO_FIELD(String, xsequence, ZH_WORDS_GETTER("Myfile.filed.xsequence"), true, "000000");
	// 文件更新时间
	API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("Myfile.filed.xupdateTime"), true, "0");
	// 文件深度
	API_DTO_FIELD(Int8, xdeepPath, ZH_WORDS_GETTER("Myfile.filed.xdeepPath"), true, 01);
	// 文件扩展名
	API_DTO_FIELD(String, xextension, ZH_WORDS_GETTER("Myfile.filed.xextension"), true, "png");
	// 文件上次修改者
	API_DTO_FIELD(String, xLastUpdatePerson, ZH_WORDS_GETTER("Myfile.filed.xLastUpdatePerson"), true, "000");
	// 文件上次修改时间
	API_DTO_FIELD(String, xLastUpdateTime, ZH_WORDS_GETTER("Myfile.filed.xLastUpdateTime"), true, "000");
	// 文件大小
	API_DTO_FIELD(UInt64, xlength, ZH_WORDS_GETTER("Myfile.filed.xlength"), true, 123);
	// 文件名
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("Myfile.file.name"), true, "_");
	//// 目录分发方式
	// API_DTO_FIELD(Int64, xdistributeFactor, ZH_WORDS_GETTER("Myfile.folder.xdistributeFactor"), false,0X001);
	//// 文件父目录id
	//API_DTO_FIELD(String, xfolder, ZH_WORDS_GETTER("Myfile.folder.xfoler"), false, "000");
	// 文件持有者
	API_DTO_FIELD(String, xperson, ZH_WORDS_GETTER("Myfile.file.person"), true, "0");
	// 文件容量
	API_DTO_FIELD(String, xstorage, ZH_WORDS_GETTER("Myfile.file.storage"), true, "251");


};

/**
 * 分页传输对象
 */
class FileInfoPageDTO : public PageDTO<FileInfoDTO::Wrapper>
{
	DTO_INIT(FileInfoPageDTO, PageDTO<FileInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !FileInfoDTO