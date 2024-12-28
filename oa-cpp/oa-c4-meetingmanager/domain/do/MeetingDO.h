#pragma once

#ifndef MEETINGDO_H
#define MEETINGDO_H
#include "DoInclude.h"
#include"SimpleDateTimeFormat.h"
#include "../dto/Meeting/MeetingDTO.h"

class MeetingDO {

private:
    CC_SYNTHESIZE(string, xid, Id);                         // ����ID
    CC_SYNTHESIZE(string, xtype, Type);                     // ��������
    CC_SYNTHESIZE(string, xsequence, Sequence);                     // ��������
    CC_SYNTHESIZE(string, xcreateTime, CreateTime);        // ����ʱ��
    CC_SYNTHESIZE(string, xupdateTime, UpdateTime);        // ����ʱ��
    CC_SYNTHESIZE(string, xstartTime, StartTime);          // ��ʼʱ��
    CC_SYNTHESIZE(string, xcompletedTime, CompletedTime);   // ���ʱ��
    CC_SYNTHESIZE(string, xroom, Room);                 // ������ID
    CC_SYNTHESIZE(string, xhostPerson, HostPerson);          // ������
    CC_SYNTHESIZE(string, xhostunit, HostUnit);             // ���쵥λ
    CC_SYNTHESIZE(list<string>, xparticipants, Participants);             // ���쵥λ
    CC_SYNTHESIZE(string, xapplicant, Applicant);         // ������
    CC_SYNTHESIZE(string, xsubject, Subject);               // ����
    CC_SYNTHESIZE(string, xsummary, Summary);       // ����

public:
    MeetingDO() = default;
    ~MeetingDO() = default;
};




#endif