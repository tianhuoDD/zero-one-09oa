#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: dingfengchuan
 @Date: 2024年11月1日

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
#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/org_personDo/org_personDO.h"

/**
 * 示例表字段匹配映射
 */
class PersonlistMapper : public Mapper<org_personDO>
{
public:
	org_personDO mapper(ResultSet* resultSet) const override
	{
		org_personDO data;
		data.setXname(resultSet->getString(1));
		data.setXmobile(resultSet->getString(2));
		data.setXicon(resultSet->getString(3));
		data.setXid(resultSet->getString(4));
		data.setXunique(resultSet->getString(5));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_