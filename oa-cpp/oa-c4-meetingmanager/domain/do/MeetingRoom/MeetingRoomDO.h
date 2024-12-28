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
#ifndef _MeetingRoom_DO_
#define _MeetingRoom_DO_
#include "../DoInclude.h"
//using namespace oatpp;

/**
 * 示例数据库实体类
 */
class MeetingRoomDO
{	//会议室id
	CC_SYNTHESIZE(string, id, Id);
	//会议室名称
	CC_SYNTHESIZE(string, name, Name);
	// 会议室位置
	CC_SYNTHESIZE(string, location, Location);
	// 会议室楼层
	CC_SYNTHESIZE(uint64_t, floor, Floor);
	// 会议室容纳人数
	CC_SYNTHESIZE(uint64_t, capacity, Capacity);
	// 会议室门牌
	CC_SYNTHESIZE(string, housenumber, Housenumber);
	// 会议室分机号
	CC_SYNTHESIZE(string, extnumber, Extnumber);
	// 会议室设备
	CC_SYNTHESIZE(vector<string>, device, Device);
	// 会议室状态
	CC_SYNTHESIZE(bool, status, Status);
public:
	MeetingRoomDO() :id(""),name(""), location(""), floor(0), capacity(0), housenumber(""), extnumber(""), device({}), status(0) {}
};

#endif // !_MeetingRoom_DO_
