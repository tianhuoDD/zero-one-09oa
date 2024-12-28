




#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Rif
 @Date: 2022/10/25 11:08:56

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
#ifndef _ORGANIZATION_SERVICE_
#define _ORGANIZATION_SERVICE_
#include <list>
#include "domain/do/Organization/OrganizationDO.h"
#include "domain/vo/Organization/OrganizationMemberVO.h"
#include "domain/vo/Organization/OrganizationNameVO.h"
#include "domain/dto/Organization/OrganizationMemberDTO.h"
#include "domain/dto/Organization/OrganizationNameDTO.h"
#include "dao/Organization/OrganizationDAO.h"


/**
 * 示例服务实现，演示基础的示例服务实现
 */
class OrganizationService 
{
public:
	// 查询组织
	OrganizationNamePageDTO::Wrapper queryOrg(const OrgQuery::Wrapper& query);
	// 查询组织成员
	OrganizationMemberPageDTO::Wrapper queryOrgMem(const OrgQuery::Wrapper& query);
};

#endif // !_ORGANIZATION_SERVICE_








































