#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: siri
 @Date: 2024/10/20 19:09:53

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
#ifndef _UPLOADATTACHMENT_DTO_
#define _UPLOADATTACHMENT_DTO_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ�������ϴ����鸽����¼�����ݴ���ģ��
 */
class UploadAttachmentDTO : public oatpp::DTO
{
	DTO_INIT(UploadAttachmentDTO, DTO);
	// �ļ����
	API_DTO_FIELD_DEFAULT(String, xid, ZH_WORDS_GETTER("meeting.file.field.xid"));
	// �ļ�����ʱ��
	API_DTO_FIELD_DEFAULT(String, xcreateTime, ZH_WORDS_GETTER("meeting.file.field.xcreateTime"));
	// ���к�
	API_DTO_FIELD_DEFAULT(String, xsequence, ZH_WORDS_GETTER("meeting.file.field.xsequence"));
	// �ļ�����ʱ��
	API_DTO_FIELD_DEFAULT(String, xupdateTime, ZH_WORDS_GETTER("meeting.file.field.xupdateTime"));
	// �ļ��������
	API_DTO_FIELD_DEFAULT(Int32, xdeepPath, ZH_WORDS_GETTER("meeting.file.field.xdeepPath"));
	// �ļ���չ������pdf
	API_DTO_FIELD_DEFAULT(String, xextension, ZH_WORDS_GETTER("meeting.file.field.xextension"));
	// ���ִ�и����ļ����û�
	API_DTO_FIELD_DEFAULT(String, xlastUpdatePerson, ZH_WORDS_GETTER("meeting.file.field.xlastUpdatePerson"));
	// �ļ��������ʱ��
	API_DTO_FIELD_DEFAULT(String, xlastUpdateTime, ZH_WORDS_GETTER("meeting.file.field.xlastUpdateTime"));
	// �ļ���С
	API_DTO_FIELD_DEFAULT(Int64, xlength, ZH_WORDS_GETTER("meeting.file.field.xlength"));
	// ����ID
	API_DTO_FIELD_DEFAULT(String, xmeeting, ZH_WORDS_GETTER("meeting.file.field.xmeeting"));
	// �ļ�����
	API_DTO_FIELD_DEFAULT(String, xname, ZH_WORDS_GETTER("meeting.file.field.xname"));
	// �ļ��洢·�� ��FastDFS
	API_DTO_FIELD_DEFAULT(String, xstorage, ZH_WORDS_GETTER("meeting.file.field.xstorage"));
	// �Ƿ��ǻ����ܽ�����ժҪ
	API_DTO_FIELD_DEFAULT(Boolean, xsummary, ZH_WORDS_GETTER("meeting.file.field.isSummary"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UPLOADATTACHMENT_DTO_