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
#ifndef _FolderAddDTO_H_
#define _FolderAddDTO_H_
#include "../../GlobalInclude.h"
#include "../../dto/folder/folderinfoDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
 //class FileInfoDTO : public oatpp::DTO
 //{
 //	DTO_INIT(FileInfoDTO, DTO);
 //	
 //};

class FolderAddDTO : public FolderInfoDTO
{
	DTO_INIT(FolderAddDTO, DTO);
	// 目录名
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("Myfile.folder.xname"), true, "_");
	// 文件父目录id
	API_DTO_FIELD(String, xsuperior, ZH_WORDS_GETTER("Myfile.folder.xsuperior"), false, "000");
	// 目录持有者
	API_DTO_FIELD(String, xperson, ZH_WORDS_GETTER("Myfile.folder.xperson"), true, "0");

};


#include OATPP_CODEGEN_END(DTO)
#endif // !FolderAddDTODTO