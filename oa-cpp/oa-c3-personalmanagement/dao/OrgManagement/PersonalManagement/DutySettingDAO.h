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
#ifndef _DUTYSETTINGDAO_H_
#define _DUTYSETTINGDAO_H_
#include "BaseDAO.h"
#include <list>
#include "domain/do/OrgManagement/PersonalManagement/org_identityDO.h"
#include "domain/do/OrgManagement/PersonalManagement/org_unitduty_identitylistDO.h"
#include "domain/dto/OrgManagement/PersonalManagement/DutySettingDTO.h"
/**
 * 示例表数据库操作实现
 */
class DutySettingDAO : public BaseDAO
{
public:
	//解除职务
	int deleteByIdentity(const DutySettingDTO::Wrapper& dto);
	int insert(const list<org_unitduty_identitylistDO>& data);
};
#endif // !_DUTYSETTINGDAO_H_
