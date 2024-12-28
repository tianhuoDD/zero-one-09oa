#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _MettingCreate_VO_
#define _MettingCreate_VO_

#include "../../../GlobalInclude.h"
#include "domain/dto/metting/mettingcreate/MettingCreateDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MettingCreateJsonVO : public JsonVO<MettingCreateDTO::Wrapper> {
	DTO_INIT(MettingCreateJsonVO, JsonVO<MettingCreateDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MettingCreatePageJsonVO : public JsonVO<MettingCreatePageDTO::Wrapper> {
	DTO_INIT(MettingCreatePageJsonVO, JsonVO<MettingCreatePageDTO::Wrapper>);
};

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MettingRoomJsonVO : public JsonVO<MettingCreateDTO::Wrapper> {
	DTO_INIT(MettingRoomJsonVO, JsonVO<MettingCreateDTO::Wrapper>);
	// ������
	API_DTO_FIELD_DEFAULT(String, room, ZH_WORDS_GETTER("metting.mettingCreate.room"));

};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MettingRoomPageJsonVO : public JsonVO<MettingCreatePageDTO::Wrapper> {
	DTO_INIT(MettingRoomPageJsonVO, JsonVO<MettingCreatePageDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MettingHostJsonVO : public JsonVO<MettingCreateDTO::Wrapper> {
	DTO_INIT(MettingHostJsonVO, JsonVO<MettingCreateDTO::Wrapper>);
	// ����������
	API_DTO_FIELD_DEFAULT(String, hoster, ZH_WORDS_GETTER("metting.mettingCreate.hoster"));

};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MettingHostPageJsonVO : public JsonVO<MettingCreatePageDTO::Wrapper> {
	DTO_INIT(MettingHostPageJsonVO, JsonVO<MettingCreatePageDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MettingDepartJsonVO : public JsonVO<MettingCreateDTO::Wrapper> {
	DTO_INIT(MettingDepartJsonVO, JsonVO<MettingCreateDTO::Wrapper>);
	// 
	API_DTO_FIELD_DEFAULT(String, depart, ZH_WORDS_GETTER("metting.mettingCreate.depart"));

};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MettingDepartPageJsonVO : public JsonVO<MettingCreatePageDTO::Wrapper> {
	DTO_INIT(MettingDepartPageJsonVO, JsonVO<MettingCreatePageDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MettingMemberJsonVO : public JsonVO<MettingCreateDTO::Wrapper> {
	DTO_INIT(MettingMemberJsonVO, JsonVO<MettingCreateDTO::Wrapper>);
	// 
	API_DTO_FIELD_DEFAULT(String, depart, ZH_WORDS_GETTER("metting.mettingCreate.depart"));

};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MettingMemebrPageJsonVO : public JsonVO<MettingCreatePageDTO::Wrapper> {
	DTO_INIT(MettingMemebrPageJsonVO, JsonVO<MettingCreatePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MettingCreate_VO_