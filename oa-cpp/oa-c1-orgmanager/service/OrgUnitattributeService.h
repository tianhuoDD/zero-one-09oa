#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: UptoFate
 @Date: 2024/10/21 21:13:11

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
#ifndef _ORGUNITATTRIBUTE_SERVICE_
#define _ORGUNITATTRIBUTE_SERVICE_
#include <list>
#include "domain/vo/OrgUnitattributeVO.h"
#include "domain/query/OrgUnitattributeQuery.h"
#include "domain/dto/OrgUnitattributeDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class OrgUnitattributeService
{
public:
	// 分页查询所有数据
	OrgUnitattributePageDTO::Wrapper listAll(const OrgUnitattributeQuery::Wrapper& query);

	// 通过ID删除数据
	bool removeData(string id);
};

#endif // !_ORGUNITATTRIBUTE_SERVICE_

