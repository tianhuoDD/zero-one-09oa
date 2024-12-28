#pragma once
#ifndef ADDMEETING_H
#define ADDMEETING_H


#include"domain/dto/Meeting/MeetingDTO.h"
#include "domain/vo/Meeting/MeetingVO.h"
#include "domain/vo/BaseJsonVO.h"
#include "SnowFlake.h"
#include "../../domain/do/MeetingDO.h"
#include "../../dao/MeetingDAO.h"



class AddCelMeetingService {
public:
    // 新增会议
    StringJsonVO::Wrapper addMeeting(const MeetingDTO::Wrapper& dto);
    //取消会议
    StringJsonVO::Wrapper celMeeting(string id);

    //设置参数
    bool setparam(MeetingDO& data);

    
};

#endif