/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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
#include "adminPwdDAO.h"
#include "adminPwdMapper.h"
#include <sstream>
#include "domain/do/password/admin/AdminPwdDO.h"

int adminPwdDAO::update(const AdminPwdDO& uObj)
{
	string sql = "UPDATE `sys_adminpassword` SET `xnewpassword`=?, `xconfirmpassword`=?, `xchangePasswordTime`=?, `xpasswordExpiredTime`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%ull", uObj.getNewPassword(), uObj.getConfirmPassword(), uObj.getChangePasswordTime(), uObj.getPasswordExpiredTime(), uObj.getId());
}




