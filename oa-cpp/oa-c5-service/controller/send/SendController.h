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

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class SendController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
    // 2 定义控制器访问入口
    API_ACCESS_DECLARE(SendController);

public:
    // 3.1 定义发送邮箱接口描述
    ENDPOINT_INFO(sendMail) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("send.post.mail"));
        // 定义默认授权参数
        API_DEF_ADD_AUTH();
        API_DEF_ADD_QUERY_PARAMS(String, "phone", ZH_WORDS_GETTER("send.field.phone"), "12345678900", false);
        API_DEF_ADD_QUERY_PARAMS(String, "mail", ZH_WORDS_GETTER("send.field.mail"), "111@123.com", false);
        API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("send.field.type"), ZH_WORDS_GETTER("send.typename.massage"), true);
        API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("send.field.code"), "000000", true);
    }

    // 3.2 定义发送消息接口处理
    ENDPOINT(API_M_POST, "/massage-service/sendmail", sendMail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(userQuery, SendQuery, queryParams);
        // 调用执行函数响应结果
        API_HANDLER_RESP_VO(execSendMail(userQuery,authObject->getPayload()));
    }

    // 3.1 定义发送短信接口描述
    ENDPOINT_INFO(sendMessage) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("send.post.message"));
        // 定义默认授权参数
        API_DEF_ADD_RSP_JSON(SendJsonVO::Wrapper);
        API_DEF_ADD_AUTH();
        /*   API_DEF_ADD_QUERY_PARAMS(String, "phone", ZH_WORDS_GETTER("send.field.phone"), "18972019068", false);
           API_DEF_ADD_QUERY_PARAMS(String, "mail", ZH_WORDS_GETTER("send.field.mail"), "111@123.com", false);
           API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("send.field.type"), ZH_WORDS_GETTER("send.typename.massage"), true);
           API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("send.field.code"), "000000", true);
      */
    }

    // 3.2 定义发送短信接口处理
    ENDPOINT(API_M_POST, "/massage-service/sendmessage", sendMessage, BODY_DTO(SendDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // 校验传入参数
        if (dto->type->empty() || dto->code->empty()) {
            return createResponse(Status::CODE_400, "Type and code must not be empty.");
        }
        // 调用执行函数响应结果
        API_HANDLER_RESP_VO(execSendMessage(dto));
    }

private:
    // 3.3 执行发送邮箱的具体逻辑
    StringJsonVO::Wrapper execSendMail(const SendQuery::Wrapper& query, const PayloadDTO& payload);

    // 3.3 执行发送消息的具体逻辑
    SendJsonVO::Wrapper execSendMessage(const SendDTO::Wrapper& dto);
    bool validatePhoneNumber(const std::string& phoneNumber);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_