#pragma once
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
#ifndef _DATAOPRATOR_DAO_
#define _DATAOPRATOR_DAO_
#include "BaseDAO.h"
#include "../../oa-c8-proappmanager/domain/do/data/DataOpDO.h"
#include "../oa-c8-proappmanager/dao/data/DataOpratorMapper.h"
#include "../oa-c8-proappmanager/domain/query/data/DataOpQuery.h"

class DataOpDAO : public BaseDAO
{
public:

	//查询数据条数
	uint64_t count(const DataOpQuery::Wrapper& query);
	//新增数据
	uint64_t insert(const DataOpDO& iObj1);
	// 修改数据
	bool update(const DataOpDO& uObj);
	// 通过ID删除数据
	bool deleteById(const string &id);
};
#endif // !_DATAOPRATOR_DAO_
