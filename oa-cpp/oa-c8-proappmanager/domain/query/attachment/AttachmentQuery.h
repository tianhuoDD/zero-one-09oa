#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/19 22:50:17

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
#ifndef _ATTACHMENTQUERY_H_
#define _ATTACHMENTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AttachmentQuery : public PageQuery
{
	DTO_INIT(AttachmentQuery, PageQuery);
	// ID
	DTO_FIELD(String,xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("process.attachments.field.id");
	}
	// Ãû³Æ
	DTO_FIELD(String,xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("process.attachments.field.name");
	}
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_APPLICATIONQUERY_H_