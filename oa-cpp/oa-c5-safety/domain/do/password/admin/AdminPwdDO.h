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
 * ʾ�����ݿ�ʵ����
 */
class AdminPwdDO
{
	//// ���
	//CC_SYNTHESIZE(uint64_t, xid, Id);
	//CC_SYNTHESIZE(string, xoldpassword, OldPassword);
	//CC_SYNTHESIZE(string, xnewpassword, NewPassword);
	//CC_SYNTHESIZE(string, xconfirmpassword, ConfirmPassword);
	//CC_SYNTHESIZE(string, xchangePasswordTime, ChangePasswordTime);
	//CC_SYNTHESIZE(string, xpasswordExpiredTime, PasswordExpiredTime);

	// �����û����ã���Ҫ�� ��š��û��������롢��һ�ε�½ʱ�䡢�����䡢���ֻ��š���Сʱ�ڳ��Ե�½������Ȩ�ޣ�admin����ͨ�û�������½��ַIP
	// ����Ψһ���
	CC_SYNTHESIZE(uint64_t, xid, Id);
	// ������
	CC_SYNTHESIZE(string, xoldpassword, OldPassword);
	// ������
	CC_SYNTHESIZE(string, xnewpassword, NewPassword);
	//ȷ������
	CC_SYNTHESIZE(string, xconfirmpassword, ConfirmPassword);
	//�޸�����ʱ��
	CC_SYNTHESIZE(string, xchangePasswordTime, ChangePasswordTime);
	//�����½ʱ��
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
		//oss << put_time(tm, "%Y-%m-%d %H:%M:%S"); // ��ʽ��ʱ��
		//return oss.str();
		string ret = SimpleDateTimeFormat::format();
		return ret;
	}
};

#endif // !_ADMINPWD_DO_