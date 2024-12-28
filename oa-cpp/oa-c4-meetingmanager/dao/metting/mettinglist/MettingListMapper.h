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
#ifndef _MettingList_MAPPER_
#define _MettingList_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/metting/mettinglist/MettingCreateDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class MettingListMapper : public Mapper<MettingListDO>
{
public:
	MettingListDO mapper(ResultSet* resultSet) const override
	{
		MettingListDO data;
		data.setDates(resultSet->getString(2));
		data.setNames(resultSet->getString(1));
		data.setTimeend(resultSet->getString(4));
		data.setMtroom(resultSet->getString(6));
		data.setTimestart(resultSet->getString(3));
		data.setTitle(resultSet->getString(5));

		return data;
	}
};

#endif // !_MettingList_MAPPER_