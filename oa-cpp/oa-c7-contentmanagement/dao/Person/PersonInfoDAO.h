
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _PERSONINFO_DAO_
#define _PERSONINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Person/PersonInfoDO.h"
#include "../../domain/query/PersonQuery.h"
//#include "../domain/do/sample/SampleDO.h"
//#include "../domain/query/sample/SampleQuery.h" //因为直接用string查询，所以我认为这里不用再包装

/**
 * 示例表数据库操作实现
 */
class PersonInfoDAO : public BaseDAO
{
public:
	// 通过姓名查询数据
	list<PersonInfoDO> selectWithPage(const PersonQuery::Wrapper& query);

	uint64_t count(const PersonQuery::Wrapper& query);
};
#endif // !_PERSONINFO_DAO_
