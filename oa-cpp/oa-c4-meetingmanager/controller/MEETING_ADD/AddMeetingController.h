#pragma once


#ifndef _ADDMEETINGCONTROLLER_H_
#define _ADDMEETINGCONTROLLER_H_
//#include "domain/vo/grouplist/GroupListVO.h"
#include"domain/dto/Meeting/MeetingDTO.h"
#include "domain/vo/Meeting/MeetingVO.h"
#include "domain/vo/BaseJsonVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class  AddMeetingController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{

    API_ACCESS_DECLARE(AddMeetingController);
public://����ӿ�
    //���������ӿ�
    ENDPOINT_INFO(addMeeting) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("meeting.add.summary"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(MeetingVOJsonVO);
    }
    // 3.2 ���������ӿڴ���
    ENDPOINT(API_M_POST, "/meeting/add", addMeeting, BODY_DTO(MeetingDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execAddMeeting(dto));
    }
private: // ����ӿ�ִ�к���
    // ��������ִ�к���
    StringJsonVO::Wrapper execAddMeeting(const MeetingDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_ADDMEETINGCONTROLLER_H_