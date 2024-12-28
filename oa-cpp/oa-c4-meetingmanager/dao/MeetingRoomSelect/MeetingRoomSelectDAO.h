#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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

#ifndef _MEETINGROOMSELECT_DAO_
#define _MEETINGROOMSELECT_DAO_

#include "BaseDAO.h"
#include "../../domain/do/MeetingRoomSelect/MeetingRoomSelectDO.h"
#include "../../domain/query/MeetingRoomSelect/MeetingRoomQuery.h"

/**
 * ������ѡ������ݿ����ʵ����
 */
class MeetingRoomSelectDAO : public BaseDAO
{
public:
    // ͳ�Ƽ�¼��
    uint64_t count(const MeetingRoomSelectQuery::Wrapper& query);

    // ��ҳ��ѯ�����Ҽ�¼
    list<MeetingRoomSelectDO> selectWithPage(const MeetingRoomSelectQuery::Wrapper& query);

    // ���ݻ��������Ʋ�ѯ������
    list<MeetingRoomSelectDO> selectByRoomName(const std::string& roomName);

    // �����µĻ����Ҽ�¼
    uint64_t insert(const MeetingRoomSelectDO& iObj);

    // ���»����Ҽ�¼
    int update(const MeetingRoomSelectDO& uObj);

    // ����IDɾ�������Ҽ�¼
    int deleteById(uint64_t id);
};


#endif // !_MEETINGROOMSELECT_DAO_