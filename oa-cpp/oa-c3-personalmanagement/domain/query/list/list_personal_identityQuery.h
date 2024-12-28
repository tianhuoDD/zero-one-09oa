#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/24 00:16:35

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

#ifndef _LIST_PERSONAL_IDENTITYQUERY_
#define _LIST_PERSONAL_IDENTITYQUERY_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"



#include OATPP_CODEGEN_BEGIN(DTO)
class list_personal_identityQuery : public PageQuery
{
	DTO_INIT(list_personal_identityQuery, PageQuery);
	//唯一编码
	DTO_FIELD(String, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("sample.field.xid");
	}
	//身份名称
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("sample.field.xname");
	}
};


#include OATPP_CODEGEN_END(DTO)


#endif // !_LIST_PERSONAL_IDENTITYQUERY_
