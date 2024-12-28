
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
#ifndef _ORGANIZATION_MAPPER_
#define _ORGANIZATION_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Organization/OrganizationDO.h"

/**
 * 公司名称表映射
 */
class OrganizationNameMapper : public Mapper<OrganizationNameDO>
{
public:
	OrganizationNameDO mapper(ResultSet* resultSet) const override
	{
		OrganizationNameDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

/**
 * 公司成员表映射
 */
class OrganizationMemberMapper : public Mapper<OrganizationMemberDO>
{
public:
	OrganizationMemberDO mapper(ResultSet* resultSet) const override
	{
		OrganizationMemberDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		//data.setEmployee(resultSet->getString(3));
		return data;
	}
};
#endif // !_ORGANIZATION_MAPPER_
