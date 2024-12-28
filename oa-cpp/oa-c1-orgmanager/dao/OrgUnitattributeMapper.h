#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: UptoFate
 @Date: 2024/10/22 14:21:55

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
#ifndef _ORGUNITATTRIBUTE_MAPPER_
#define _ORGUNITATTRIBUTE_MAPPER_

#include "Mapper.h"
#include "domain/do/OrgUnitattributeDO.h"

/**
 * 示例表字段匹配映射
 */
class OrgUnitattributeMapper : public Mapper<OrgUnitattributeDO>
{
public:
	OrgUnitattributeDO mapper(ResultSet* resultSet) const override
	{
		OrgUnitattributeDO data;
		data.setXid(resultSet->getString(1));
        data.setXid(resultSet->getString(1));
        data.setXcreateTime(resultSet->getString(2));
        data.setXsequence(resultSet->getString(3));
        data.setXupdateTime(resultSet->getString(4));
        data.setXdistributeFactor(resultSet->getInt(5));
        data.setXdescription(resultSet->getString(6));
        data.setXdistinguishedName(resultSet->getString(7));
        data.setXname(resultSet->getString(8));
        data.setXorderNumber(resultSet->getInt(9));
        data.setXpinyin(resultSet->getString(10));
        data.setXpinyinInitial(resultSet->getString(11));
        data.setXunique(resultSet->getString(12));
        data.setXunit(resultSet->getString(13));
		return data;
	}
};

#endif // !_ORGUNITATTRIBUTE_MAPPER_