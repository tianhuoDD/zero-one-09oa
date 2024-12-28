#pragma once


#ifndef _CANCELMEETINGCONTROLLER_H_
#define _CANCELMEETINGCONTROLLER_H_
#include"domain/dto/Meeting/MeetingDTO.h"
#include "domain/vo/Meeting/MeetingVO.h"
#include "domain/vo/BaseJsonVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class  CancelMeetingController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{

    API_ACCESS_DECLARE(CancelMeetingController);
public://����ӿ�
    //���������ӿ�
    ENDPOINT_INFO(CancelMeeting) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("meeting.cancel.summary"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(MeetingVOJsonVO);
    }
    // 3.2 ���������ӿڴ���
    ENDPOINT(API_M_DEL, "/meeting/cancel/{id}", CancelMeeting, PATH(String, id), API_HANDLER_AUTH_PARAME) {    //����id
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execCancelMeeting(id));
    }
private: // ����ӿ�ִ�к���
    // ȡ������ִ�к���
    StringJsonVO::Wrapper execCancelMeeting(const string& id);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_ADDMEETINGCONTROLLER_H_