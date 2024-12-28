#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/21

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
#ifndef _MEETINGSELECT_DTO_H_
#define _MEETINGSELECT_DTO_H_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)



/**
 * 会议选择DTO
 */
class MeetingSelectDTO : public oatpp::DTO
{
	DTO_INIT(MeetingSelectDTO, DTO);

	// 会议编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.id");
	}

	// 申请人
	DTO_FIELD(String, applicant);
	DTO_FIELD_INFO(applicant) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.applicant");
	}

	//// 日期
	//DTO_FIELD(String, date);
	//DTO_FIELD_INFO(date) {
	//	info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.date");
	//}

	// 时间
	DTO_FIELD(String, time);
	DTO_FIELD_INFO(time) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.time");
	}

	// 会议标题
	DTO_FIELD(String, title);
	DTO_FIELD_INFO(title) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.title");
	}

	// 会议室
	DTO_FIELD(String, meetingRoom);
	DTO_FIELD_INFO(meetingRoom) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.meetingRoom");
	}

	//// 会议类型 (申请/邀请)
	//DTO_FIELD(UInt64, type);
	//DTO_FIELD_INFO(type) {
	//	info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.type");
	//	
	//}

	//// 会议状态 (未开始/进行中/已结束/已拒绝)
	//DTO_FIELD(String, status);
	//DTO_FIELD_INFO(status) {
	//	info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.status");
	//}


};

/**
 * 会议选择分页DTO
 */
class MeetingSelectPageDTO : public PageDTO<MeetingSelectDTO::Wrapper>
{
	DTO_INIT(MeetingSelectPageDTO, PageDTO<MeetingSelectDTO::Wrapper>);

	// 当前页码
	DTO_FIELD(UInt64, page);
	DTO_FIELD_INFO(page) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.page");
	}

	// 每页大小
	DTO_FIELD(UInt64, pageSize);
	DTO_FIELD_INFO(pageSize) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.pageSize");
	}

	// 总记录数
	DTO_FIELD(UInt64, totalRecords);
	DTO_FIELD_INFO(totalRecords) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.totalRecords");
	}

	// 总页数
	DTO_FIELD(UInt64, totalPages);
	DTO_FIELD_INFO(totalPages) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.totalPages");
	}

};


///**
// * 会议分类DTO
// */
//class MeetingCategoryDTO : public oatpp::DTO
//{
//	DTO_INIT(MeetingCategoryDTO, DTO);
//
//	// 分类名称（我的会议申请或我收到的邀请）
//	DTO_FIELD(String, categoryName);
//	DTO_FIELD_INFO(categoryName) {
//		info->description = ZH_WORDS_GETTER("orgmanager.meetingcategory.field.categoryName");
//	}
//
//	// 状态列表
//	DTO_FIELD(List<MeetingStatusDTO::Wrapper>, statuses);
//	DTO_FIELD_INFO(statuses) {
//		info->description = ZH_WORDS_GETTER("orgmanager.meetingcategory.field.statuses");
//	}
//};
//
///**
// * 左侧会议状态列表DTO
// */
//class MeetingStatusListDTO : public oatpp::DTO
//{
//	DTO_INIT(MeetingStatusListDTO, DTO);
//
//	// 会议分类列表（包含"我的会议申请"和"我收到的邀请"）
//	DTO_FIELD(List<MeetingCategoryDTO::Wrapper>, categories);
//	DTO_FIELD_INFO(categories) {
//		info->description = ZH_WORDS_GETTER("orgmanager.meetingstatuslist.field.categories");
//	}
//};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MEETINGSELECT_DTO_


