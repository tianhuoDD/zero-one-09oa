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
#ifndef _DATAOPQUERY_H_
#define _DATAOPQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DataOpQuery : public PageQuery
{
	DTO_INIT(DataOpQuery, PageQuery);
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("dataconfiguration.datamessage.id"), true, ZH_WORDS_GETTER("dataconfiguration.datamessage.id"));
	// ˝æ›≈‰÷√¡–id
	API_DTO_FIELD(String, itemid, ZH_WORDS_GETTER("dataconfiguration.item.item-id"), true,"dataconfiguration.datamessage.itemid");
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_DATAOPQUERY_H_