#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/21

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
#ifndef _MEETINGROOMSELECT_VO_
#define _MEETINGROOMSELECT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/meetingmanager/MeetingRoomSelectDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������ѡ��JsonVO��������Ӧ���ͻ��˵�Json����
 */
class MeetingRoomSelectJsonVO : public JsonVO<MeetingRoomSelectDTO::Wrapper> {
    DTO_INIT(MeetingRoomSelectJsonVO, JsonVO<MeetingRoomSelectDTO::Wrapper>);
};



/**
 * λ��������Ӧ JsonVO�����ڷ��ذ������ LocationDTO ����� JSON ����
 */
class LocationJsonVO : public JsonVO<oatpp::Vector<oatpp::Object<LocationDTO>>> {
    DTO_INIT(LocationJsonVO, JsonVO<oatpp::Vector<oatpp::Object<LocationDTO>>>);
};

/**
 * ������ѡ���ҳJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MeetingRoomSelectPageJsonVO : public JsonVO<MeetingRoomSelectPageDTO::Wrapper> {
    DTO_INIT(MeetingRoomSelectPageJsonVO, JsonVO<MeetingRoomSelectPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_MEETINGROOMSELECT_VO_
