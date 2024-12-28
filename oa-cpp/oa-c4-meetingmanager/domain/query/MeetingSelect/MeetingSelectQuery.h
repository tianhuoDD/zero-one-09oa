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
 * 会议选择查询对象
 * 包含用于过滤的状态（status）和类型（type）字段
 */
class MeetingSelectQuery : public PageQuery
{
    DTO_INIT(MeetingSelectQuery, PageQuery);

    // 会议编号
    DTO_FIELD(String, id);
    DTO_FIELD_INFO(id) {
        info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.id");
    }

    // 申请人
    DTO_FIELD(String, applicant);
    DTO_FIELD_INFO(applicant) {
        info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.applicant");
    }

    // 日期
    DTO_FIELD(String, date); // 推荐改为 oatpp::DateTime 类型
    DTO_FIELD_INFO(date) {
        info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.date");
    }

    // 时间
    DTO_FIELD(String, time); // 推荐改为 oatpp::Time 类型
    DTO_FIELD_INFO(time) {
        info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.time");
    }

    // 会议标题
    DTO_FIELD(String, title);
    DTO_FIELD_INFO(title) {
        info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.title");
    }

    // 会议室
    DTO_FIELD(String, meetingRoom);
    DTO_FIELD_INFO(meetingRoom) {
        info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.meetingRoom");
    }

    // 会议状态（a: 未开始, b: 进行中, c: 已结束）
    DTO_FIELD(String, status);
    DTO_FIELD_INFO(status) {
        info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.status");
        // 示例值："a" 对应"未开始"
    }

    // 会议类型（1: 申请, 2: 邀请）
    DTO_FIELD(String, type);
    DTO_FIELD_INFO(type) {
        info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.type");
        // 示例值：1 对应"申请"
    }

    // 分页字段
    DTO_FIELD(oatpp::UInt64, page);
    DTO_FIELD(oatpp::UInt64, pageSize);

    // 月份字段，用于按月份过滤
    DTO_FIELD(oatpp::String, month);
    DTO_FIELD_INFO(month) {
        info->description = "指定月份，格式为 'YYYY-MM'";
    }
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MEETINGSELECT_QUERY_
