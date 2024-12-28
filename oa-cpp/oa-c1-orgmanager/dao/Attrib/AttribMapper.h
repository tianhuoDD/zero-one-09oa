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
#ifndef _ATTRIB_MAPPER_
#define _ATTRIB_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Attrib/AttribDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class AttribMapper : public Mapper<AttribDO>
{
public:
	AttribDO mapper(ResultSet* resultSet) const override
	{
		AttribDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setShuxing(resultSet->getString(3));
		data.setValue(resultSet->getInt(4));
		data.setMiaoshu(resultSet->getString(5));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_