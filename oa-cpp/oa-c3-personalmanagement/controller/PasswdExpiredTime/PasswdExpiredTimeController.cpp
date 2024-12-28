#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/10/20 17:58:35

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

#include "PasswdExpiredTimeController.h"
#include "service/PasswdExpiredTime/PasswdExpiredTimeService.h"

StringJsonVO::Wrapper PasswdExpiredTimeController::
					     execSetPasswdExipredTime(const PasswdExpiredTimeQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ���µ���service��
	PasswdExpiredTimeService service;

	// ��resΪ��, ������ɹ�, ���ص�ǰϵͳʱ��; ���򷵻�res(Ϊ����ԭ��)
	std::string res = service.setPasswdExpiredTime(query);

	// ��Ӧ���
	auto jvo = StringJsonVO::createShared();
	if(!res.empty()) {
		jvo->success(res);
	}
	else {
		jvo->fail("Failed. Same Value");
	}
	
	return jvo;
}