#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/27 14:46:21

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
#ifndef _GETGROUPINFODAO_H_
#define _GETGROUPINFODAO_H_
#include "BaseDAO.h"
//#include "../../../domain/query/get/GetGroupInfo/GetGroupInfoQuery.h"
#include "../../../domain/do/groupmanagement/OrgGroupDO.h"

class GetGroupInfoDAO : public BaseDAO
{
public:
	// 统计数据条数
	//uint64_t count(const GetGroupInfoQuery::Wrapper& query);

	// 通过姓名查询数据
	list<OrgGroupDO> selectByName(const string& name);
	// 通过id查询数据
	list<OrgGroupDO> selectById(const string& id);

};

#endif // !_GETGROUPINFODAO_H_