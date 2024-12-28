#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _MEETINGROOMSELECT_DO_
#define _MEETINGROOMSELECT_DO_
#include "../DoInclude.h"

/**
 * MeetingRoomSelectDO - 会议室选择的领域对象 (DO)
 */
class MeetingRoomSelectDO
{
    // 会议室编号
    CC_SYNTHESIZE(uint64_t, roomId, RoomId);

    // 会议室名称
    CC_SYNTHESIZE(std::string, roomName, RoomName);

    //// 会议室位置
    //CC_SYNTHESIZE(std::string, location, Location);

    // 计划会议时间
    CC_SYNTHESIZE(std::string, scheduledDateTime, ScheduledDateTime);

    // 会议持续小时数
    CC_SYNTHESIZE(uint32_t, durationHours, DurationHours);

    // 会议持续分钟数
    CC_SYNTHESIZE(uint32_t, durationMinutes, DurationMinutes);

    // 可容纳人数
    CC_SYNTHESIZE(int, capacity, Capacity);

    // 是否可用
    CC_SYNTHESIZE(bool, isAvailable, IsAvailable);

    // 编号
    CC_SYNTHESIZE(uint64_t, locationId, LocationId);

    // 姓名
    CC_SYNTHESIZE(string, locationName, LocationName);

public:
    // 构造函数：初始化字段为默认值
    MeetingRoomSelectDO() {
        roomId = 0;
        roomName = "";
        //location = "";
        scheduledDateTime = "";
        durationHours = 0;
        durationMinutes = 0;
        capacity = 0;
        isAvailable = true;  // 默认可用
        locationId = 1;
        locationName = "1";
    }
};

#endif // _MEETINGROOMSELECT_DO_
