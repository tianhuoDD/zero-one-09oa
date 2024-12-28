#pragma once

#ifndef _MEETING_INFO_DTO_
#define _MEETING_INFO_DTO_
#include"../../GlobalInclude.h"
#include "domain/dto/room-new/RoomDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

//关于附件的DTO
class AttachmentInfo : public oatpp::DTO
{
	DTO_INIT(AttachmentInfo, DTO);
	//附件唯一标识符
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.id");
	}
	//文件名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.name");
	}
	//最后更新时间
	DTO_FIELD(String, lastUpdateTime);
	DTO_FIELD_INFO(lastUpdateTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.lastUpdateTime");
	}
	//最后更新人
	DTO_FIELD(String, lastUpdatePerson);
	DTO_FIELD_INFO(lastUpdatePerson) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.lastUpdatePerson");
	}
	//文件密钥
	DTO_FIELD(String, encryptKey);
	DTO_FIELD_INFO(encryptKey) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.encryptKey");
	}
	//是否使用深层路径
	DTO_FIELD(Boolean, deepPath);
	DTO_FIELD_INFO(deepPath) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.deepPath");
	}
	//文件拓展名
	DTO_FIELD(String, extension);
	DTO_FIELD_INFO(extension) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.extension");
	}
	//文件大小
	DTO_FIELD(UInt64, length);
	DTO_FIELD_INFO(length) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.length");
	}
	//文件存储标识
	DTO_FIELD(String, storage);
	DTO_FIELD_INFO(storage) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.storage");
	}
	//是否有文件描述
	DTO_FIELD(Boolean, summary);
	DTO_FIELD_INFO(summary) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.attachment.summary");
	}
	//创建时间
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.createTime");
	}

	//关联的会议id
	DTO_FIELD(String, meetingId);
	DTO_FIELD_INFO(meetingId) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.meetingId");
	}
};


//会议所有信息
class MeetingInfo : public oatpp::DTO {
	DTO_INIT(MeetingInfo, DTO);
	////申请人
	//DTO_FIELD(String, applicant);
	//DTO_FIELD_INFO(applicant) {
	//	info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.applicant");
	//}
	//会议Id
	DTO_FIELD(String, meetingId);
	DTO_FIELD_INFO(meetingId) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.meetingId");
	}
	//会议类型
	DTO_FIELD(String, meetingtype);
	DTO_FIELD_INFO(meetingtype) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.type");
	}
	//开始时间
	DTO_FIELD(String, startTime);
	DTO_FIELD_INFO(startTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.time");
	}
	//结束时间
	DTO_FIELD(String, completedTime);
	DTO_FIELD_INFO(completedTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.time");
	}
	//会议室
	DTO_FIELD(String, roomId);
	DTO_FIELD_INFO(roomId) {
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
	DTO_FIELD_INFO(inviteDelPersonList) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.inviteMemberList");
	}
	//接受的参会人员
	DTO_FIELD(oatpp::List<oatpp::String>, acceptPersonList) = {};
	DTO_FIELD_INFO(acceptPersonList) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.acceptPersonList");
	}
	//拒绝的参会人员
	DTO_FIELD(oatpp::List<oatpp::String>, rejectPersonList) = {};
	DTO_FIELD_INFO(rejectPersonList) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.rejectPersonList");
	}
	//参会人员
	DTO_FIELD(oatpp::List<oatpp::String>, invitePersonList) = {};
	DTO_FIELD_INFO(invitePersonList) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.invitePersonList");
	}
	//主持部门
	DTO_FIELD(String, hostUnit);
	DTO_FIELD_INFO(hostUnit) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.hostUnit");
	}
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
	//附件列表
	DTO_FIELD(oatpp::List<Object<AttachmentInfo>>, document) = {};
	DTO_FIELD_INFO(document) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.document");
	}
	//拼音
	DTO_FIELD(String, pinyin);
	DTO_FIELD_INFO(pinyin) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.pinyin");
	}
	//拼音首字母
	DTO_FIELD(String, pinyinInitial);
	DTO_FIELD_INFO(pinyinInitial) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.pinyinInitial");
	}
};






#include OATPP_CODEGEN_END(DTO)
#endif //_MEETING_INFO