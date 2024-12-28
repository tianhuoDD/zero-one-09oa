#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 11:01:02

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
#ifndef _GETSHAREFILES_QUERY_H_
#define _GETSHAREFILES_QUERY_H_

#include "../../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ�����û��б�����ݴ���ģ��
 */
class GetShareFilesQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(GetShareFilesQuery, PageQuery);
	// �û�Ψһid
	DTO_FIELD(String, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("Myfile.user.id");
	}
	//�û�������
	DTO_FIELD(String, xperson);
	DTO_FIELD_INFO(xperson) {
		info->description = ZH_WORDS_GETTER("Myfile.user.name");
	}
	//�ļ���
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("Myfile.file.name");
	}
	//�ļ���С
	DTO_FIELD(String, xlength);
	DTO_FIELD_INFO(xlength) {
		info->description = ZH_WORDS_GETTER("Myfile.file.size");
	}
	//�ļ�����ʱ��
	DTO_FIELD(String, xcreateTime);
	DTO_FIELD_INFO(xcreateTime) {
		info->description = ZH_WORDS_GETTER("getting.file.size");
	}
	//�ļ��޸�ʱ��
	DTO_FIELD(String, xUpdateTime);
	DTO_FIELD_INFO(xUpdateTime) {
		info->description = ZH_WORDS_GETTER("getting.file.size");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETSHAREFILES_QUERY_H_

