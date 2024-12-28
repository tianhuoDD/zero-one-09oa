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
 * ������ѡ���ѯ����
 */
class MeetingRoomSelectQuery : public PageQuery
{
    DTO_INIT(MeetingRoomSelectQuery, PageQuery);

    // �����ұ��
    DTO_FIELD(UInt64, meetingRoomId);
    DTO_FIELD_INFO(meetingRoomId) {
        info->description = ZH_WORDS_GETTER("meetingmanager.field.meetingRoomId");
    }

    // ����������
    DTO_FIELD(String, meetingRoomName);
    DTO_FIELD_INFO(meetingRoomName) {
        info->description = ZH_WORDS_GETTER("meetingmanager.field.meetingRoomName");
    }

    //// ������λ��
    //DTO_FIELD(MeetingRoomLocationDTO::Wrapper, location);
    //DTO_FIELD_INFO(location) {
    //    info->description = ZH_WORDS_GETTER("meetingmanager.field.location");
    //}

    // Ԥ������ʱ��
    DTO_FIELD(String, scheduledDateTime);
    DTO_FIELD_INFO(scheduledDateTime) {
        info->description = ZH_WORDS_GETTER("meetingmanager.field.scheduledDateTime");
    }

    // ����ʱ�䣨Сʱ��
    DTO_FIELD(UInt32, durationHours);
    DTO_FIELD_INFO(durationHours) {
        info->description = ZH_WORDS_GETTER("meetingmanager.field.durationHours");
    }

    // ����ʱ�䣨���ӣ�
    DTO_FIELD(UInt32, durationMinutes);
    DTO_FIELD_INFO(durationMinutes) {
        info->description = ZH_WORDS_GETTER("meetingmanager.field.durationMinutes");
    }

    // ¥��ID�����ڰ�IDɸѡ
    DTO_FIELD(UInt64, locationId);
    DTO_FIELD_INFO(locationId) {
        info->description = ZH_WORDS_GETTER("meetingmanager.field.locationId");
    }

    // ¥�����ƣ����ڰ�����ɸѡ
    DTO_FIELD(String, locationName);
    DTO_FIELD_INFO(locationName) {
        info->description = ZH_WORDS_GETTER("meetingmanager.field.locationName");
    }
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_MEETINGROOM_SELECT_QUERY_