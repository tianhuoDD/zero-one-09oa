#pragma once

#ifndef _MEETING_INFO_DTO_
#define _MEETING_INFO_DTO_
#include"../../GlobalInclude.h"
#include "domain/dto/room-new/RoomDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

//���ڸ�����DTO
class AttachmentInfo : public oatpp::DTO
{
	DTO_INIT(AttachmentInfo, DTO);
	//����Ψһ��ʶ��
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.id");
	}
	//�ļ���
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.name");
	}
	//������ʱ��
	DTO_FIELD(String, lastUpdateTime);
	DTO_FIELD_INFO(lastUpdateTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.lastUpdateTime");
	}
	//��������
	DTO_FIELD(String, lastUpdatePerson);
	DTO_FIELD_INFO(lastUpdatePerson) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.lastUpdatePerson");
	}
	//�ļ���Կ
	DTO_FIELD(String, encryptKey);
	DTO_FIELD_INFO(encryptKey) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.encryptKey");
	}
	//�Ƿ�ʹ�����·��
	DTO_FIELD(Boolean, deepPath);
	DTO_FIELD_INFO(deepPath) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.deepPath");
	}
	//�ļ���չ��
	DTO_FIELD(String, extension);
	DTO_FIELD_INFO(extension) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.extension");
	}
	//�ļ���С
	DTO_FIELD(UInt64, length);
	DTO_FIELD_INFO(length) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.length");
	}
	//�ļ��洢��ʶ
	DTO_FIELD(String, storage);
	DTO_FIELD_INFO(storage) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.storage");
	}
	//�Ƿ����ļ�����
	DTO_FIELD(Boolean, summary);
	DTO_FIELD_INFO(summary) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.summary");
	}
	//����ʱ��
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.createTime");
	}

	//�����Ļ���id
	DTO_FIELD(String, meetingId);
	DTO_FIELD_INFO(meetingId) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.meetingId");
	}
};


//����������Ϣ
class MeetingInfo : public oatpp::DTO {
	DTO_INIT(MeetingInfo, DTO);
	////������
	//DTO_FIELD(String, applicant);
	//DTO_FIELD_INFO(applicant) {
	//	info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.applicant");
	//}
	//����Id
	DTO_FIELD(String, meetingId);
	DTO_FIELD_INFO(meetingId) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.meetingId");
	}
	//��������
	DTO_FIELD(String, meetingtype);
	DTO_FIELD_INFO(meetingtype) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.type");
	}
	//��ʼʱ��
	DTO_FIELD(String, startTime);
	DTO_FIELD_INFO(startTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.time");
	}
	//����ʱ��
	DTO_FIELD(String, completedTime);
	DTO_FIELD_INFO(completedTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.time");
	}
	//������
	DTO_FIELD(String, roomId);
	DTO_FIELD_INFO(roomId) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room");
	}
	//������
	DTO_FIELD(oatpp::String, hostPerson);
	DTO_FIELD_INFO(hostPerson) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.hostPerson");
	}
	//�λ��Ա
	DTO_FIELD(oatpp::List<oatpp::String>, inviteMemberList) = {};
	DTO_FIELD_INFO(inviteMemberList) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.inviteMemberList");
	}
	//ǩ����Ա
	DTO_FIELD(oatpp::List<oatpp::String>, checkinPersonList) = {};
	DTO_FIELD_INFO(checkinPersonList) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.checkInPersonList");
	}
	//
	DTO_FIELD(oatpp::List<oatpp::String>, inviteDelPersonList) = {};
	DTO_FIELD_INFO(inviteDelPersonList) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.inviteMemberList");
	}
	//���ܵĲλ���Ա
	DTO_FIELD(oatpp::List<oatpp::String>, acceptPersonList) = {};
	DTO_FIELD_INFO(acceptPersonList) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.acceptPersonList");
	}
	//�ܾ��Ĳλ���Ա
	DTO_FIELD(oatpp::List<oatpp::String>, rejectPersonList) = {};
	DTO_FIELD_INFO(rejectPersonList) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.rejectPersonList");
	}
	//�λ���Ա
	DTO_FIELD(oatpp::List<oatpp::String>, invitePersonList) = {};
	DTO_FIELD_INFO(invitePersonList) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.invitePersonList");
	}
	//���ֲ���
	DTO_FIELD(String, hostUnit);
	DTO_FIELD_INFO(hostUnit) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.hostUnit");
	}
	//�������
	DTO_FIELD(String, subject);
	DTO_FIELD_INFO(subject) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.subject");
	}
	//��������
	DTO_FIELD(String, summary);
	DTO_FIELD_INFO(summary) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.summary");
	}
	//�����б�
	DTO_FIELD(oatpp::List<Object<AttachmentInfo>>, document) = {};
	DTO_FIELD_INFO(document) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.document");
	}
	//ƴ��
	DTO_FIELD(String, pinyin);
	DTO_FIELD_INFO(pinyin) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.pinyin");
	}
	//ƴ������ĸ
	DTO_FIELD(String, pinyinInitial);
	DTO_FIELD_INFO(pinyinInitial) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.pinyinInitial");
	}
};






#include OATPP_CODEGEN_END(DTO)
#endif //_MEETING_INFO