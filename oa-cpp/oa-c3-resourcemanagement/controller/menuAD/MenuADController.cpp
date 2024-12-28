/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/20 16:29:31

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
#include "MenuADController.h"
#include"./service/menuAD/MenuADService.h"


Uint64JsonVO::Wrapper MenuADController::execAddMenu(const MenuADDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	
	// 非空校验
	if (!dto->menu_id || !dto->menu_name || !dto->menu_type || !dto->parent_id || !dto->status || !dto->level)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->menu_id == dto->parent_id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	if ( dto->menu_name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	MenuADService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	jvo->success(UInt64(id));
	//响应结果
	return jvo;
}

StringJsonVO::Wrapper MenuADController::execRemoveMenu(const string& id)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (id == "")
	{
		jvo->init("-1", RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	MenuADService service;
	// 执行数据删除
	if (service.removeData(id)) {

		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}