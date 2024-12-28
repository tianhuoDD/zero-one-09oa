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
 * ����ѡ��DTO
 */
class MeetingSelectDTO : public oatpp::DTO
{
	DTO_INIT(MeetingSelectDTO, DTO);

	// ������
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.id");
	}

	// ������
	DTO_FIELD(String, applicant);
	DTO_FIELD_INFO(applicant) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.applicant");
	}

	//// ����
	//DTO_FIELD(String, date);
	//DTO_FIELD_INFO(date) {
	//	info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.date");
	//}

	// ʱ��
	DTO_FIELD(String, time);
	DTO_FIELD_INFO(time) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.time");
	}

	// �������
	DTO_FIELD(String, title);
	DTO_FIELD_INFO(title) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.title");
	}

	// ������
	DTO_FIELD(String, meetingRoom);
	DTO_FIELD_INFO(meetingRoom) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.meetingRoom");
	}

	//// �������� (����/����)
	//DTO_FIELD(UInt64, type);
	//DTO_FIELD_INFO(type) {
	//	info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.type");
	//	
	//}

	//// ����״̬ (δ��ʼ/������/�ѽ���/�Ѿܾ�)
	//DTO_FIELD(String, status);
	//DTO_FIELD_INFO(status) {
	//	info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.status");
	//}


};

/**
 * ����ѡ���ҳDTO
 */
class MeetingSelectPageDTO : public PageDTO<MeetingSelectDTO::Wrapper>
{
	DTO_INIT(MeetingSelectPageDTO, PageDTO<MeetingSelectDTO::Wrapper>);

	// ��ǰҳ��
	DTO_FIELD(UInt64, page);
	DTO_FIELD_INFO(page) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.page");
	}

	// ÿҳ��С
	DTO_FIELD(UInt64, pageSize);
	DTO_FIELD_INFO(pageSize) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.pageSize");
	}

	// �ܼ�¼��
	DTO_FIELD(UInt64, totalRecords);
	DTO_FIELD_INFO(totalRecords) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.totalRecords");
	}

	// ��ҳ��
	DTO_FIELD(UInt64, totalPages);
	DTO_FIELD_INFO(totalPages) {
		info->description = ZH_WORDS_GETTER("orgmanager.meetingselect.field.totalPages");
	}

};


///**
// * �������DTO
// */
//class MeetingCategoryDTO : public oatpp::DTO
//{
//	DTO_INIT(MeetingCategoryDTO, DTO);
//
//	// �������ƣ��ҵĻ�����������յ������룩
//	DTO_FIELD(String, categoryName);
//	DTO_FIELD_INFO(categoryName) {
//		info->description = ZH_WORDS_GETTER("orgmanager.meetingcategory.field.categoryName");
//	}
//
//	// ״̬�б�
//	DTO_FIELD(List<MeetingStatusDTO::Wrapper>, statuses);
//	DTO_FIELD_INFO(statuses) {
//		info->description = ZH_WORDS_GETTER("orgmanager.meetingcategory.field.statuses");
//	}
//};
//
///**
// * ������״̬�б�DTO
// */
//class MeetingStatusListDTO : public oatpp::DTO
//{
//	DTO_INIT(MeetingStatusListDTO, DTO);
//
//	// ��������б�����"�ҵĻ�������"��"���յ�������"��
//	DTO_FIELD(List<MeetingCategoryDTO::Wrapper>, categories);
//	DTO_FIELD_INFO(categories) {
//		info->description = ZH_WORDS_GETTER("orgmanager.meetingstatuslist.field.categories");
//	}
//};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MEETINGSELECT_DTO_


