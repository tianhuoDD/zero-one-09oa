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
#ifndef _MEETINGSELECT_DO_
#define _MEETINGSELECT_DO_
#include "../DoInclude.h"

/**
 * MeetingSelectDO - ����ѡ���������� (DO)
 */
class MeetingSelectDO
{
    // ������
    CC_SYNTHESIZE(std::string, id, Id);

    // ������
    CC_SYNTHESIZE(std::string, applicant, Applicant);

    //// ���ڣ���ʽ��YYYY-MM-DD��
    //CC_SYNTHESIZE(std::string, date, Date);

    // ʱ�䣨��ʽ��HH:MM��
    CC_SYNTHESIZE(std::string, time, Time);

    // �������
    CC_SYNTHESIZE(std::string, title, Title);

    // ����������
    CC_SYNTHESIZE(std::string, meetingRoom, MeetingRoom);

    CC_SYNTHESIZE(std::string, type, Type);

    CC_SYNTHESIZE(std::string, status, StatuS);

public:
    // Ĭ�Ϲ��캯������ʼ���ֶ�ΪĬ��ֵ
    MeetingSelectDO()
        : id(""),
        applicant(""),
        /*date(""),*/
        time(""),
        title(""),
        meetingRoom(""),
        type("1"),
        status("a")
    {}
};

#endif // _MEETINGSELECT_DO_
