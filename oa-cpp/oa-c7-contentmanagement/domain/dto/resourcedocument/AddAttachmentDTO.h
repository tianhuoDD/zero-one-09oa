#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: amie
 @Date: 2022/10/26 23:47:08

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
#ifndef _ADDATTACHMENTDTO_H_
#define _ADDATTACHMENTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个修改用户信息的数据传输模型
 */
class AddAttachmentDTO : public oatpp::DTO
{
	DTO_INIT(AddAttachmentDTO, DTO);
	API_DTO_FIELD(String, xId, ZH_WORDS_GETTER("resourcedocument.query.fields.xid"), true, "");
	API_DTO_FIELD(String, xAppId, ZH_WORDS_GETTER("resourcedocument.query.fields.xappid"), true, "");
	API_DTO_FIELD(String, xName, ZH_WORDS_GETTER("resourcedocument.query.fields.xname"), true, "");
	API_DTO_FIELD(String, xDescription, ZH_WORDS_GETTER("resourcedocument.query.fields.xdescription"), true, "");
	API_DTO_FIELD(String, xUpdateTime, ZH_WORDS_GETTER("resourcedocument.query.fields.xupdate_time"), true, "");
};

#include OATPP_CODEGEN_END(DTO)
#endif // _ADDATTACHMENTDTO_H_