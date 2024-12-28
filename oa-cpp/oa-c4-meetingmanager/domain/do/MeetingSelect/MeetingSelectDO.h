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
 * MeetingSelectDO - 会议选择的领域对象 (DO)
 */
class MeetingSelectDO
{
    // 会议编号
    CC_SYNTHESIZE(std::string, id, Id);

    // 申请人
    CC_SYNTHESIZE(std::string, applicant, Applicant);

    //// 日期（格式：YYYY-MM-DD）
    //CC_SYNTHESIZE(std::string, date, Date);

    // 时间（格式：HH:MM）
    CC_SYNTHESIZE(std::string, time, Time);

    // 会议标题
    CC_SYNTHESIZE(std::string, title, Title);

    // 会议室名称
    CC_SYNTHESIZE(std::string, meetingRoom, MeetingRoom);

    CC_SYNTHESIZE(std::string, type, Type);

    CC_SYNTHESIZE(std::string, status, StatuS);

public:
    // 默认构造函数：初始化字段为默认值
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
