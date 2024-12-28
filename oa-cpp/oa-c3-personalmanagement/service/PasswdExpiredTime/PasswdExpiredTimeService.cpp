/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/10/31 16:38:45

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
#include "PasswdExpiredTimeService.h"
#include "dao/PasswdExpiredTime/PasswdExpiredTimeDAO.h"
#include "domain/query/ResetPasswd/ResetPasswdQuery.h"
#include "domain/do/org_personDo/org_personDO.h"

std::string PasswdExpiredTimeService::
	setPasswdExpiredTime(const PasswdExpiredTimeQuery::Wrapper& query)
{
	// ��queryת����do���ݸ�dao
	org_personDO _do;
	ZO_STAR_DOMAIN_DTO_TO_DO(_do, query, Xid, id, XpasswordExpiredTime, date);

	// ���µ���dao��
	PasswdExpiredTimeDAO dao;
	int res = dao.updatePasswdExpiredTime(_do);
	
	// ���ؿ�
	if (res == 0) {
		return oatpp::String("");
	}

	// ����ʱ��
	time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	auto tt = std::localtime(&now);
	char str[25] = { 0 };
	sprintf(str, "%d-%02d-%02d %02d:%02d:%02d", tt->tm_year + 1900,
		tt->tm_mon + 1, tt->tm_mday, tt->tm_hour, tt->tm_min, tt->tm_sec);
	
	return oatpp::String(str);
}