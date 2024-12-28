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
#ifndef _ACCEPTFILELIST_QUERY_H_
#define _ACCEPTFILELIST_QUERY_H_

#include "../../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class AcceptFileListQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(AcceptFileListQuery, PageQuery);
	//�ļ���
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("accept.file.name");
	}
	// �ϴ��û�Ψһid
	DTO_FIELD(String, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("accept.file.upload");
	}
	//�û�������
	DTO_FIELD(String, xperson);
	DTO_FIELD_INFO(xperson) {
		info->description = ZH_WORDS_GETTER("accept.user.name");
	}
	//�ļ��ϴ�ʱ��
	DTO_FIELD(String, xcreateTime);
	DTO_FIELD_INFO(xcreateTime) {
		info->description = ZH_WORDS_GETTER("accept.file.unload");
	}
	//�ļ��޸�ʱ��
	DTO_FIELD(String, xlastupdateTime);
	DTO_FIELD_INFO(xlastupdateTime) {
		info->description = ZH_WORDS_GETTER("accept.file.changed");
	}

	//�ļ���С
	DTO_FIELD(Int64, xlength);
	DTO_FIELD_INFO(xlength) {
		info->description = ZH_WORDS_GETTER("accept.file.size");
	}
	////�ļ�����
	//DTO_FIELD(String, xlength);
	//DTO_FIELD_INFO(xlength) {
	//	info->description = ZH_WORDS_GETTER("accept.file.share");
	//}
	////�ļ�����
	//DTO_FIELD(String, xlength);
	//DTO_FIELD_INFO(xlength) {
	//	info->description = ZH_WORDS_GETTER("accept.file.send");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_