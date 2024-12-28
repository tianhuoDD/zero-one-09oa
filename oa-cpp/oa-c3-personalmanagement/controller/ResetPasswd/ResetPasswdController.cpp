#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/10/20 19:44:07

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
#include "ResetPasswdController.h"
#include "service/ResetPasswd/ResetPasswdService.h"

Int32JsonVO::Wrapper ResetPasswdController::
						execResetPasswd(const ResetPasswdQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 向下层传递给service
	ResetPasswdService service;
	int32_t res = service.updateResetPasswd(query);

	auto jvo = Int32JsonVO::createShared();
	jvo->success(res);
	return jvo;
}
