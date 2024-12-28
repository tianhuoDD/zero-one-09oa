#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _DISABLEUNBANPERSON_DAO_
#define _DISABLEUNBANPERSON_DAO_
#include "BaseDAO.h"
#include "../../domain/do/org_personDo/org_personDO.h"

/**
 * 示例表数据库操作实现
 */
class DisableUnbanPersonDAO : public BaseDAO
{
public:

	// 修改数据
	int update(const org_personDO& uObj);

};
#endif // !_SAMPLE_DAO_
