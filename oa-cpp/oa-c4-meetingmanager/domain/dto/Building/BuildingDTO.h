#pragma once

#ifndef _BUILDING_DTO_
#define _BUILDING_DTO_

#include "../../GlobalInclude.h"
#include "./Meeting/MeetingInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class BuildInfo : public: oatpp::DTO
{
	DTO_INIT(BuildInfo, DTO);
	//会议室位置唯一标识符
	DTO_FIELD(String, buildId);
	DTO_FIELD_INFO(buildId) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.buildId");
	}
	//会议室位置创建时间
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.createTime");
	}
	//会议室位置更新时间
	DTO_FIELD(String, updateTime);
	DTO_FIELD_INFO(updateTime) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.updateTime");
	}
	//会议室位置名称
	DTO_FIELD(String, buildName);
	DTO_FIELD_INFO(buildName) {
		info->description = ZH_WORDS_GETTER("meeting-manager.meeting-info.room-info.buildName");
	}
	
}
//class BuildingDTO: public oatpp::DTO
//{
//	DTO_INIT(BuildingDTO, DTO);
//	//根据会议室获取会议列表
//	DTO_FIELD(list<oatpp::Object<MeetingInfo>>, meetingList);
//	DTO_FIELD_INFO(meetingList) {
//		info->description = ZH_WORDS_GETTER();
//	}
//
//	//根据building的唯一id进行查询
//	DTO_FIELD(String, buildId);
//	DTO_FIELD_INFO(buildId) {
//		info->description = ZH_WORDS_GETTER();
//	}
//	//拼音
//	DTO_FIELD(String, pinyin);
//	DTO_FIELD_INFO(pinyin) {
//		info->description = ZH_WORDS_GETTER();
//	}
//	//拼音首字母缩写
//	DTO_FIELD(String, pinyinInitial);
//	DTO_FIELD_INFO(pinyinInitial) {
//		info->description = ZH_WORDS_GETTER();
//	}
//	//
//};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BUILDING_DTO_