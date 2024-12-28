#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/26 23:47:08

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
#ifndef _MettingCreateDTO_H_
#define _MettingCreateDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ���޸��û���Ϣ�����ݴ���ģ��
 */
class MettingCreateDTO : public oatpp::DTO
{
	DTO_INIT(MettingCreateDTO, DTO);
	// ��������
	API_DTO_FIELD_DEFAULT(String, mettingtype,	ZH_WORDS_GETTER("metting.mettingCreate.mettingtype"));
	// ����
	API_DTO_FIELD_DEFAULT(String, date1,		ZH_WORDS_GETTER("metting.mettingCreate.date"));
	// ���鿪ʼʱ��
	API_DTO_FIELD_DEFAULT(String, timestart,	ZH_WORDS_GETTER("metting.mettingCreate.timestart"));
	// �������ʱ��
	API_DTO_FIELD_DEFAULT(String, timeend,		ZH_WORDS_GETTER("metting.mettingCreate.timeend"));
	// ������
	API_DTO_FIELD_DEFAULT(String, mettingroom,	ZH_WORDS_GETTER("metting.mettingCreate.mettingroom"));
	// ����title
	API_DTO_FIELD_DEFAULT(String, mettingtitle, ZH_WORDS_GETTER("metting.mettingCreate.mettingtitle"));
	// members
	API_DTO_FIELD_DEFAULT(String, member,		ZH_WORDS_GETTER("metting.mettingCreate.members"));
	// hoster
	API_DTO_FIELD_DEFAULT(String, hoster,		ZH_WORDS_GETTER("metting.mettingCreate.hoster"));
	// department
	API_DTO_FIELD_DEFAULT(String, department,	ZH_WORDS_GETTER("metting.mettingCreate.department"));
	// description
	API_DTO_FIELD_DEFAULT(String, description, ZH_WORDS_GETTER("metting.mettingCreate.description"));
};

/**
 * ����һ���û���Ϣ��ҳ�������
 */
class MettingCreatePageDTO : public PageDTO<MettingCreateDTO::Wrapper>
{
	DTO_INIT(MettingCreatePageDTO, PageDTO<MettingCreateDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _MettingCreateDTO_H_