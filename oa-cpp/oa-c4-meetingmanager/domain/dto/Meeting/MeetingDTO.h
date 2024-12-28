#pragma once
#ifndef _MEETINGDTO_H_
#define _MEETINGDTO_H_

#include "../../GlobalInclude.h"
#include"SimpleDateTimeFormat.h"
#include OATPP_CODEGEN_BEGIN(DTO)

//��������
#define CREATE_ERROR_RESPONSE(error,jvo) \
    do{\
        jvo->data = error;\
    }while(0)


// �������ϵ����жϼ��ĳһ�ֶ��Ƿ�ȱʧ������ȱʧ�ֶ���Ϣ
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

    // ����ID
    //API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("meeting.field.id")); // ��Ӧ MeetingDO �е� xid

    // ��������
    API_DTO_FIELD_DEFAULT(String, meetingtype, ZH_WORDS_GETTER("meeting.field.meetingtype")); // ��Ӧ MeetingDO �е� xtype


    //API_DTO_FIELD_DEFAULT(String, sequence, ZH_WORDS_GETTER("meeting.field.sequence")); // ��Ӧ MeetingDO �е� sequence


    // ��ʼʱ��
    API_DTO_FIELD_DEFAULT(String, startTime, ZH_WORDS_GETTER("meeting.field.startTime")); // ��Ӧ MeetingDO �е� xstartTime

    // ���ʱ��
    API_DTO_FIELD_DEFAULT(String, completedTime, ZH_WORDS_GETTER("meeting.field.completedTime")); // ��Ӧ MeetingDO �е� xcompletedTime

    //������
    API_DTO_FIELD_DEFAULT(String, applicant, ZH_WORDS_GETTER("meeting.field.roomId")); // ��Ӧ MeetingDO �е� xapplicant
    
    //������
    API_DTO_FIELD_DEFAULT(String, hostperson, ZH_WORDS_GETTER("meeting.field.hostperson")); // ��Ӧ MeetingDO �е� xhostperson

    //������
    API_DTO_FIELD_DEFAULT(List<String>, participants, ZH_WORDS_GETTER("meeting.field.participantS")); // ��Ӧ MeetingDO �е� participant

    // ������ID
    API_DTO_FIELD_DEFAULT(String, room, ZH_WORDS_GETTER("meeting.field.roomId")); // ��Ӧ MeetingDO �е� xroomId

    // ���쵥λ
    API_DTO_FIELD_DEFAULT(String, hostunit, ZH_WORDS_GETTER("meeting.field.hostunit")); // ��Ӧ MeetingDO �е� hostunit

    // ����
    API_DTO_FIELD_DEFAULT(String, subject, ZH_WORDS_GETTER("meeting.field.subject")); // ��Ӧ MeetingDO �е� xsubject

    // ����
    API_DTO_FIELD_DEFAULT(String, summary, ZH_WORDS_GETTER("meeting.field.summary")); // ��Ӧ MeetingDO �е� xsummary

};

#include OATPP_CODEGEN_END(DTO)




#endif // !MeetingDTO