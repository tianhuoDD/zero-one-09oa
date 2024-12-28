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
class FileInfoDTO : public oatpp::DTO
{
	DTO_INIT(FileInfoDTO, DTO);
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
	//// Ŀ¼�ַ���ʽ
	// API_DTO_FIELD(Int64, xdistributeFactor, ZH_WORDS_GETTER("Myfile.folder.xdistributeFactor"), false,0X001);
	//// �ļ���Ŀ¼id
	//API_DTO_FIELD(String, xfolder, ZH_WORDS_GETTER("Myfile.folder.xfoler"), false, "000");
	// �ļ�������
	API_DTO_FIELD(String, xperson, ZH_WORDS_GETTER("Myfile.file.person"), true, "0");
	// �ļ�����
	API_DTO_FIELD(String, xstorage, ZH_WORDS_GETTER("Myfile.file.storage"), true, "251");


};

/**
 * ��ҳ�������
 */
class FileInfoPageDTO : public PageDTO<FileInfoDTO::Wrapper>
{
	DTO_INIT(FileInfoPageDTO, PageDTO<FileInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !FileInfoDTO