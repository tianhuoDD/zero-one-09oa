#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#ifndef _ORGSTRUCTSERVICE_H_
#define _ORGSTRUCTSERVICE_H_
#include <list>
#include "domain/vo/OrgStructVO/OrgStructVO.h"
#include "domain/query/OrgStructQuery/OrgStructQuery.h"
#include "domain/dto/OrgStructDTO/OrgStructDTO.h"


class OrgStructService
{
public:
	// 分页查询所有数据
	OrgStructPageDTO::Wrapper listAll(const OrgStructPageQuery::Wrapper& query);
};

class OrgStaffService
{
public:
	// 分页查询数据
	OrgStaffPageDTO::Wrapper list(const OrgStaffPageQuery::Wrapper& query);
	// 分页查询所有数据
	OrgStaffPageDTO::Wrapper listAll(const OrgStaffPageQuery::Wrapper& query);
};


class OrgDelectService
{
public:
	// 通过ID删除数据
	bool removeData(const DeleteOrgmeberDTO::Wrapper& condtion);
};

#endif // !_ORGSTRUCTSERVICE_H_

