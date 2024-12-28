#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _MettingRoomList_DTO_
#define _MettingRoomList_DTO_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class MettingRoomListDTO : public oatpp::DTO
{
	DTO_INIT(MettingRoomListDTO, DTO);
	// id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("metting.id"));
	// 会议name
	API_DTO_FIELD_DEFAULT(String, mettingname, ZH_WORDS_GETTER("metting.name"));
	// 会议build
	API_DTO_FIELD_DEFAULT(String, mettingbuild, ZH_WORDS_GETTER("metting.build"));
	// 会议floor
	API_DTO_FIELD_DEFAULT(Int32, mettingfloor, ZH_WORDS_GETTER("metting.floor"));
	// 会议capacity
	API_DTO_FIELD_DEFAULT(Int32, mettingcapacity, ZH_WORDS_GETTER("metting.capacity"));
	// 会议roomnumber
	API_DTO_FIELD_DEFAULT(String, mettingroomnumber, ZH_WORDS_GETTER("metting.roomnumber"));
	// 会议dis
	API_DTO_FIELD_DEFAULT(Int32, mettingdis, ZH_WORDS_GETTER("metting.dis"));
	// 会议device
	API_DTO_FIELD_DEFAULT(String, mettingdevice, ZH_WORDS_GETTER("metting.device"));
	// 会议status
	API_DTO_FIELD_DEFAULT(Boolean, mettingavailable, ZH_WORDS_GETTER("metting.available"));
	// meeting
	API_DTO_FIELD_DEFAULT(String, meeting, ZH_WORDS_GETTER("metting.meeting"));

};

/**
 * 示例分页传输对象
 */
class MettingRoomListPageDTO : public PageDTO<MettingRoomListDTO::Wrapper>
{
	DTO_INIT(MettingRoomListPageDTO, PageDTO<MettingRoomListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MettingRoomList_DTO_