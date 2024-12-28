#include "stdafx.h"
#include "AddCelMeetingService.h"
#include "../../domain/dto/Meeting/MeetingDTO.h"



StringJsonVO::Wrapper AddCelMeetingService::addMeeting(const MeetingDTO::Wrapper& dto) {

    auto jvo = StringJsonVO::createShared();
    
    MeetingDO data;
    MeetingDAO dao;

    //�����ж�,����Ƿ����ֶ�ȱʧ
    bool flag = 0;
    VALIDATE_MEETING_DTO(dto, flag, jvo);
    if (flag == 0) {
        return jvo;
    }
    if (!dao.checkMeetingTimeConflict(dto->startTime, dto->completedTime, dto->room)) {
        jvo->fail(ZH_WORDS_GETTER("jvo.meetingtime.fail"));
        return jvo;
    }
    

    //DTOתDOģ��
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        Type, meetingtype,
        Room, room,
        StartTime, startTime,
        CompletedTime, completedTime,
        HostUnit, hostunit,
        HostPerson, hostperson,
        Applicant, applicant,
        Subject, subject,
        Summary, summary);
    
    //���òλ���Ա
    std::list<std::string> stdParticipants;
    for (const auto& participant : *dto->participants) 
        stdParticipants.push_back(participant.getValue(""));
    data.setParticipants(stdParticipants);
    
    //����ʱ���ѩ��id���������к�
    setparam(data);


    
    if (dao.addMeeting(data)) {
        jvo->data = "success"; // ���سɹ���Ϣ
    }
    else {
        jvo->data = "error";
    }

    return jvo;
}

StringJsonVO::Wrapper AddCelMeetingService::celMeeting(string id) {
    auto jvo = StringJsonVO::createShared();

    MeetingDAO dao;
    if (dao.celMeeting(id)) {
        jvo->data = "success"; // ���سɹ���Ϣ
    }
    else {
        jvo->data = "error";
    }

    return jvo;

}

bool AddCelMeetingService::setparam(MeetingDO& data) {
    try {
        //����ʱ��
        string currenttime = SimpleDateTimeFormat::format();
        data.setCreateTime(currenttime);
        data.setUpdateTime(currenttime);

        //����ѩ��id
        SnowFlake sf(1, 1);
        string uuid = std::to_string(sf.nextId());
        data.setId(uuid);

        //�������к�
        string seq = MeetingDAO::convertDate(currenttime) + uuid;
        data.setSequence(seq);
        return true;
    }
    catch (const std::exception& e) {
        std::cerr << "���ò���ʱ�����쳣: " << e.what() << std::endl;
        return false; // ����ʧ��
    }

}

