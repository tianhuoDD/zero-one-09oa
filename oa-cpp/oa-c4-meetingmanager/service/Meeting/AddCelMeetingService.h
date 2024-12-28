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
    // ��������
    StringJsonVO::Wrapper addMeeting(const MeetingDTO::Wrapper& dto);
    //ȡ������
    StringJsonVO::Wrapper celMeeting(string id);

    //���ò���
    bool setparam(MeetingDO& data);

    
};

#endif