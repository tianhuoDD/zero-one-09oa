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
 * 定义一个新增上传会议附件记录的数据传输模型
 */
class UploadAttachmentDTO : public oatpp::DTO
{
	DTO_INIT(UploadAttachmentDTO, DTO);
	// 做此上传操作的用户ID
	API_DTO_FIELD(String, xlastUpdatePerson, ZH_WORDS_GETTER("user.field.id"), true, {"123"});
	// 会议ID
	API_DTO_FIELD(String, xmeeting, ZH_WORDS_GETTER("meeting.file.field.id"), true, {"123"});
	// 文件名称
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("meeting.file.field.filename"), true, {"1.txt"});
	// 是否是会议总结或相关摘要
	API_DTO_FIELD(Boolean, xsummary, ZH_WORDS_GETTER("meeting.file.field.isSummary"), true, {false});
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UPLOADATTACHMENT_H_