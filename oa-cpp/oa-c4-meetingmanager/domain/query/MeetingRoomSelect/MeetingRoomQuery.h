#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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

#ifndef _MEETINGROOM_SELECT_QUERY_
#define _MEETINGROOM_SELECT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 会议室选择查询对象
 */
class MeetingRoomSelectQuery : public PageQuery
{
    DTO_INIT(MeetingRoomSelectQuery, PageQuery);

    // 会议室编号
    DTO_FIELD(UInt64, meetingRoomId);
    DTO_FIELD_INFO(meetingRoomId) {
        info->description = ZH_WORDS_GETTER("meetingmanager.field.meetingRoomId");
    }

    // 会议室名称
    DTO_FIELD(String, meetingRoomName);
    DTO_FIELD_INFO(meetingRoomName) {
        info->description = ZH_WORDS_GETTER("meetingmanager.field.meetingRoomName");
    }

    //// 会议室位置
    //DTO_FIELD(MeetingRoomLocationDTO::Wrapper, location);
    //DTO_FIELD_INFO(location) {
    //    info->description = ZH_WORDS_GETTER("meetingmanager.field.location");
    //}

    // 预定日期时间
    DTO_FIELD(String, scheduledDateTime);
    DTO_FIELD_INFO(scheduledDateTime) {
        info->description = ZH_WORDS_GETTER("meetingmanager.field.scheduledDateTime");
    }

    // 持续时间（小时）
    DTO_FIELD(UInt32, durationHours);
    DTO_FIELD_INFO(durationHours) {
        info->description = ZH_WORDS_GETTER("meetingmanager.field.durationHours");
    }

    // 持续时间（分钟）
    DTO_FIELD(UInt32, durationMinutes);
    DTO_FIELD_INFO(durationMinutes) {
        info->description = ZH_WORDS_GETTER("meetingmanager.field.durationMinutes");
    }

    // 楼层ID，用于按ID筛选
    DTO_FIELD(UInt64, locationId);
    DTO_FIELD_INFO(locationId) {
        info->description = ZH_WORDS_GETTER("meetingmanager.field.locationId");
    }

    // 楼层名称，用于按名称筛选
    DTO_FIELD(String, locationName);
    DTO_FIELD_INFO(locationName) {
        info->description = ZH_WORDS_GETTER("meetingmanager.field.locationName");
    }
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_MEETINGROOM_SELECT_QUERY_