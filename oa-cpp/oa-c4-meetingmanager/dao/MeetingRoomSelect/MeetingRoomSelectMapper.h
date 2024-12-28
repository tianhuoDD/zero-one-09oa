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
 * ������ѡ����ֶ�ƥ��ӳ��
 */
class MeetingRoomSelectMapper : public Mapper<MeetingRoomSelectDO>
{
public:
    // �� ResultSet ӳ�䵽 MeetingRoomSelectDO
    MeetingRoomSelectDO mapper(ResultSet* resultSet) const override
    {
        MeetingRoomSelectDO data;

        // ӳ������ұ�� (RoomId)
        data.setRoomId(resultSet->getUInt64(1)); // ������ ResultSet �У�RoomId �ǵ�һ��

        // ӳ����������� (RoomName)
        data.setRoomName(resultSet->getString(2)); // ������ ResultSet �У�RoomName �ǵڶ���

        // ӳ����������� (Capacity)
        data.setCapacity(resultSet->getInt(3)); // ������ ResultSet �У�Capacity �ǵ�����

        // ӳ���Ƿ���� (IsAvailable)
        data.setIsAvailable(resultSet->getBoolean(4)); // ������ ResultSet �У�IsAvailable �ǵ�����

        return data; // ����ӳ���� MeetingRoomSelectDO ����
    }

    
};
#endif // !_MEETINGROOMSELECT_MAPPER_
