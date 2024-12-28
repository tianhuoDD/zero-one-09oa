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
#ifndef _ACCEPTFILELIST_MAPPER_
#define _ACCEPTFILELIST_MAPPER_
#include "Mapper.h"
#include "../../../domain/do/file/file_attachmentDO.h"

/**
 * 
 */
class AcceptFileListMapper : public Mapper<file_attachmentDO>
{
public:
	file_attachmentDO mapper(ResultSet* resultSet) const override
	{
		file_attachmentDO data;
		data.setXname(resultSet->getString(1));
		data.setXperson(resultSet->getString(2));
		data.setXcreateTime(resultSet->getString(3));
		data.setXlastUpdateTime(resultSet->getString(4));
		data.setXlength(resultSet->getUInt64(5));



		return data;
	}
};

#endif // !_SAMPLE_MAPPER_