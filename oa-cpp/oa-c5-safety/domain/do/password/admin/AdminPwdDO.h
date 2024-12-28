#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _ADMINPWD_DO_
#define _ADMINPWD_DO_
#include "../../DoInclude.h"
#include"../../../../../lib-common/include/SimpleDateTimeFormat.h"

/**
 * 示例数据库实体类
 */
class AdminPwdDO
{
	//// 编号
	//CC_SYNTHESIZE(uint64_t, xid, Id);
	//CC_SYNTHESIZE(string, xoldpassword, OldPassword);
	//CC_SYNTHESIZE(string, xnewpassword, NewPassword);
	//CC_SYNTHESIZE(string, xconfirmpassword, ConfirmPassword);
	//CC_SYNTHESIZE(string, xchangePasswordTime, ChangePasswordTime);
	//CC_SYNTHESIZE(string, xpasswordExpiredTime, PasswordExpiredTime);

	// 关于用户配置：主要有 编号、用户名、密码、上一次登陆时间、绑定邮箱、绑定手机号、半小时内尝试登陆次数、权限（admin、普通用户）、登陆地址IP
	// 数据唯一编号
	CC_SYNTHESIZE(uint64_t, xid, Id);
	// 旧密码
	CC_SYNTHESIZE(string, xoldpassword, OldPassword);
	// 新密码
	CC_SYNTHESIZE(string, xnewpassword, NewPassword);
	//确认密码
	CC_SYNTHESIZE(string, xconfirmpassword, ConfirmPassword);
	//修改密码时间
	CC_SYNTHESIZE(string, xchangePasswordTime, ChangePasswordTime);
	//最近登陆时间
	CC_SYNTHESIZE(string, xpasswordExpiredTime, PasswordExpiredTime);


public:
	AdminPwdDO() {
		xid = 0;
		xoldpassword = "";
		xnewpassword = "";
		xconfirmpassword = "";
		xchangePasswordTime = getCurrentTime();
		xpasswordExpiredTime = getCurrentTime();

	}
	

	std::string getCurrentTime() {
		//std::time_t t = std::time(nullptr);
		//std::tm* tm = std::localtime(&t);
		//std::ostringstream oss;
		//oss << put_time(tm, "%Y-%m-%d %H:%M:%S"); // 格式化时间
		//return oss.str();
		string ret = SimpleDateTimeFormat::format();
		return ret;
	}
};

#endif // !_ADMINPWD_DO_