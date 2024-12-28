#pragma once
#ifndef _ROOM_DTO_
#define _ROOM_DTO_
#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//���ڻ����ҵ�DTO

class RoomDTO : public oatpp::DTO
{
	DTO_INIT(RoomDTO, DTO);
	//������Ψһ��ʶ��
	DTO_FIELD(String, roomId);
	DTO_FIELD_INFO(roomId) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.roomId");
	}

	//����������
	DTO_FIELD(String, roomName);
	DTO_FIELD_INFO(roomName) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.roomName");
	}

	//����������
	DTO_FIELD(String, roomNumber);
	DTO_FIELD_INFO(roomNumber) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.roomNumber");
	}
	//�ֻ���
	DTO_FIELD(String, phoneNumber);
	DTO_FIELD_INFO(phoneNumber) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.phoneNumber");
	}
	//������¥��
	DTO_FIELD(Int32, floor);
	DTO_FIELD_INFO(floor) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.floor");
	}
	//�������豸
	DTO_FIELD(String, device);
	DTO_FIELD_INFO(device) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.device");

	}
	//����������
	DTO_FIELD(Int64, capacity);
	DTO_FIELD_INFO(capacity) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.capacity");

	}
	//�Ƿ����
	DTO_FIELD(Boolean, available);
	DTO_FIELD_INFO(available) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.available");

	}
	//����ʱ��
	DTO_FIELD(String, updateTime);
	/*DTO_FIELD_INFO(updateTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.updateTime");

	}*/
	//����ʱ��
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
