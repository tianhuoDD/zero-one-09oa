#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: UptoFate
 @Date: 2024/10/22 14:23:49
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
#ifndef _ORGUNITATTRIBUTE_DAO_
#define _ORGUNITATTRIBUTE_DAO_
#include "BaseDAO.h"
#include "domain/do/OrgUnitattributeDO.h"
#include "domain/query/OrgUnitattributeQuery.h"

class OrgUnitattributeDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const OrgUnitattributeQuery::Wrapper& query);
	// 分页查询数据
	list<OrgUnitattributeDO> selectWithPage(const OrgUnitattributeQuery::Wrapper& query);
	//// 通过姓名查询数据
	//list<OrgUnitattributeDO> selectByName(const string& name);
	//// 插入数据
	//uint64_t insert(const OrgUnitattributeDO& iObj);
	//// 修改数据
	//int update(const OrgUnitattributeDO& uObj);
	// 通过ID删除数据
	int deleteById(string id);
};

#endif // !_ORGUNITATTRIBUTE_DAO_