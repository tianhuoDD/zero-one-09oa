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
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class MettingCreateJsonVO : public JsonVO<MettingCreateDTO::Wrapper> {
	DTO_INIT(MettingCreateJsonVO, JsonVO<MettingCreateDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class MettingCreatePageJsonVO : public JsonVO<MettingCreatePageDTO::Wrapper> {
	DTO_INIT(MettingCreatePageJsonVO, JsonVO<MettingCreatePageDTO::Wrapper>);
};

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class MettingRoomJsonVO : public JsonVO<MettingCreateDTO::Wrapper> {
	DTO_INIT(MettingRoomJsonVO, JsonVO<MettingCreateDTO::Wrapper>);
	// 会议室
	API_DTO_FIELD_DEFAULT(String, room, ZH_WORDS_GETTER("metting.mettingCreate.room"));

};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class MettingRoomPageJsonVO : public JsonVO<MettingCreatePageDTO::Wrapper> {
	DTO_INIT(MettingRoomPageJsonVO, JsonVO<MettingCreatePageDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class MettingHostJsonVO : public JsonVO<MettingCreateDTO::Wrapper> {
	DTO_INIT(MettingHostJsonVO, JsonVO<MettingCreateDTO::Wrapper>);
	// 会议主持人
	API_DTO_FIELD_DEFAULT(String, hoster, ZH_WORDS_GETTER("metting.mettingCreate.hoster"));

};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class MettingHostPageJsonVO : public JsonVO<MettingCreatePageDTO::Wrapper> {
	DTO_INIT(MettingHostPageJsonVO, JsonVO<MettingCreatePageDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class MettingDepartJsonVO : public JsonVO<MettingCreateDTO::Wrapper> {
	DTO_INIT(MettingDepartJsonVO, JsonVO<MettingCreateDTO::Wrapper>);
	// 
	API_DTO_FIELD_DEFAULT(String, depart, ZH_WORDS_GETTER("metting.mettingCreate.depart"));

};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class MettingDepartPageJsonVO : public JsonVO<MettingCreatePageDTO::Wrapper> {
	DTO_INIT(MettingDepartPageJsonVO, JsonVO<MettingCreatePageDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class MettingMemberJsonVO : public JsonVO<MettingCreateDTO::Wrapper> {
	DTO_INIT(MettingMemberJsonVO, JsonVO<MettingCreateDTO::Wrapper>);
	// 
	API_DTO_FIELD_DEFAULT(String, depart, ZH_WORDS_GETTER("metting.mettingCreate.depart"));

};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class MettingMemebrPageJsonVO : public JsonVO<MettingCreatePageDTO::Wrapper> {
	DTO_INIT(MettingMemebrPageJsonVO, JsonVO<MettingCreatePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MettingCreate_VO_