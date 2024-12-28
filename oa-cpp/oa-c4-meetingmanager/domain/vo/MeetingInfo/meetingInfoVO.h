#pragma once
#ifndef _MEETING_INFO_VO_
#define _MEETING_INFO_VO_
#include"../../GlobalInclude.h"
#include "domain/dto/Meeting/MeetingInfoDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

//��ѯ���صĻ�����ϸ��Ϣ



//����������Ϣ
class MeetingInfoVO : public oatpp::DTO {
	DTO_INIT(MeetingInfoVO, DTO);
	//������
	DTO_FIELD(String, applicant);
	DTO_FIELD_INFO(applicant) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.applicant");
	}
	//��������
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.type");
	}
	//��ʼ����
	DTO_FIELD(String, startTime);
	DTO_FIELD_INFO(startTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.startTime");
	}
	//����ʱ��
	DTO_FIELD(String, completedTime);
	DTO_FIELD_INFO(completedTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.completedTime");
	}
	//������
	DTO_FIELD(String, room);
	DTO_FIELD_INFO(room) {
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
	//���ܵĲλ���Ա
	DTO_FIELD(oatpp::List<oatpp::String>, acceptPersonList) = {};

	//�ܾ��Ĳλ���Ա
	DTO_FIELD(oatpp::List<oatpp::String>, rejectPersonList) = {};
	//�λ���Ա
	DTO_FIELD(oatpp::List<oatpp::String>, invitePersonList) = {};

	//���ֲ���
	DTO_FIELD(String, hostUnit);

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
	//ƴ��
	DTO_FIELD(String, pinyin);

	//ƴ������ĸ
	DTO_FIELD(String, pinyinInitial);
	//�����б�
	DTO_FIELD(oatpp::List<Object<AttachmentInfo>>, document) = {};
	DTO_FIELD_INFO(document) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.document");
	}

};

class MeetInfoJsonVO : public JsonVO<MeetingInfoVO::Wrapper> {
	DTO_INIT(MeetInfoJsonVO, JsonVO<MeetingInfoVO::Wrapper>);
};





#include OATPP_CODEGEN_END(DTO)
#endif //_MEETING_INFO_VO_