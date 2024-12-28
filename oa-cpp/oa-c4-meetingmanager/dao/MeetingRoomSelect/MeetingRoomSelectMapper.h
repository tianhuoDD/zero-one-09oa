#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/23

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
#ifndef _MEETINGROOMSELECT_MAPPER_
#define _MEETINGROOMSELECT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/MeetingRoomSelect/MeetingRoomSelectDO.h"

/**
 * 会议室选择表字段匹配映射
 */
class MeetingRoomSelectMapper : public Mapper<MeetingRoomSelectDO>
{
public:
    // 从 ResultSet 映射到 MeetingRoomSelectDO
    MeetingRoomSelectDO mapper(ResultSet* resultSet) const override
    {
        MeetingRoomSelectDO data;

        // 映射会议室编号 (RoomId)
        data.setRoomId(resultSet->getUInt64(1)); // 假设在 ResultSet 中，RoomId 是第一列

        // 映射会议室名称 (RoomName)
        data.setRoomName(resultSet->getString(2)); // 假设在 ResultSet 中，RoomName 是第二列

        // 映射可容纳人数 (Capacity)
        data.setCapacity(resultSet->getInt(3)); // 假设在 ResultSet 中，Capacity 是第三列

        // 映射是否可用 (IsAvailable)
        data.setIsAvailable(resultSet->getBoolean(4)); // 假设在 ResultSet 中，IsAvailable 是第四列

        return data; // 返回映射后的 MeetingRoomSelectDO 对象
    }

    
};
#endif // !_MEETINGROOMSELECT_MAPPER_
