/*
 Copyright Zero One Star. All rights reserved.

 @Author: wangye
 @Date: 2024/10/20 17:58:42

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
#include "MenuInfoController.h"
#include "service/menuAD/MenuInfoService.h"  //*����Ӧ��Ҫд�Լ����ļ�
#include "../ApiDeclarativeServicesHelper.h"




MenuInfoJsonVO::Wrapper MenuInfoController::executeQueryMenuInfo(const String& menu_id)
{

	// ���巵�����ݶ���
	auto jvo = MenuInfoJsonVO::createShared();
	// ����һ��Service
	MenuInfoService service;
	// ִ�����ݲ�ѯ
	auto id2 = menu_id.getValue("");
	auto res = service.queryData(id2);
	jvo->success(res);
	// ��Ӧ���
	return jvo;
	//return {};
}

// PersonInfoDTO::Wrapper <===> oatpp::Object<PersonInfoDTO>
StringJsonVO::Wrapper MenuInfoController::executeModifyMenuInfo(const MenuInfoDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	string menu_id2 = dto->menu_id.getValue("");

	
	if (!dto->menu_id || stoi(menu_id2) <= 0)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	MenuInfoService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->menu_id);
	}
	else
	{
		jvo->fail(dto->menu_id);
	}
	// ��Ӧ���
	return jvo;
	//return {};

}
