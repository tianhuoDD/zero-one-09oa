#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wangye
 @Date: 2024/10/25 14:21:55

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
#ifndef _MENUINFO_MAPPER_
#define _MENUINFO_MAPPER_

#include "Mapper.h"
#include "../../domain/do/menuinfo/MenuInfoDO.h"

/**
 * MenuInfo表字段匹配映射
 */
class MenuInfoMapper : public Mapper<MenuInfoDO>
{
public:
	MenuInfoDO mapper(ResultSet* resultSet) const override
	{
		// 按照MenuInfoDO.h文件里的顺序写的
		MenuInfoDO data;
		data.setMenu_Id(resultSet->getString(3));
		data.setMenu_Name(resultSet->getString(2));
		//data.setOrgabbreviation(resultSet->getString(3));
		//data.setOrgicon(resultSet->getString(3));
		//data.setOrgsortingvalue(resultSet->getInt(4));
		//data.setOrgdescription(resultSet->getString(3));
		data.setMenu_Type(resultSet->getInt(3));
		data.setParent_Id(resultSet->getString(3));
		//data.setManager(resultSet->getString(3));
		return data;
	}
};

#endif // !_MENUINFO_MAPPER_