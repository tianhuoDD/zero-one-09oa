#pragma once

#ifndef MEETINGDO_H
#define MEETINGDO_H
#include "DoInclude.h"
#include"SimpleDateTimeFormat.h"
#include "../dto/Meeting/MeetingDTO.h"

class MeetingDO {

private:
    CC_SYNTHESIZE(string, xid, Id);                         // 会议ID
    CC_SYNTHESIZE(string, xtype, Type);                     // 会议类型
    CC_SYNTHESIZE(string, xsequence, Sequence);                     // 会议类型
    CC_SYNTHESIZE(string, xcreateTime, CreateTime);        // 创建时间
    CC_SYNTHESIZE(string, xupdateTime, UpdateTime);        // 更新时间
    CC_SYNTHESIZE(string, xstartTime, StartTime);          // 开始时间
    CC_SYNTHESIZE(string, xcompletedTime, CompletedTime);   // 完成时间
    CC_SYNTHESIZE(string, xroom, Room);                 // 会议室ID
    CC_SYNTHESIZE(string, xhostPerson, HostPerson);          // 主持人
    CC_SYNTHESIZE(string, xhostunit, HostUnit);             // 主办单位
    CC_SYNTHESIZE(list<string>, xparticipants, Participants);             // 主办单位
    CC_SYNTHESIZE(string, xapplicant, Applicant);         // 申请人
    CC_SYNTHESIZE(string, xsubject, Subject);               // 主题
    CC_SYNTHESIZE(string, xsummary, Summary);       // 描述

public:
    MeetingDO() = default;
    ~MeetingDO() = default;
};




#endif