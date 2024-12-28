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
#ifndef _DISABLEUNBANPERSON_MAPPER_
#define _DISABLEUNBANPERSON_MAPPER_

#include "Mapper.h"
#include "../../domain/do/org_personDo/org_personDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class DisableUnbanPersonMapper : public Mapper<org_personDO>
{
public:
	org_personDO mapper(ResultSet* resultSet) const override
	{
		org_personDO data;
		data.setXid(resultSet->getString(1));
		data.setXstatus(resultSet->getString(2));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_