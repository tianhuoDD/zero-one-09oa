/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "MettingRoomController.h"
#include "../../../service/metting/mettingroom/MettingRoomService.h"
#include "../../ApiDeclarativeServicesHelper.h"

MettingBuildPageJsonVO::Wrapper MettingRoomController::execQueryBuild()
{
	MettingRoomService service;
	auto result = service.listAll();
	auto jvo = MettingBuildPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper MettingRoomController::execAddMettingRoom(const MettingRoomDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 非空校验
	if (!dto->name || !dto->location || !dto->floor || !dto->capacity || !dto->status)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->name.getValue("") == "" || dto->floor < -2 || dto->floor > 50 || dto->capacity < 0 || dto->capacity > 500)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	MettingRoomService service;
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}
