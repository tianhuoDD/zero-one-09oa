#pragma once
#ifndef _MEETINGDTO_H_
#define _MEETINGDTO_H_

#include "../../GlobalInclude.h"
#include"SimpleDateTimeFormat.h"
#include OATPP_CODEGEN_BEGIN(DTO)

//辅助函数
#define CREATE_ERROR_RESPONSE(error,jvo) \
    do{\
        jvo->data = error;\
    }while(0)


// 用来从上到下判断检查某一字段是否缺失并返回缺失字段信息
#define VALIDATE_MEETING_DTO(dto, flag, jvo) \
    do { \
        if (dto->meetingtype.getValue("") == "") CREATE_ERROR_RESPONSE("Meeting type cannot be empty",jvo); \
        else if (dto->startTime.getValue("") == "")  CREATE_ERROR_RESPONSE("Start time cannot be empty",jvo); \
        else if (dto->completedTime.getValue("") == "")CREATE_ERROR_RESPONSE("Completed time cannot be empty",jvo); \
        else if (dto->room.getValue("") == "") CREATE_ERROR_RESPONSE("Meeting room ID cannot be empty", jvo); \
        else if (dto->hostunit.getValue("") == "")  CREATE_ERROR_RESPONSE("Host unit cannot be empty", jvo); \
        else if (dto->applicant.getValue("") == "")  CREATE_ERROR_RESPONSE("xapplicant cannot be empty", jvo); \
        else if (dto->subject.getValue("") == "")  CREATE_ERROR_RESPONSE("Subject cannot be empty", jvo); \
        else if (dto->hostperson.getValue("") == "")  CREATE_ERROR_RESPONSE("hostperson cannot be empty", jvo); \
        else if (dto->participants->size() == 0)  CREATE_ERROR_RESPONSE("participants cannot be empty", jvo); \
        else if (dto->summary.getValue("") == "") CREATE_ERROR_RESPONSE("Summary cannot be empty", jvo); \
        else flag = 1; \
    } while (0)

class MeetingDTO : public oatpp::DTO {
    DTO_INIT(MeetingDTO, DTO);

    // 会议ID
    //API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("meeting.field.id")); // 对应 MeetingDO 中的 xid

    // 会议类型
    API_DTO_FIELD_DEFAULT(String, meetingtype, ZH_WORDS_GETTER("meeting.field.meetingtype")); // 对应 MeetingDO 中的 xtype


    //API_DTO_FIELD_DEFAULT(String, sequence, ZH_WORDS_GETTER("meeting.field.sequence")); // 对应 MeetingDO 中的 sequence


    // 开始时间
    API_DTO_FIELD_DEFAULT(String, startTime, ZH_WORDS_GETTER("meeting.field.startTime")); // 对应 MeetingDO 中的 xstartTime

    // 完成时间
    API_DTO_FIELD_DEFAULT(String, completedTime, ZH_WORDS_GETTER("meeting.field.completedTime")); // 对应 MeetingDO 中的 xcompletedTime

    //申请人
    API_DTO_FIELD_DEFAULT(String, applicant, ZH_WORDS_GETTER("meeting.field.roomId")); // 对应 MeetingDO 中的 xapplicant
    
    //主持人
    API_DTO_FIELD_DEFAULT(String, hostperson, ZH_WORDS_GETTER("meeting.field.hostperson")); // 对应 MeetingDO 中的 xhostperson

    //参与人
    API_DTO_FIELD_DEFAULT(List<String>, participants, ZH_WORDS_GETTER("meeting.field.participantS")); // 对应 MeetingDO 中的 participant

    // 会议室ID
    API_DTO_FIELD_DEFAULT(String, room, ZH_WORDS_GETTER("meeting.field.roomId")); // 对应 MeetingDO 中的 xroomId

    // 主办单位
    API_DTO_FIELD_DEFAULT(String, hostunit, ZH_WORDS_GETTER("meeting.field.hostunit")); // 对应 MeetingDO 中的 hostunit

    // 主题
    API_DTO_FIELD_DEFAULT(String, subject, ZH_WORDS_GETTER("meeting.field.subject")); // 对应 MeetingDO 中的 xsubject

    // 描述
    API_DTO_FIELD_DEFAULT(String, summary, ZH_WORDS_GETTER("meeting.field.summary")); // 对应 MeetingDO 中的 xsummary

};

#include OATPP_CODEGEN_END(DTO)




#endif // !MeetingDTO