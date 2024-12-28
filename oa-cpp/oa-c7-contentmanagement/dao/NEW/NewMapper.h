#pragma once
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
#ifndef _NEW_MAPPER_
#define _NEW_MAPPER_

#include "Mapper.h"
#include "../../domain/do/New/NewDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class NewMapper : public Mapper<NewDO>
{
public:
	NewDO mapper(ResultSet* resultSet) const override
	{
		NewDO data;
		data.setxappIcon(resultSet->getString(1));
		data.setxappName(resultSet->getString(2));
		data.setxappAlias(resultSet->getString(3));
		data.setxdescription(resultSet->getString(4));
		data.setxsequence(resultSet->getString(5));
		data.setxdocumentType(resultSet->getString(6));
		data.setignore1(resultSet->getString(7));
		data.settimed(resultSet->getString(8));
		data.setxappType(resultSet->getString(9));
		data.setxshowAlldocuments(resultSet->getString(10));
		data.setautosave(resultSet->getString(11));
		data.setxdefaultEditForm(resultSet->getString(12));
		data.setxdefaultReadForm(resultSet->getString(13));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_