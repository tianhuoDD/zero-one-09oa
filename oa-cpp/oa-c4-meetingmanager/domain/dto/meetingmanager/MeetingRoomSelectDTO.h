#pragma once

/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/21 20:00:00

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


#ifndef _MEETINGROOMSELECT_DTO_
#define _MEETINGROOMSELECT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������ѡ��DTO
 */
class MeetingRoomSelectDTO : public oatpp::DTO
{
	DTO_INIT(MeetingRoomSelectDTO, DTO);

	// �����ұ��
	DTO_FIELD(UInt64, meetingRoomId);
	DTO_FIELD_INFO(meetingRoomId) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.meetingRoomId");
	}

	// ����������
	DTO_FIELD(String, meetingRoomName);
	DTO_FIELD_INFO(meetingRoomName) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.meetingRoomName");
	}


	// Ԥ������ʱ��
	DTO_FIELD(String, scheduledDateTime);
	DTO_FIELD_INFO(scheduledDateTime) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.scheduledDateTime");
	}

	// ����ʱ�䣨Сʱ��
	DTO_FIELD(UInt32, durationHours);
	DTO_FIELD_INFO(durationHours) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.durationHours");
	}

	// ����ʱ�䣨���ӣ�
	DTO_FIELD(UInt32, durationMinutes);
	DTO_FIELD_INFO(durationMinutes) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.durationMinutes");
	}

	//// id
	//DTO_FIELD(UInt64, locationId);
	//DTO_FIELD_INFO(locationId) {
	//	info->description = ZH_WORDS_GETTER("meetingmanager.field.locationId");
	//}
	//// ����
	//DTO_FIELD(String, locationName);
	//DTO_FIELD_INFO(locationName) {
	//	info->description = ZH_WORDS_GETTER("meetingmanager.field.locationName");
	//}        // ¥�����ƣ��硰1¥������2¥��
};



/**
 * λ��DTO
 */
class LocationDTO : public oatpp::DTO {
	DTO_INIT(LocationDTO, DTO);

	//// λ�ñ��
	//DTO_FIELD(UInt64, locationId);
	//DTO_FIELD_INFO(locationId) {
	//	info->description = ZH_WORDS_GETTER("meetingroomselect.field.locationId");
	//}

	// λ������
	DTO_FIELD(String, locationName);
	DTO_FIELD_INFO(locationName) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.locationName");
	}


	// �����Ļ�������Ϣ�б�
	DTO_FIELD(Vector<oatpp::Object<MeetingRoomSelectDTO>>, meetingRooms);
	DTO_FIELD_INFO(meetingRooms) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.meetingRooms");
	}
};


/**
 * ������ѡ���ҳDTO
 */
class MeetingRoomSelectPageDTO : public PageDTO<MeetingRoomSelectDTO::Wrapper>
{
	DTO_INIT(MeetingRoomSelectPageDTO, PageDTO<MeetingRoomSelectDTO::Wrapper>);

	// ��ǰҳ��
	DTO_FIELD(Int32, page);
	DTO_FIELD_INFO(page) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.page");
	}

	// ÿҳ��С
	DTO_FIELD(Int32, pageSize);
	DTO_FIELD_INFO(pageSize) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.pageSize");
	}

	// �ܼ�¼��
	DTO_FIELD(Int64, totalRecords);
	DTO_FIELD_INFO(totalRecords) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.totalRecords");
	}

	// ��ҳ��
	DTO_FIELD(Int32, totalPages);
	DTO_FIELD_INFO(totalPages) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.totalPages");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MEETINGROOMSELECT_DTO_