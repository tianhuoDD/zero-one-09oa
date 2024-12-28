




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
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class OrganizationService 
{
public:
	// ��ѯ��֯
	OrganizationNamePageDTO::Wrapper queryOrg(const OrgQuery::Wrapper& query);
	// ��ѯ��֯��Ա
	OrganizationMemberPageDTO::Wrapper queryOrgMem(const OrgQuery::Wrapper& query);
};

#endif // !_ORGANIZATION_SERVICE_








































