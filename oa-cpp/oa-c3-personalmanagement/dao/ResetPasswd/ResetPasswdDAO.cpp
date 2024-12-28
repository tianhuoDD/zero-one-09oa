#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: กฃบร
 @Date: 2024/11/01 15:59:59

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
#include "ResetPasswdDAO.h"

int32_t ResetPasswdDAO::updateResetPasswd(const org_personDO& _do)
{
	std::string sql{"UPDATE `org_person` SET `xpassword`=? WHERE `xid`=?"};
	return sqlSession->executeUpdate(sql, "%s%s", _do.getXpassword(), _do.getXid());
}