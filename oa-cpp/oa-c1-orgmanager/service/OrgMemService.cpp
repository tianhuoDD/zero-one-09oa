/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "stdafx.h"
#include "OrgMemService.h"
#include "../dao/OrgMemDAO.h"

bool OrgMemService::addData(string orgID, string personID)
{
	// 组装DO数据
	OrgMemDO data;
	// 执行数据添加
	OrgJobDAO dao;
	return dao.add(orgID, personID);
}
bool OrgMemService::removeData(string orgID, string personID)
{
	OrgMemDAO dao;
	return dao.deleteById(orgID,personID) == 1;
}
bool OrgJobService::removeData(string personID, string dutyID)
{
	OrgJobDAO dao;
	return dao.deleteById(personID,dutyID) == 1;
}
bool OrgJobService::addData(string personID, string dutyID) {
	// 组装DO数据
	OrgMemDO data;
		// 执行数据添加
		OrgJobDAO dao;
	return dao.add(personID,dutyID);
}
