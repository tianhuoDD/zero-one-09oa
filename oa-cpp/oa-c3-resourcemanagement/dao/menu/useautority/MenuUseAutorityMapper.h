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
#ifndef _MENUUSEAUTORITY_MAPPER_
#define _MENUUSEAUTORITY_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/org_role_menulistDO/org_role_menulistDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class MenuUseAutorityMapper : public Mapper<Org_role_menulistDO>
{
public:
	Org_role_menulistDO mapper(ResultSet* resultSet) const override
	{
		Org_role_menulistDO data;
		//data.setId(resultSet->getUInt64(1));
		//data.setName(resultSet->getString(2));
		//data.setSex(resultSet->getString(3));
		//data.setAge(resultSet->getInt(4));
		data.setrole_Id(resultSet->getString(1));
		data.setMenulist(resultSet->getString(2));
		data.setXorderColumn(resultSet->getInt(3));
		
		
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_