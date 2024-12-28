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

// ��ѯͬ¥��������б�ľ���ʵ�ַ���
MeetingRoomSelectPageJsonVO::Wrapper MeetingRoomSelectController::execQueryMeetingRoom(
    const MeetingRoomSelectQuery::Wrapper& query,
    const PayloadDTO& payload) {

    MeetingRoomSelectService service;  // ��������ʵ��
    auto result = service.listAll(query);  // ���÷����Ĳ�ѯ����

    // �������ض��󣬰�װ��ѯ���
    auto jvo = MeetingRoomSelectPageJsonVO::createShared();
    jvo->success(result);  // �������װΪ�ɹ�״̬
    return jvo;
}


// ��ѯ������������Ϣ�ľ���ʵ�ַ���
MeetingRoomSelectJsonVO::Wrapper MeetingRoomSelectController::execQueryOne(
    const UInt64& meetingRoomId, 
    const PayloadDTO& payload) {

    API_CLIENT_CREATE(ac, om, MeetingRoomSelectApiClient, "meetingroomselect-api");
    std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();

    // ʹ�� API �ͻ��˲�ѯ������������Ϣ��ֱ�ӷ��ؽ��
    return ac->queryOne(token, meetingRoomId)->readBodyToDto<MeetingRoomSelectJsonVO::Wrapper>(om);
}


//MeetingRoomSelectPageJsonVO::Wrapper MeetingRoomSelectController::execQueryAll(const MeetingRoomSelectQuery::Wrapper& query, const PayloadDTO& payload)
//{
//    // �����ͻ��˶���
//    API_CLIENT_CREATE(ac, om, MeetingRoomSelectApiClient, "meetingroomselect-api");
//    // ����ƾ֤
//    std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
//    // ���ز�ѯ���
//    return ac->queryAll(token, query->pageIndex, query->pageSize, URIUtil::urlEncode(query->meetingRoomName))->readBodyToDto<MeetingRoomSelectPageJsonVO::Wrapper>(om);
//}


