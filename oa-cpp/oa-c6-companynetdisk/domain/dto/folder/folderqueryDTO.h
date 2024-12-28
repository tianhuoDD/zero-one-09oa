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
#ifndef _FolderQueryDTO_H_
#define _FolderQueryDTO_H_
#include "../../GlobalInclude.h"
#include "../myfile/FileInfoDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
 //class FileInfoDTO : public oatpp::DTO
 //{
 //	DTO_INIT(FileInfoDTO, DTO);
 //	
 //};

 /**
  * ��ҳ�������
  */
class FolderQueryDTO : public FileInfoDTO
{
	DTO_INIT(FolderQueryDTO, DTO);
	// Ŀ¼id,Ŀ¼Ψһ��ʶ
	API_DTO_FIELD(String, folder_xid, ZH_WORDS_GETTER("Myfile.folder.xid"), true, "0x0000000");
	// Ŀ¼����ʱ��
	API_DTO_FIELD(String, folder_xcreateTime, ZH_WORDS_GETTER("Myfile.folder.xcreateTime"), true, "0");
	// Ŀ¼���к�
	API_DTO_FIELD(String, folder_xsequence, ZH_WORDS_GETTER("Myfile.folder.xsequence"), true, "000000");
	// Ŀ¼����ʱ��
	API_DTO_FIELD(String, folder_xupdateTime, ZH_WORDS_GETTER("Myfile.folder.xupdateTime"), true, "0");
	// Ŀ¼��
	API_DTO_FIELD(String, folder_xname, ZH_WORDS_GETTER("Myfile.folder.xname"), true, "_");
	// Ŀ¼������
	API_DTO_FIELD(String, folder_xperson, ZH_WORDS_GETTER("Myfile.folder.xperson"), true, "0");
	// �ļ�id,Ŀ¼Ψһ��ʶ
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("Myfile.file.id"), true, "0x0000000");
	// �ļ�����ʱ��
	API_DTO_FIELD(String, xcreateTime, ZH_WORDS_GETTER("Myfile.filed.xcreateTime"), true, "0");
	// �ļ����к�
	API_DTO_FIELD(String, xsequence, ZH_WORDS_GETTER("Myfile.filed.xsequence"), true, "000000");
	// �ļ�����ʱ��
	API_DTO_FIELD(String, xupdateTime, ZH_WORDS_GETTER("Myfile.filed.xupdateTime"), true, "0");
	// �ļ����
	API_DTO_FIELD(Int8, xdeepPath, ZH_WORDS_GETTER("Myfile.filed.xdeepPath"), true, 01);
	// �ļ���չ��
	API_DTO_FIELD(String, xextension, ZH_WORDS_GETTER("Myfile.filed.xextension"), true, "png");
	// �ļ��ϴ��޸���
	API_DTO_FIELD(String, xLastUpdatePerson, ZH_WORDS_GETTER("Myfile.filed.xLastUpdatePerson"), true, "000");
	// �ļ��ϴ��޸�ʱ��
	API_DTO_FIELD(String, xLastUpdateTime, ZH_WORDS_GETTER("Myfile.filed.xLastUpdateTime"), true, "000");
	// �ļ���С
	API_DTO_FIELD(UInt64, xlength, ZH_WORDS_GETTER("Myfile.filed.xlength"), true, 123);
	// �ļ���
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("Myfile.file.name"), true, "_");
	// �ļ�������
	API_DTO_FIELD(String, xperson, ZH_WORDS_GETTER("Myfile.file.person"), true, "0");
	// �ļ�����
	API_DTO_FIELD(String, xstorage, ZH_WORDS_GETTER("Myfile.file.storage"), true, "251");
	// Ŀ¼��Ŀ¼ID
	//API_DTO_FIELD(String, folder_xsuperior, ZH_WORDS_GETTER("Myfile.folder.xsuperior"), true, "251");


};
/**
 * ��ҳ�������
 */
class FolderQueryPageDTO : public PageDTO<FolderQueryDTO::Wrapper>
{
	DTO_INIT(FolderQueryPageDTO, PageDTO<FolderQueryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !FolderQueryDTO