#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#include "../../domain/do/data-config/DictDO.h"
#include "../../domain/do/data-config/ItemDO.h"

/**
 * cms_appndict±Ì◊÷∂Œ∆•≈‰”≥…‰
 */
class DictMapper : public Mapper<DictDO>
{
public:
	DictDO mapper(ResultSet* resultSet) const override
	{
		DictDO data;
		data.setXid(resultSet->getString(1));
		data.setXcreateTime(resultSet->getString(2));
		data.setXsequence(resultSet->getString(3));
		data.setXupdateTime(resultSet->getString(4));
		data.setXdistributeFactor(resultSet->getInt(5));
		data.setXalias(resultSet->getString(6));
		data.setXappId(resultSet->getString(7));
		data.setXcreatorUid(resultSet->getString(8));
		data.setXdescription(resultSet->getString(9));
		data.setXname(resultSet->getString(10));
		return data;
	}
};

/**
 * cms_appdictitem±Ì◊÷∂Œ∆•≈‰”≥…‰
 */
class ItemMapper : public Mapper<ItemDO>
{
public:
	ItemDO mapper(ResultSet* resultSet) const override
	{
		ItemDO data;
		data.setXid(resultSet->getString(1));
		data.setXcreateTime(resultSet->getString(2));
		data.setXsequence(resultSet->getString(3));
		data.setXupdateTime(resultSet->getString(4));
		data.setXdistributeFactor(resultSet->getInt(5));
		data.setXappId(resultSet->getString(6));
		data.setXbooleanValue(resultSet->getInt(7));
		data.setXbundle(resultSet->getString(8));
		data.setXdateTimeValue(resultSet->getString(9));
		data.setXdateValue(resultSet->getString(10));
		data.setXitemCategory(resultSet->getString(11));
		data.setXitemPrimitiveType(resultSet->getString(12));
		data.setXitemStringValueType(resultSet->getString(13));
		data.setXitemType(resultSet->getString(14));
		data.setXnumberValue(resultSet->getDouble(15));
		data.setXpath0(resultSet->getString(16));
		data.setXpath0Location(resultSet->getString(17));
		data.setXpath1(resultSet->getString(18));
		data.setXpath1Location(resultSet->getString(19));
		data.setXpath2(resultSet->getString(20));
		data.setXpath2Location(resultSet->getString(21));
		data.setXpath3(resultSet->getString(22));
		data.setXpath3Location(resultSet->getString(23));
		data.setXpath4(resultSet->getString(24));
		data.setXpath4Location(resultSet->getString(25));
		data.setXpath5(resultSet->getString(26));
		data.setXpath5Location(resultSet->getString(27));
		data.setXpath6(resultSet->getString(28));
		data.setXpath6Location(resultSet->getString(29));
		data.setXpath7(resultSet->getString(30));
		data.setXpath7Location(resultSet->getString(31));
		data.setXstringLongValue(resultSet->getString(32));
		data.setXstringShortValue(resultSet->getString(33));
		data.setXtimeValue(resultSet->getString(34));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_
