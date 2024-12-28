#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/11/1 16:39:23

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
#ifndef _LIST_PERSONAL_IDENTITYDAO_
#define _LIST_PERSONAL_IDENTITYDAO_

#include<BaseDAO.h>

#include "../../domain/do/list/org_identityDO.h"
#include "../../domain/query/list/list_personal_identityQuery.h"

class list_personal_identityDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const list_personal_identityQuery::Wrapper& query);
	// 分页查询数据
	list<org_identityDO> selectWithPage(const list_personal_identityQuery::Wrapper& query);
	// 通过姓名查询数据
	list<org_identityDO> selectByName(const string& name);
};




#endif // !_LIST_PERSONAL_IDENTITYDAO_
