/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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

#include "stdafx.h"
#include "MeetingRoomSelectController.h"
#include "../../service/MeetingRoomSelect/MeetingRoomSelectService.h"
#include "../ApiDeclarativeServicesHelper.h"

// 查询同楼层会议室列表的具体实现方法
MeetingRoomSelectPageJsonVO::Wrapper MeetingRoomSelectController::execQueryMeetingRoom(
    const MeetingRoomSelectQuery::Wrapper& query,
    const PayloadDTO& payload) {

    MeetingRoomSelectService service;  // 创建服务实例
    auto result = service.listAll(query);  // 调用服务层的查询方法

    // 创建返回对象，包装查询结果
    auto jvo = MeetingRoomSelectPageJsonVO::createShared();
    jvo->success(result);  // 将结果包装为成功状态
    return jvo;
}


// 查询单个会议室信息的具体实现方法
MeetingRoomSelectJsonVO::Wrapper MeetingRoomSelectController::execQueryOne(
    const UInt64& meetingRoomId, 
    const PayloadDTO& payload) {

    API_CLIENT_CREATE(ac, om, MeetingRoomSelectApiClient, "meetingroomselect-api");
    std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();

    // 使用 API 客户端查询单个会议室信息并直接返回结果
    return ac->queryOne(token, meetingRoomId)->readBodyToDto<MeetingRoomSelectJsonVO::Wrapper>(om);
}


//MeetingRoomSelectPageJsonVO::Wrapper MeetingRoomSelectController::execQueryAll(const MeetingRoomSelectQuery::Wrapper& query, const PayloadDTO& payload)
//{
//    // 创建客户端对象
//    API_CLIENT_CREATE(ac, om, MeetingRoomSelectApiClient, "meetingroomselect-api");
//    // 构建凭证
//    std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
//    // 返回查询结果
//    return ac->queryAll(token, query->pageIndex, query->pageSize, URIUtil::urlEncode(query->meetingRoomName))->readBodyToDto<MeetingRoomSelectPageJsonVO::Wrapper>(om);
//}


