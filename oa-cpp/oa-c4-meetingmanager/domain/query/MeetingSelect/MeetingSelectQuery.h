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

#ifndef _MEETINGSELECT_QUERY_
#define _MEETINGSELECT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����ѡ���ѯ����
 * �������ڹ��˵�״̬��status�������ͣ�type���ֶ�
 */
class MeetingSelectQuery : public PageQuery
{
    DTO_INIT(MeetingSelectQuery, PageQuery);

    // ������
    DTO_FIELD(String, id);
    DTO_FIELD_INFO(id) {
        info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.id");
    }

    // ������
    DTO_FIELD(String, applicant);
    DTO_FIELD_INFO(applicant) {
        info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.applicant");
    }

    // ����
    DTO_FIELD(String, date); // �Ƽ���Ϊ oatpp::DateTime ����
    DTO_FIELD_INFO(date) {
        info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.date");
    }

    // ʱ��
    DTO_FIELD(String, time); // �Ƽ���Ϊ oatpp::Time ����
    DTO_FIELD_INFO(time) {
        info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.time");
    }

    // �������
    DTO_FIELD(String, title);
    DTO_FIELD_INFO(title) {
        info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.title");
    }

    // ������
    DTO_FIELD(String, meetingRoom);
    DTO_FIELD_INFO(meetingRoom) {
        info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.meetingRoom");
    }

    // ����״̬��a: δ��ʼ, b: ������, c: �ѽ�����
    DTO_FIELD(String, status);
    DTO_FIELD_INFO(status) {
        info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.status");
        // ʾ��ֵ��"a" ��Ӧ"δ��ʼ"
    }

    // �������ͣ�1: ����, 2: ���룩
    DTO_FIELD(String, type);
    DTO_FIELD_INFO(type) {
        info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.type");
        // ʾ��ֵ��1 ��Ӧ"����"
    }

    // ��ҳ�ֶ�
    DTO_FIELD(oatpp::UInt64, page);
    DTO_FIELD(oatpp::UInt64, pageSize);

    // �·��ֶΣ����ڰ��·ݹ���
    DTO_FIELD(oatpp::String, month);
    DTO_FIELD_INFO(month) {
        info->description = "ָ���·ݣ���ʽΪ 'YYYY-MM'";
    }
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MEETINGSELECT_QUERY_
