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
#ifndef _SHAREFILES_MAPPER_
#define _SHAREFILES_MAPPER_

#include "Mapper.h"
#include "../../domain/do/file/file_attachment_sharelistDO.h"

/**
 * ????¡À¨ª¡Á???????????
 */
class ShareFilesMapper : public Mapper<file_attachment_sharelistDO>
{
public:
	file_attachment_sharelistDO mapper(ResultSet* resultSet) const override
	{
		file_attachment_sharelistDO data;
		data.setattachment_xid(resultSet->getString(1));
		data.setXshareList(resultSet->getString(2));
		data.setXorderColumn(resultSet->getInt(3));
		return data;
	}
};

class ShareFilesMapperlog : public Mapper<FileLogDO>
{
public:
	FileLogDO mapper(ResultSet* resultSet) const override
	{
		FileLogDO data;
		data.setXid(resultSet->getString(1));
		data.setXOperationType(resultSet->getInt(2));
		data.setXFromPerson(resultSet->getString(3));
		data.setXToPerson(resultSet->getString(4));
		data.setXOperationTime(resultSet->getString(5));
		data.setFile_attachment_id(resultSet->getString(6));
		return data;
	}
};

#endif // !_SHAREFILES_MAPPER_