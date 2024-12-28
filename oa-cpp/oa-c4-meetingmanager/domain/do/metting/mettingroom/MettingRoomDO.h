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
#ifndef _MettingRoom_DO_
#define _MettingRoom_DO_
#include "../../DoInclude.h"

/**
 * 示例数据库实体类
 */
class MettingRoomDO
{
	// 编号
	CC_SYNTHESIZE(string,	id		, Ids);
	// name
	CC_SYNTHESIZE(string, name, Names);
	// build
	CC_SYNTHESIZE(string,	build	, Build);
	// floor
	CC_SYNTHESIZE(int, floor	, Floor);
	// capacity
	CC_SYNTHESIZE(int, capacity, capacity);
	// roomnumber
	CC_SYNTHESIZE(string,	roomnumber, Roomnumber);
	// dis
	CC_SYNTHESIZE(int, dis		, Dis);
	// device
	CC_SYNTHESIZE(string,	device	, Device);
	// status
	CC_SYNTHESIZE(bool,		available, Available);
public:
	MettingRoomDO() {
		id = "";

		name = "";

		build = "";

		floor = 1;

		capacity = 50;

		roomnumber = "";

		dis = 0;

		device = "";

		available = true;
	}
};

class MettingBuildDO {
	// build
	CC_SYNTHESIZE(string, build, Build);
public:
	MettingBuildDO() {
		build = "";
	}
};

#endif // !_MettingRoom_DO_
