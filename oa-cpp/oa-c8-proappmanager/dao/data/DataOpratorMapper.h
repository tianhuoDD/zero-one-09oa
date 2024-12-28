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
#include "../../domain/do/data/DataOpDO.h"
/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class DataOpMapper : public Mapper<DataOpDO>
{
public:
	DataOpDO mapper(ResultSet* resultSet) const override
	{
		DataOpDO data;
		//Á½¸ö×Ö·û
		data.setId(resultSet->getString(1));
		return data;
	}

};	
class DataItemOpMapper : public Mapper<DataOpItemDO>
{
public:
	DataOpItemDO mapper(ResultSet* resultSet) const override
	{
		DataOpItemDO item_data;
		//Á½¸ö×Ö·û
		item_data.setItemId(resultSet->getString(2));
		return item_data;
	}
	
};


#endif // !_SAMPLE_MAPPER_