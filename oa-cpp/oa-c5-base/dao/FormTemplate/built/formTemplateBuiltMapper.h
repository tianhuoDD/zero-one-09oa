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
#ifndef _FORMTEMPLATEBUILT_MAPPER_
#define _FORMTEMPLATEBUILT_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/formTemplate/built/formTemplateBuiltDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class formTemplateBuiltMapper : public Mapper<formTemplateBuiltDO>
{
public:
	formTemplateBuiltDO mapper(ResultSet* resultSet) const override
	{
		formTemplateBuiltDO data;
		data.setId(resultSet->getUInt64(1));
		data.setCreateTime(resultSet->getString(2));
		data.setSequence(resultSet->getString(3));
		data.setUpdateTime(resultSet->getString(4));
		data.setDistributeFactor(resultSet->getString(5));
		data.setAlias(resultSet->getString(6));
		data.setCategory(resultSet->getString(7));
		data.setData(resultSet->getString(8));
		data.setDescription(resultSet->getString(9));
		data.setIcon(resultSet->getString(10));
		data.setMobileData(resultSet->getString(11));
		data.setName(resultSet->getString(12));
		data.setOutline(resultSet->getString(13));

		/*data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setSex(resultSet->getString(3));
		data.setAge(resultSet->getInt(4));*/
		return data;
	}
};

#endif // !_FORMTEMPLATEBUILT_MAPPER_