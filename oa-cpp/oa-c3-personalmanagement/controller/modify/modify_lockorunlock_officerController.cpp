/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/24 1:05:55

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
#include "modify_lockorunlock_officerController.h"
#include "service/modify/modify_lockorunlock_officerService.h"
#include "../ApiDeclarativeServicesHelper.h"
StringJsonVO::Wrapper modify_lockorunlock_officerController::execModify_lockorunlock_officer(const modify_lockorunlock_officerDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (dto->xid->empty())
	{
		jvo->init(String(" "), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	//cout << dto->xunique.getValue("") << endl;
	modify_lockorunlock_officerService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->xid);
	}
	else
	{
		jvo->fail(dto->xid);
	}


	// 响应结果
	return jvo;
}
