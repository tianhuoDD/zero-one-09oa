#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/25

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

#ifndef _MEETINGROOMSELECT_SERVICE_
#define _MEETINGROOMSELECT_SERVICE_

#include <list>
#include "../../domain/do/MeetingRoomSelect/MeetingRoomSelectDO.h"
#include "../../domain/query/MeetingRoomSelect/MeetingRoomQuery.h"
#include "../../domain/dto/meetingmanager/MeetingRoomSelectDTO.h"

/**
 * 会议室选择服务实现类
 */
class MeetingRoomSelectService
{
public:
    // 分页查询所有会议室数据
    MeetingRoomSelectPageDTO::Wrapper listAll(const MeetingRoomSelectQuery::Wrapper& query);

    // 保存会议室数据
    uint64_t saveData(const MeetingRoomSelectDTO::Wrapper& dto);

    // 修改会议室数据
    bool updateData(const MeetingRoomSelectDTO::Wrapper& dto);

    // 根据ID删除会议室数据
    bool removeData(uint64_t id);
};


#endif // !_MEETINGROOMSELECT_SERVICE_
