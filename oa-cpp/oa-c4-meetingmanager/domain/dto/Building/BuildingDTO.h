#pragma once

#ifndef _BUILDING_DTO_
#define _BUILDING_DTO_

#include "../../GlobalInclude.h"
#include "./Meeting/MeetingInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class BuildInfo : public: oatpp::DTO
{
	DTO_INIT(BuildInfo, DTO);
	//������λ��Ψһ��ʶ��
	DTO_FIELD(String, buildId);
	DTO_FIELD_INFO(buildId) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.buildId");
	}
	//������λ�ô���ʱ��
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.createTime");
	}
	//������λ�ø���ʱ��
	DTO_FIELD(String, updateTime);
	DTO_FIELD_INFO(updateTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.updateTime");
	}
	//������λ������
	DTO_FIELD(String, buildName);
	DTO_FIELD_INFO(buildName) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.buildName");
	}
	
}
//class BuildingDTO: public oatpp::DTO
//{
//	DTO_INIT(BuildingDTO, DTO);
//	//���ݻ����һ�ȡ�����б�
//	DTO_FIELD(list<oatpp::Object<MeetingInfo>>, meetingList);
//	DTO_FIELD_INFO(meetingList) {
//		info->description = ZH_WORDS_GETTER();
//	}
//
//	//����building��Ψһid���в�ѯ
//	DTO_FIELD(String, buildId);
//	DTO_FIELD_INFO(buildId) {
//		info->description = ZH_WORDS_GETTER();
//	}
//	//ƴ��
//	DTO_FIELD(String, pinyin);
//	DTO_FIELD_INFO(pinyin) {
//		info->description = ZH_WORDS_GETTER();
//	}
//	//ƴ������ĸ��д
//	DTO_FIELD(String, pinyinInitial);
//	DTO_FIELD_INFO(pinyinInitial) {
//		info->description = ZH_WORDS_GETTER();
//	}
//	//
//};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BUILDING_DTO_