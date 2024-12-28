#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _MEETINGROOMSELECT_CONTROLLER_
#define _MEETINGROOMSELECT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "././domain/vo/meetingmanager/MeetingRoomSelectVO.h"
#include "../../domain/dto/meetingmanager/MeetingRoomSelectDTO.h"
#include "../../domain/query/MeetingRoomSelect/MeetingRoomQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

//**
//会议室选择控制器
//
class MeetingRoomSelectController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(MeetingRoomSelectController);

public:
    // 获取会议室信息接口，通过 locationId 和 locationName 进行筛选或通过 meetingRoomId 查询详细信息
    ENDPOINT_INFO(getMeetingRoomInfo) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("meetingmanager.get.summary"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(LocationJsonVO);

        // 查询参数定义
        /*API_DEF_ADD_QUERY_PARAMS(UInt64, "locationId", ZH_WORDS_GETTER("meetingmanager.field.locationId"), 1, false);*/
        API_DEF_ADD_QUERY_PARAMS(String, "locationName", ZH_WORDS_GETTER("meetingmanager.field.locationName"), "1", false);
        UInt64 id_value = std::stoull("0");
        API_DEF_ADD_QUERY_PARAMS(UInt64, "meetingRoomId", ZH_WORDS_GETTER("meetingmanager.field.meetingRoomId"), id_value, false);
    }

    ENDPOINT(API_M_GET, "/meeting/meetingroom/info", getMeetingRoomInfo,
        /*QUERY(UInt64, locationId, "locationId"),*/
        QUERY(String, locationName, "locationName"),
        QUERY(UInt64, meetingRoomId, "meetingRoomId"),
        API_HANDLER_AUTH_PARAME) {

        if (meetingRoomId != 0) {
            // 如果包含 meetingRoomId，则查询特定会议室的详细信息
            API_HANDLER_RESP_VO(execQueryOne(meetingRoomId, authObject->getPayload()));
        }
        else if ( !locationName->empty()) {
            // 如果不包含 meetingRoomId，则按 locationId 和 locationName 查询会议室列表
            MeetingRoomSelectQuery::Wrapper locationQuery = MeetingRoomSelectQuery::createShared();
            /*locationQuery->locationId = locationId;*/
            locationQuery->locationName = locationName;

            API_HANDLER_RESP_VO(execQueryMeetingRoom(locationQuery, authObject->getPayload()));
        }
    }


    //// 3.1 定义测试声明式服务调用的接口2描述
    //ENDPOINT_INFO(queryAll) {
    //    // 定义标题和返回类型以及授权支持
    //    API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("meetingmanager.query-all.summary"), MeetingRoomSelectPageJsonVO::Wrapper);
    //    // 定义分页查询参数描述
    //    API_DEF_ADD_PAGE_PARAMS();
    //    // 定义其他查询参数描述
    //    API_DEF_ADD_QUERY_PARAMS(String, "meetingRoomName", ZH_WORDS_GETTER("meetingmanager.field.meetingRoomName"), "jjj", false);
    //}
    //// 3.2 定义测试声明式服务调用的接口1处理
    //API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/meetingroom/query-all", queryAll, MeetingRoomSelectQuery, execQueryAll(query, authObject->getPayload()));

   

private:
    // 查询同楼层会议室列表的具体实现方法
    MeetingRoomSelectPageJsonVO::Wrapper execQueryMeetingRoom(const MeetingRoomSelectQuery::Wrapper& query, const PayloadDTO& payload);

    // 查询单个会议室信息的具体实现方法
    MeetingRoomSelectJsonVO::Wrapper execQueryOne(const UInt64& meetingRoomId, const PayloadDTO& payload);
   /* MeetingRoomSelectPageJsonVO::Wrapper execQueryAll(const MeetingRoomSelectQuery::Wrapper& query, const PayloadDTO& payload);*/
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MEETINGROOMSELECT_CONTROLLER_