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
#ifndef _ORGSTRUCT_MAPPER_
#define _ORGSTRUCT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/OrgStructDO/OrgStructDO.h"

/**
 * 示例表字段匹配映射
 */
class OrgStructMapper : public Mapper<OrgStructDO>
{
public:
	OrgStructDO mapper(ResultSet* resultSet) const override
	{
		OrgStructDO data;
		//data.setPageIndex(resultSet->getUInt64(1));
		//data.setPageSize(resultSet->getUInt64(1));
		data.setXdistinguishedName(resultSet->getString(1));
		data.setXemployee(resultSet->getString(2));
		data.setXmail(resultSet->getString(3));
		data.setXmobile(resultSet->getString(4));
		data.setXunique(resultSet->getString(5));
		data.setXiconLdpi(resultSet->getString(6));
		data.setXname(resultSet->getString(7));
		data.setXid(resultSet->getString(8));
		return data;
	}
};


class OrgStaffMapper : public Mapper<OrgStructDO>
{
public:
	OrgStructDO mapper(ResultSet* resultSet) const override
	{
		OrgStructDO data;
		//查询个人信息
		data.setXdistinguishedName(resultSet->getString(1));
		//查询电话
		data.setXmobile(resultSet->getString(2));
		return data;
	}
};


#endif // !_ORGSTRUCT_MAPPER_