
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
#ifndef _ORGANIZATION_DAO_
#define _ORGANIZATION_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Organization/OrganizationDO.h"
#include "../../domain/query/OrgQuery.h"
//#include "../domain/do/sample/SampleDO.h"
//#include "../domain/query/sample/SampleQuery.h" //��Ϊֱ����string��ѯ����������Ϊ���ﲻ���ٰ�װ

/**
 * ʾ�������ݿ����ʵ��
 */
class OrganizationDAO : public BaseDAO
{
public:
	// ͨ��������ѯ����
	list<OrganizationNameDO> selectByName(const OrgQuery::Wrapper& query);

	// ͨ��������ѯ����
	list<OrganizationMemberDO> selectByNameMember(const OrgQuery::Wrapper& query);

	uint64_t countName(const OrgQuery::Wrapper& query);

	uint64_t countMember(const OrgQuery::Wrapper& query);
};
#endif // !_ORGANIZATION_DAO_
