#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/23 1:06:10

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
#ifndef _MODIFY_LOCKORUNLOCK_OFFICERMAPPER_
#define	_MODIFY_LOCKORUNLOCK_OFFICERMAPPER_
// Mapper
#include "Mapper.h"

#include "domain/do/org_personDo/org_personDO.h"

class modify_lockorunlock_officerMapper : public Mapper<org_personDO>
{
public:
	org_personDO mapper(ResultSet* resultSet) const override
	{
		org_personDO data;
		data.setXid(resultSet->getString(""));
		data.setXlockTime(resultSet->getString(""));
		data.setXstatusDes(resultSet->getString(""));
		data.setXstatus(resultSet->getString(""));


		return data;
	}
};





#endif // !_MODIFY_LOCKORUNLOCK_OFFICERMAPPER_
