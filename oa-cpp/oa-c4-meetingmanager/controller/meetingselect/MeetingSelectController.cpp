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
#include "MeetingSelectController.h"
#include "../../service/MeetingSelect/MeetingSelectService.h" 
#include "../ApiDeclarativeServicesHelper.h"

MeetingSelectPageJsonVO::Wrapper MeetingSelectController::execQueryMeeting(const MeetingSelectQuery::Wrapper& query, const PayloadDTO& payload)
{
    MeetingSelectService service; // ��������ʵ�������ڵ��ò�ѯ�߼�
    // ���÷����Ĳ�ѯ����
    auto result = service.listAll(query); // ���� listAll ���Խ��� id��Ϊ��ѯ����
    auto jvo = MeetingSelectPageJsonVO::createShared(); // �������ض��󣬰�װ��ѯ���
    jvo->success(result); // ��ѯ�ɹ����������װΪ�ɹ�״̬
    return jvo;
}

MeetingSelectJsonVO::Wrapper MeetingSelectController::execQueryOneMeeting(const String& applicant,  const PayloadDTO& payload)
{
    // ����API�ͻ���
    API_CLIENT_CREATE(ac, om, MeetingSelectApiClient, "meetingselect-api");

    // ������ȨToken������SampleController�е��߼���
    std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();


    // ʹ��API�ͻ��˸���ID��ѯ��������Ϣ
    return ac->queryOne(token, applicant)->readBodyToDto<MeetingSelectJsonVO::Wrapper>(om);
}

//MeetingSelectPageJsonVO::Wrapper MeetingSelectController::execQueryAllMeetings(const MeetingSelectQuery::Wrapper& query, const PayloadDTO& payload)
//{
//    // �����ͻ��˶���
//    API_CLIENT_CREATE(ac, om, MeetingRoomSelectApiClient, "meetingselect-api");
//    // ����ƾ֤
//    std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
//    // ���ز�ѯ���
//    return ac->queryAll(token, query->page,query->pageSize, URIUtil::urlEncode(query->title))->readBodyToDto<MeetingSelectPageJsonVO::Wrapper>(om);
//}
