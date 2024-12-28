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
 * MeetingRoomSelectDO - ������ѡ���������� (DO)
 */
class MeetingRoomSelectDO
{
    // �����ұ��
    CC_SYNTHESIZE(uint64_t, roomId, RoomId);

    // ����������
    CC_SYNTHESIZE(std::string, roomName, RoomName);

    //// ������λ��
    //CC_SYNTHESIZE(std::string, location, Location);

    // �ƻ�����ʱ��
    CC_SYNTHESIZE(std::string, scheduledDateTime, ScheduledDateTime);

    // �������Сʱ��
    CC_SYNTHESIZE(uint32_t, durationHours, DurationHours);

    // �������������
    CC_SYNTHESIZE(uint32_t, durationMinutes, DurationMinutes);

    // ����������
    CC_SYNTHESIZE(int, capacity, Capacity);

    // �Ƿ����
    CC_SYNTHESIZE(bool, isAvailable, IsAvailable);

    // ���
    CC_SYNTHESIZE(uint64_t, locationId, LocationId);

    // ����
    CC_SYNTHESIZE(string, locationName, LocationName);

public:
    // ���캯������ʼ���ֶ�ΪĬ��ֵ
    MeetingRoomSelectDO() {
        roomId = 0;
        roomName = "";
        //location = "";
        scheduledDateTime = "";
        durationHours = 0;
        durationMinutes = 0;
        capacity = 0;
        isAvailable = true;  // Ĭ�Ͽ���
        locationId = 1;
        locationName = "1";
    }
};

#endif // _MEETINGROOMSELECT_DO_
