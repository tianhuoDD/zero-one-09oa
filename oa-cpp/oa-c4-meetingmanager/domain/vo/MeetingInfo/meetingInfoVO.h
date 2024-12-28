#pragma once
#ifndef _MEETING_INFO_VO_
#define _MEETING_INFO_VO_
#include"../../GlobalInclude.h"
#include "domain/dto/Meeting/MeetingInfoDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

//查询返回的会议详细信息



//会议所有信息
class MeetingInfoVO : public oatpp::DTO {
	DTO_INIT(MeetingInfoVO, DTO);
	//申请人
	DTO_FIELD(String, applicant);
	DTO_FIELD_INFO(applicant) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.applicant");
	}
	//会议类型
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.type");
	}
	//开始日期
	DTO_FIELD(String, startTime);
	DTO_FIELD_INFO(startTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.startTime");
	}
	//结束时间
	DTO_FIELD(String, completedTime);
	DTO_FIELD_INFO(completedTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.completedTime");
	}
	//会议室
	DTO_FIELD(String, room);
	DTO_FIELD_INFO(room) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room");
	}
	//主持人
	DTO_FIELD(oatpp::String, hostPerson);
	DTO_FIELD_INFO(hostPerson) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.hostPerson");
	}
	//参会成员
	DTO_FIELD(oatpp::List<oatpp::String>, inviteMemberList) = {};
	DTO_FIELD_INFO(inviteMemberList) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.inviteMemberList");
	}
	//签到人员
	DTO_FIELD(oatpp::List<oatpp::String>, checkinPersonList) = {};
	DTO_FIELD_INFO(checkinPersonList) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.checkInPersonList");
	}
	//
	DTO_FIELD(oatpp::List<oatpp::String>, inviteDelPersonList) = {};
	//接受的参会人员
	DTO_FIELD(oatpp::List<oatpp::String>, acceptPersonList) = {};

	//拒绝的参会人员
	DTO_FIELD(oatpp::List<oatpp::String>, rejectPersonList) = {};
	//参会人员
	DTO_FIELD(oatpp::List<oatpp::String>, invitePersonList) = {};

	//主持部门
	DTO_FIELD(String, hostUnit);

	//会议标题
	DTO_FIELD(String, subject);
	DTO_FIELD_INFO(subject) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.subject");
	}
	//会议描述
	DTO_FIELD(String, summary);
	DTO_FIELD_INFO(summary) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.summary");
	}
	//拼音
	DTO_FIELD(String, pinyin);

	//拼音首字母
	DTO_FIELD(String, pinyinInitial);
	//附件列表
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