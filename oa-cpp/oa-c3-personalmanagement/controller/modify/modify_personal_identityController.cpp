/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/23 1:05:55

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
#include "modify_personal_identityController.h"
#include "../../domain/dto/modify/modify_personal_identityDTO.h"
#include "../../service/modify/modify_personal_identityService.h"
#include "../ApiDeclarativeServicesHelper.h"


StringJsonVO::Wrapper modify_personalidentityController::execModify_personalidentity(const modify_personal_identityDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (dto->xid->empty())
	{
		jvo->init(String(" "), RS_PARAMS_INVALID);
		return jvo;
	}


	// ����һ��Service
	modify_personal_identityService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->xid);
	}
	else
	{
		jvo->fail(dto->xid);
	}
	// ��Ӧ���
	return jvo;
}