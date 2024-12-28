/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/11/01 15:58:03

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
#include "ResetPasswdService.h"
#include "dao/ResetPasswd/ResetPasswdDAO.h"
#include "domain/do/org_personDo/org_personDO.h"

int32_t ResetPasswdService::updateResetPasswd(const ResetPasswdQuery::Wrapper& query)
{
	org_personDO _do;
	// 将query转换成do
	ZO_STAR_DOMAIN_DTO_TO_DO(_do, query, Xid, id, Xpassword, passwd);
	
	// 调用dao
	ResetPasswdDAO dao;
	return dao.updateResetPasswd(_do);
}