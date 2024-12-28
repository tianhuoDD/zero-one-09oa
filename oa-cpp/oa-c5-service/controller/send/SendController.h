#pragma once
#ifndef _SENDCONTROLLER_H_
#define _SENDCONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/send/sendDTO.h"
#include "domain/vo/send/SendVO.h"
#include "../../domain/query/SendQuery.h"
#include "domain/dto/send/sendDTO.h"
#include "domain/vo/send/SendVO.h"
#include <regex>
#include <string>
#include "service/send/SendMessageService.h"
#include <iostream>

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class SendController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
    // 2 ����������������
    API_ACCESS_DECLARE(SendController);

public:
    // 3.1 ���巢������ӿ�����
    ENDPOINT_INFO(sendMail) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("send.post.mail"));
        // ����Ĭ����Ȩ����
        API_DEF_ADD_AUTH();
        API_DEF_ADD_QUERY_PARAMS(String, "phone", ZH_WORDS_GETTER("send.field.phone"), "12345678900", false);
        API_DEF_ADD_QUERY_PARAMS(String, "mail", ZH_WORDS_GETTER("send.field.mail"), "111@123.com", false);
        API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("send.field.type"), ZH_WORDS_GETTER("send.typename.massage"), true);
        API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("send.field.code"), "000000", true);
    }

    // 3.2 ���巢����Ϣ�ӿڴ���
    ENDPOINT(API_M_POST, "/massage-service/sendmail", sendMail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(userQuery, SendQuery, queryParams);
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execSendMail(userQuery,authObject->getPayload()));
    }

    // 3.1 ���巢�Ͷ��Žӿ�����
    ENDPOINT_INFO(sendMessage) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("send.post.message"));
        // ����Ĭ����Ȩ����
        API_DEF_ADD_RSP_JSON(SendJsonVO::Wrapper);
        API_DEF_ADD_AUTH();
        /*   API_DEF_ADD_QUERY_PARAMS(String, "phone", ZH_WORDS_GETTER("send.field.phone"), "18972019068", false);
           API_DEF_ADD_QUERY_PARAMS(String, "mail", ZH_WORDS_GETTER("send.field.mail"), "111@123.com", false);
           API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("send.field.type"), ZH_WORDS_GETTER("send.typename.massage"), true);
           API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("send.field.code"), "000000", true);
      */
    }

    // 3.2 ���巢�Ͷ��Žӿڴ���
    ENDPOINT(API_M_POST, "/massage-service/sendmessage", sendMessage, BODY_DTO(SendDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // У�鴫�����
        if (dto->type->empty() || dto->code->empty()) {
            return createResponse(Status::CODE_400, "Type and code must not be empty.");
        }
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execSendMessage(dto));
    }

private:
    // 3.3 ִ�з�������ľ����߼�
    StringJsonVO::Wrapper execSendMail(const SendQuery::Wrapper& query, const PayloadDTO& payload);

    // 3.3 ִ�з�����Ϣ�ľ����߼�
    SendJsonVO::Wrapper execSendMessage(const SendDTO::Wrapper& dto);
    bool validatePhoneNumber(const std::string& phoneNumber);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_