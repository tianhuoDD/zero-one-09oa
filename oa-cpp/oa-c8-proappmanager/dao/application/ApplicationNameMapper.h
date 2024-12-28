/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/25 23:08:07

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
#ifndef _APPLICATIONNAMEMAPPER_H_
#define _APPLICATIONNAMEMAPPER_H_
#include "domain/do/application/ApplicationNameDO.h"
#include "Mapper.h"

class ApplicationNameMapper : public Mapper<ApplicationNameDO>
{
public:
	ApplicationNameDO mapper(ResultSet* resultSet) const override
	{
		ApplicationNameDO names;
		names.setName(resultSet->getString(1));
		return names;
	}
};

#endif // !_APPLICATIONNAMEMAPPER_H_