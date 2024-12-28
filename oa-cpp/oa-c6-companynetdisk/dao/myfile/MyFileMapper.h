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
#ifndef _MYFILE_MAPPER_
#define _MYFILE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/myfile/MyFileDO.h"
#include "../../domain/do/file/file_attachment2DO.h"
#include "../../domain/do/file/file_attachmentDO.h"
#include "../../domain/do/folder/folder_queryDO.h"
/**
 * xiaohaizi
 */
class MyFileMapper : public Mapper<MyFileDO>
{
public:
	MyFileDO mapper(ResultSet* resultSet) const override
	{
		MyFileDO data;
		data.setXstorage(resultSet->getString(1));
		return data;
	}
};

class MyFileMapperN : public Mapper<MyFileDO>
{
public:
	MyFileDO mapper(ResultSet* resultSet) const override
	{
		MyFileDO data;
		data.setXname(resultSet->getString(1));
		return data;
	}
};



//Yu
class MyfileMapper : public Mapper<folder_queryDO>
{
public:
	folder_queryDO mapper(ResultSet* resultSet) const override
	{
		folder_queryDO data;
		data.setXid(resultSet->getString(1));
		data.setXcreateTime(resultSet->getString(2));
		data.setXsequence(resultSet->getString(3));
		data.setXupdateTime(resultSet->getString(4));
		data.setXdeepPath(resultSet->getInt(5));
		data.setXextension(resultSet->getString(6));
		data.setXlastUpdatePerson(resultSet->getString(7));
		data.setXlastUpdateTime(resultSet->getString(8));
		data.setXlength(resultSet->getUInt64(9));
		data.setXname(resultSet->getString(10));
		data.setXperson(resultSet->getString(11));
		data.setXstorage(resultSet->getString(12));
		data.setfolder_Xid(resultSet->getString(13));
		data.setfolder_XcreateTime(resultSet->getString(14));
		data.setfolder_Xsequence(resultSet->getString(15));
		data.setfolder_XupdateTime(resultSet->getString(16));
		data.setfolder_Xname(resultSet->getString(17));
		data.setfolder_Xperson(resultSet->getString(18));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_