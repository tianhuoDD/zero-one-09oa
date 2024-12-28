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
#ifndef _UPLOADATTACHMENT_H_
#define _UPLOADATTACHMENT_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ�������ϴ����鸽����¼�����ݴ���ģ��
 */
class UploadAttachmentDTO : public oatpp::DTO
{
	DTO_INIT(UploadAttachmentDTO, DTO);
	// �����ϴ��������û�ID
	API_DTO_FIELD(String, xlastUpdatePerson, ZH_WORDS_GETTER("user.field.id"), true, {"123"});
	// ����ID
	API_DTO_FIELD(String, xmeeting, ZH_WORDS_GETTER("meeting.file.field.id"), true, {"123"});
	// �ļ�����
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("meeting.file.field.filename"), true, {"1.txt"});
	// �Ƿ��ǻ����ܽ�����ժҪ
	API_DTO_FIELD(Boolean, xsummary, ZH_WORDS_GETTER("meeting.file.field.isSummary"), true, {false});
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UPLOADATTACHMENT_H_