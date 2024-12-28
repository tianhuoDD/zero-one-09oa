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
 * ��ҳ��ѯ����
 */
class FileInfoQUERY : public PageQuery
{
	DTO_INIT(FileInfoQUERY, PageQuery);
	// Ŀ¼id
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("Myfile.folder.xid"), false, "{xid}");
	//// Ŀ¼��
	//API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("Myfile.filed.xname"));
	//// Ŀ¼���к�
	//API_DTO_FIELD_DEFAULT(String, xsequence, ZH_WORDS_GETTER("Myfile.filed.xsequence"));
	//// Ŀ¼��С
	//API_DTO_FIELD_DEFAULT(UInt64, xlength, ZH_WORDS_GETTER("Myfile.filed.xlength"));
	//// Ŀ¼����
	//API_DTO_FIELD_DEFAULT(String, xtype, ZH_WORDS_GETTER("Myfile.filed.xtype"));
	//// Ŀ¼����ʱ��
	//API_DTO_FIELD_DEFAULT(String, xcreateTime, ZH_WORDS_GETTER("Myfile.filed.xcreateTime"));
	//// Ŀ¼����ʱ��
	//API_DTO_FIELD_DEFAULT(String, xupdateTime, ZH_WORDS_GETTER("Myfile.filed.xupdateTime"));
	//// Ŀ¼������
	//API_DTO_FIELD_DEFAULT(String, xperson, ZH_WORDS_GETTER("Myfile.filed.xperson"));
	//// Ŀ¼״̬
	//API_DTO_FIELD_DEFAULT(String, xstatus, ZH_WORDS_GETTER("Myfile.filed.xstatus"));
	//// Ŀ¼���ļ�id
	//API_DTO_FIELD_DEFAULT(String, xfileid, ZH_WORDS_GETTER("Myfile.filed.xfileid"));
	//// Ŀ¼���ļ�����
	//API_DTO_FIELD_DEFAULT(String, xfileType, ZH_WORDS_GETTER("Myfile.filed.xfileType"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_FileInfoQUEY_H_