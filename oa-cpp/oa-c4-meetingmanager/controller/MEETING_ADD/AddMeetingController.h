#pragma once


#ifndef _ADDMEETINGCONTROLLER_H_
#define _ADDMEETINGCONTROLLER_H_
//#include "domain/vo/grouplist/GroupListVO.h"
#include"domain/dto/Meeting/MeetingDTO.h"
#include "domain/vo/Meeting/MeetingVO.h"
#include "domain/vo/BaseJsonVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class  AddMeetingController : public oatpp::web::server::api::ApiController // 1 继承控制器
{

    API_ACCESS_DECLARE(AddMeetingController);
public://定义接口
    //定义新增接口
    ENDPOINT_INFO(addMeeting) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("meeting.add.summary"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(MeetingVOJsonVO);
    }
    // 3.2 定义新增接口处理
    ENDPOINT(API_M_POST, "/meeting/add", addMeeting, BODY_DTO(MeetingDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execAddMeeting(dto));
    }
private: // 定义接口执行函数
    // 新增会议执行函数
    StringJsonVO::Wrapper execAddMeeting(const MeetingDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_ADDMEETINGCONTROLLER_H_