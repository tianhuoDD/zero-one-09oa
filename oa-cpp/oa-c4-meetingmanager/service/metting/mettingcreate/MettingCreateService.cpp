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
#include "MettingCreateService.h"
#include "../../../dao/metting/mettingcreate/MettingCreateDAO.h"

uint64_t MettingCreateService::saveData(const MettingCreateDTO::Wrapper& dto)
{
	// 组装DO数据
	MettingCreateDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, MettingType, mettingtype, Date, date1, TimeStart, timestart, TimeEnd, timeend, MettingRoom, mettingroom, MettingTitle, mettingtitle, Member, member, Hoster, hoster, Department, department, Description, description);
	// 执行数据添加
	MettingCreateDAO dao;
	return dao.insert(data);
}
