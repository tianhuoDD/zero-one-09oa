#pragma once
#ifndef _MEETINGSELECT_MAPPER_
#define _MEETINGSELECT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/MeetingSelect/MeetingSelectDO.h"

/**
 * ����ѡ����ֶ�ƥ��ӳ��
 */
class MeetingSelectMapper : public Mapper<MeetingSelectDO>
{
public:
    // �� ResultSet ӳ�䵽 MeetingSelectDO
    MeetingSelectDO mapper(ResultSet* resultSet) const override
    {
        MeetingSelectDO data;

        // ӳ������� (Id)
        data.setId(resultSet->getString(1)); // ������ ResultSet �У�Id �ǵ�һ��

        // ӳ�������� (Applicant)
        data.setApplicant(resultSet->getString(2)); // ������ ResultSet �У�Applicant �ǵڶ���

        //// ӳ������ (Date)
        //data.setDate(resultSet->getString(3)); // ������ ResultSet �У�Date �ǵ�����

        // ӳ��ʱ�� (Time)
        data.setTime(resultSet->getString(3)); // ������ ResultSet �У�Time �ǵ�����

        // ӳ�������� (Title)
        data.setTitle(resultSet->getString(4)); // ������ ResultSet �У�Title �ǵ�����

        // ӳ����������� (MeetingRoom)
        data.setMeetingRoom(resultSet->getString(5)); // ������ ResultSet �У�MeetingRoom �ǵ�����

        //// ӳ��������� (Type)
        //data.setType(resultSet->getUInt64(6)); // ������ ResultSet �У�Type �ǵ�����

        //// ӳ�����״̬ (StatuS)
        //data.setStatuS(resultSet->getString(7)); // ������ ResultSet �У�StatuS �ǵڰ���

        return data; // ����ӳ���� MeetingSelectDO ����
    }
};

#endif // !_MEETINGSELECT_MAPPER_