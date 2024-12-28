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
 * 会议室选择DTO
 */
class MeetingRoomSelectDTO : public oatpp::DTO
{
	DTO_INIT(MeetingRoomSelectDTO, DTO);

	// 会议室编号
	DTO_FIELD(UInt64, meetingRoomId);
	DTO_FIELD_INFO(meetingRoomId) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.meetingRoomId");
	}

	// 会议室名称
	DTO_FIELD(String, meetingRoomName);
	DTO_FIELD_INFO(meetingRoomName) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.meetingRoomName");
	}


	// 预定日期时间
	DTO_FIELD(String, scheduledDateTime);
	DTO_FIELD_INFO(scheduledDateTime) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.scheduledDateTime");
	}

	// 持续时间（小时）
	DTO_FIELD(UInt32, durationHours);
	DTO_FIELD_INFO(durationHours) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.durationHours");
	}

	// 持续时间（分钟）
	DTO_FIELD(UInt32, durationMinutes);
	DTO_FIELD_INFO(durationMinutes) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.durationMinutes");
	}

	//// id
	//DTO_FIELD(UInt64, locationId);
	//DTO_FIELD_INFO(locationId) {
	//	info->description = ZH_WORDS_GETTER("meetingmanager.field.locationId");
	//}
	//// 姓名
	//DTO_FIELD(String, locationName);
	//DTO_FIELD_INFO(locationName) {
	//	info->description = ZH_WORDS_GETTER("meetingmanager.field.locationName");
	//}        // 楼层名称，如“1楼”，“2楼”
};



/**
 * 位置DTO
 */
class LocationDTO : public oatpp::DTO {
	DTO_INIT(LocationDTO, DTO);

	//// 位置编号
	//DTO_FIELD(UInt64, locationId);
	//DTO_FIELD_INFO(locationId) {
	//	info->description = ZH_WORDS_GETTER("meetingroomselect.field.locationId");
	//}

	// 位置名称
	DTO_FIELD(String, locationName);
	DTO_FIELD_INFO(locationName) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.locationName");
	}


	// 包含的会议室信息列表
	DTO_FIELD(Vector<oatpp::Object<MeetingRoomSelectDTO>>, meetingRooms);
	DTO_FIELD_INFO(meetingRooms) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.meetingRooms");
	}
};


/**
 * 会议室选择分页DTO
 */
class MeetingRoomSelectPageDTO : public PageDTO<MeetingRoomSelectDTO::Wrapper>
{
	DTO_INIT(MeetingRoomSelectPageDTO, PageDTO<MeetingRoomSelectDTO::Wrapper>);

	// 当前页码
	DTO_FIELD(Int32, page);
	DTO_FIELD_INFO(page) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.page");
	}

	// 每页大小
	DTO_FIELD(Int32, pageSize);
	DTO_FIELD_INFO(pageSize) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.pageSize");
	}

	// 总记录数
	DTO_FIELD(Int64, totalRecords);
	DTO_FIELD_INFO(totalRecords) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.totalRecords");
	}

	// 总页数
	DTO_FIELD(Int32, totalPages);
	DTO_FIELD_INFO(totalPages) {
		info->description = ZH_WORDS_GETTER("meetingroomselect.field.totalPages");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MEETINGROOMSELECT_DTO_