#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: dingfengchuan
 @Date: 2024��11��1��

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
#ifndef _SAMPLE_DTO_
#define _SAMPLE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class PersonlistDTO : public oatpp::DTO
{
	DTO_INIT(PersonlistDTO, DTO);
	// ����
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("person.setting.get.field.name");
	}
	// �绰
	DTO_FIELD(String, xmobile);
	DTO_FIELD_INFO(xmobile) {
		info->description = ZH_WORDS_GETTER("person.setting.get.field.phone");
	}
	// ͷ���ַ
	DTO_FIELD(String, xicon);
	DTO_FIELD_INFO(xicon) {
		info->description = ZH_WORDS_GETTER("person.setting.get.field.head");
	}
	// id
	DTO_FIELD(String, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("person.setting.get.field.id");
	}
	// xunique
	DTO_FIELD(String, xunique);
	DTO_FIELD_INFO(xunique) {
		info->description = ZH_WORDS_GETTER("person.setting.get.field.xunique");
	}
};

/**
 * ʾ����ҳ�������
 */
class PersonlistPageDTO : public PageDTO<PersonlistDTO::Wrapper>
{
	DTO_INIT(PersonlistPageDTO, PageDTO<PersonlistDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_