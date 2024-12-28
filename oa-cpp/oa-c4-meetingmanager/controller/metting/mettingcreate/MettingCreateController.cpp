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
#include "MettingCreateController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "../../../../lib-common/include/SimpleDateTimeFormat.h"
#include "service/metting/mettingcreate/MettingCreateService.h"

Uint64JsonVO::Wrapper MettingCreateController::execMettingCreate(const MettingCreateDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//参数校验
	
	// 会议标题、会议室、参会人员不能空
	//if (!dto->member && !dto->mettingtitle && !dto->mettingtitle)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 会议时间校验
	SimpleDateTimeFormat format;
	auto date_str = format.format("%Y-%m-%d");
	//if(dto->date1 < date_str) //这里能不能转string
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	date_str = format.format("%H:%M:%S");
	//if(dto->timestart < dto->timeend && dto->timestart > date_str)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 参数校验

	// Service
	MettingCreateService service;
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}

	return jvo;
}

MettingRoomPageJsonVO::Wrapper MettingCreateController::execQueryRoom()
{
	return {};
}

MettingHostPageJsonVO::Wrapper MettingCreateController::execQueryHoster(const PageQuery::Wrapper& userquery, const PayloadDTO& payload)
{
	return {};
}

MettingDepartPageJsonVO::Wrapper MettingCreateController::execQueryDepart(const PageQuery::Wrapper& userquery, const PayloadDTO& payload)
{
	return {};
}

MettingMemebrPageJsonVO::Wrapper MettingCreateController::execQueryMember(const PageQuery::Wrapper& userquery, const PayloadDTO& payload)
{
	return {};
}
