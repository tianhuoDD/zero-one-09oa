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
#ifndef _FolderInfodDTO_H_
#define _FolderInfoDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
 //class FileInfoDTO : public oatpp::DTO
 //{
 //	DTO_INIT(FileInfoDTO, DTO);
 //	
 //};

class FolderInfoDTO : public oatpp::DTO
{
	DTO_INIT(FolderInfoDTO, DTO);
	// Ŀ¼id
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("Myfile.folder.xid"), true, "_");
	// Ŀ¼��
	//API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("Myfile.folder.xname"), true, "_");
	// �ļ���Ŀ¼id
	//API_DTO_FIELD(String, xsuperior, ZH_WORDS_GETTER("Myfile.folder.xsuperior"), false, "000");
	// Ŀ¼������
	//API_DTO_FIELD(String, xperson, ZH_WORDS_GETTER("Myfile.folder.xperson"), true, "0");
	////Ŀ¼����ʱ��
	API_DTO_FIELD(String, xcreateTime, ZH_WORDS_GETTER("Myfile.folder.xcreateTime"), true, "0");
	////Ŀ¼����ʱ��
	API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("Myfile.folder.xupdateTime"), true, "0");
	//Ŀ¼���к�
	API_DTO_FIELD(String, xsequence, ZH_WORDS_GETTER("Myfile.folder.xsequence"), true, "0");

};


#include OATPP_CODEGEN_END(DTO)
#endif // !FolderInfoDTO