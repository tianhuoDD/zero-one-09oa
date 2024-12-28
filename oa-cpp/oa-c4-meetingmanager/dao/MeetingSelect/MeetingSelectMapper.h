#pragma once
#ifndef _MEETINGSELECT_MAPPER_
#define _MEETINGSELECT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/MeetingSelect/MeetingSelectDO.h"

/**
 * 会议选择表字段匹配映射
 */
class MeetingSelectMapper : public Mapper<MeetingSelectDO>
{
public:
    // 从 ResultSet 映射到 MeetingSelectDO
    MeetingSelectDO mapper(ResultSet* resultSet) const override
    {
        MeetingSelectDO data;

        // 映射会议编号 (Id)
        data.setId(resultSet->getString(1)); // 假设在 ResultSet 中，Id 是第一列

        // 映射申请人 (Applicant)
        data.setApplicant(resultSet->getString(2)); // 假设在 ResultSet 中，Applicant 是第二列

        //// 映射日期 (Date)
        //data.setDate(resultSet->getString(3)); // 假设在 ResultSet 中，Date 是第三列

        // 映射时间 (Time)
        data.setTime(resultSet->getString(3)); // 假设在 ResultSet 中，Time 是第四列

        // 映射会议标题 (Title)
        data.setTitle(resultSet->getString(4)); // 假设在 ResultSet 中，Title 是第五列

        // 映射会议室名称 (MeetingRoom)
        data.setMeetingRoom(resultSet->getString(5)); // 假设在 ResultSet 中，MeetingRoom 是第六列

        //// 映射会议类型 (Type)
        //data.setType(resultSet->getUInt64(6)); // 假设在 ResultSet 中，Type 是第七列

        //// 映射会议状态 (StatuS)
        //data.setStatuS(resultSet->getString(7)); // 假设在 ResultSet 中，StatuS 是第八列

        return data; // 返回映射后的 MeetingSelectDO 对象
    }
};

#endif // !_MEETINGSELECT_MAPPER_