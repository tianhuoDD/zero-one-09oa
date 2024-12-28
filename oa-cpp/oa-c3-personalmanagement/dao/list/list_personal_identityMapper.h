#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/31 20:05:13

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
#ifndef _LIST_PERSONAL_IDENTITYMAPPER_
#define _LIST_PERSONAL_IDENTITYMAPPER_
#include "Mapper.h"

#include "../../domain/do/list/org_identityDO.h"

class list_personal_identityMapper : public Mapper<org_identityDO>
{
public:
	org_identityDO mapper(ResultSet* resultSet) const override
	{
		//xname, xunitName, xunique, xdistinguishedName, xmajor
		org_identityDO data;
		data.setXname(resultSet->getString(1));
		data.setXunitName(resultSet->getString(2));
		data.setXid(resultSet->getString(3));
		data.setXdistinguishedName(resultSet->getString(4));
		data.setXmajor(resultSet->getBoolean(5));
		return data;
	}
};






#endif // !_LIST_PERSONAL_IDENTITYMAPPER_
