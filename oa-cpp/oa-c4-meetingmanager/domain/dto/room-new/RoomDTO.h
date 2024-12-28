#pragma once
#ifndef _ROOM_DTO_
#define _ROOM_DTO_
#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//关于会议室的DTO

class RoomDTO : public oatpp::DTO
{
	DTO_INIT(RoomDTO, DTO);
	//会议室唯一标识符
	DTO_FIELD(String, roomId);
	DTO_FIELD_INFO(roomId) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.roomId");
	}

	//会议室名称
	DTO_FIELD(String, roomName);
	DTO_FIELD_INFO(roomName) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.roomName");
	}

	//会议室门牌
	DTO_FIELD(String, roomNumber);
	DTO_FIELD_INFO(roomNumber) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.roomNumber");
	}
	//分机号
	DTO_FIELD(String, phoneNumber);
	DTO_FIELD_INFO(phoneNumber) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.phoneNumber");
	}
	//会议室楼层
	DTO_FIELD(Int32, floor);
	DTO_FIELD_INFO(floor) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.floor");
	}
	//会议室设备
	DTO_FIELD(String, device);
	DTO_FIELD_INFO(device) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.device");

	}
	//会议室容量
	DTO_FIELD(Int64, capacity);
	DTO_FIELD_INFO(capacity) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.capacity");

	}
	//是否可用
	DTO_FIELD(Boolean, available);
	DTO_FIELD_INFO(available) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.available");

	}
	//更新时间
	DTO_FIELD(String, updateTime);
	/*DTO_FIELD_INFO(updateTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.updateTime");

	}*/
	//创建时间
	DTO_FIELD(String, createTime);
	/*DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.createTime");

	}*/

};
class WoRoom : public RoomDTO {
	DTO_INIT(WoRoom, RoomDTO);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ROOM_DTO_
