#include "stdafx.h"
#include "AddCelMeetingService.h"
#include "../../domain/dto/Meeting/MeetingDTO.h"



StringJsonVO::Wrapper AddCelMeetingService::addMeeting(const MeetingDTO::Wrapper& dto) {

    auto jvo = StringJsonVO::createShared();
    
    MeetingDO data;
    MeetingDAO dao;

    //错误判断,检查是否有字段缺失
    bool flag = 0;
    VALIDATE_MEETING_DTO(dto, flag, jvo);
    if (flag == 0) {
        return jvo;
    }
    if (!dao.checkMeetingTimeConflict(dto->startTime, dto->completedTime, dto->room)) {
        jvo->fail(ZH_WORDS_GETTER("jvo.meetingtime.fail"));
        return jvo;
    }
    

    //DTO转DO模型
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
    
    //设置参会人员
    std::list<std::string> stdParticipants;
    for (const auto& participant : *dto->participants) 
        stdParticipants.push_back(participant.getValue(""));
    data.setParticipants(stdParticipants);
    
    //设置时间和雪花id参数和序列号
    setparam(data);


    
    if (dao.addMeeting(data)) {
        jvo->data = "success"; // 返回成功消息
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
        jvo->data = "success"; // 返回成功消息
    }
    else {
        jvo->data = "error";
    }

    return jvo;

}

bool AddCelMeetingService::setparam(MeetingDO& data) {
    try {
        //设置时间
        string currenttime = SimpleDateTimeFormat::format();
        data.setCreateTime(currenttime);
        data.setUpdateTime(currenttime);

        //设置雪花id
        SnowFlake sf(1, 1);
        string uuid = std::to_string(sf.nextId());
        data.setId(uuid);

        //设置序列号
        string seq = MeetingDAO::convertDate(currenttime) + uuid;
        data.setSequence(seq);
        return true;
    }
    catch (const std::exception& e) {
        std::cerr << "设置参数时发生异常: " << e.what() << std::endl;
        return false; // 返回失败
    }

}

