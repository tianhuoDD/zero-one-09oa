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
#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/attachment/AttachmentListDO.h"
#include "../../domain/do/attachment/AttachmentDetailDO.h"
/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class AttachmentListMapper : public Mapper<AttachmentListDO>
{
public:
	AttachmentListDO mapper(ResultSet* resultSet) const override
	{
		AttachmentListDO data;
		data.setXid(resultSet->getString(1));
		data.setXname(resultSet->getString(2));
		data.setXalias(resultSet->getString(3));
		data.setXdescription(resultSet->getString(4));
		data.setXapplication(resultSet->getString(5));
		data.setXlastUpdatePerson(resultSet->getString(6));
		data.setXlastUpdateTime(resultSet->getString(7));
		data.setXfileName(resultSet->getString(8));
		data.setXlength(resultSet->getInt64(9));
		data.setXcreateTime(resultSet->getString(10));
		data.setXupdateTime(resultSet->getString(11));
		return data;
	}
};

class AttachmentDetailMapper : public Mapper<AttachmentDetailDO>
{
public:
	AttachmentDetailDO mapper(ResultSet* resultSet) const override
	{
		AttachmentDetailDO data;
		data.setXid(resultSet->getString("xid"));
		data.setXname(resultSet->getString("xname"));
		data.setXalias(resultSet->getString("xalias"));
		data.setXdescription(resultSet->getString("xdescription"));
		data.setXapplication(resultSet->getString("xapplication"));
		data.setXlastUpdatePerson(resultSet->getString("xlastUpdatePerson"));
		data.setXlastUpdateTime(resultSet->getString("xlastUpdateTime"));
		data.setXfileName(resultSet->getString("xfileName"));
		data.setXlength(resultSet->getInt64("xlength"));
		data.setXcreateTime(resultSet->getString("xcreateTime"));
		data.setXupdateTime(resultSet->getString("xupdateTime"));
		data.setXdata(resultSet->getString("xdata"));
		return data;
	}
};

class AttachmentMapper : public Mapper<AttachmentDO>
{
public:
	AttachmentDO mapper(ResultSet* resultSet) const override
	{
		AttachmentDO data;
		data.setXid(resultSet->getString(1));
		data.setXname(resultSet->getString(2));
		data.setXalias(resultSet->getString(3));
		data.setXdescription(resultSet->getString(4));
		data.setXapplication(resultSet->getString(5));
		data.setXlastUpdatePerson(resultSet->getString(6));
		data.setXlastUpdateTime(resultSet->getString(7));
		data.setXfileName(resultSet->getString(8));
		data.setXlength(resultSet->getInt64(9));
		data.setXcreateTime(resultSet->getString(10));
		data.setXupdateTime(resultSet->getString(11));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_