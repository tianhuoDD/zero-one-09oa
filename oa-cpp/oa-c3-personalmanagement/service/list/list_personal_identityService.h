#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/31 19:43:24

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
#ifndef _LIST_PERSONAL_IDENTITYSERVICE_
#define _LIST_PERSONAL_IDENTITYSERVICE_

#include<list>

#include "../../domain/dto/list/list_personal_identityDTO.h"

#include "../../domain/query/list/list_personal_identityQuery.h"

class list_personal_identityService
{
public:
	// 分页查询所有数据
	listPageDTO::Wrapper listAll(const list_personal_identityQuery::Wrapper& query);
};

#endif // !_LIST_PERSONAL_IDENTITYSERVICE_
