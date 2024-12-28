#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/17 19:13:23

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
#ifndef _MEETINGROOMDTO_H_
#define _MEETINGROOMDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class MeetingroomDTO : public oatpp::DTO
{
	DTO_INIT(MeetingroomDTO, DTO);
	//会议室id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("meetingroom.id"));
	// 会议室名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("meetingroom.name"));
	// 会议室位置
	API_DTO_FIELD_DEFAULT(String, location, ZH_WORDS_GETTER("meetingroom.location"));
	// 会议室楼层
	API_DTO_FIELD_DEFAULT(UInt64, floor, ZH_WORDS_GETTER("meetingroom.floor"));
	// 容纳人数
	API_DTO_FIELD_DEFAULT(UInt64, capacity, ZH_WORDS_GETTER("meetingroom.capacity"));
	//会议室门牌
	API_DTO_FIELD_DEFAULT(String, housenumber, ZH_WORDS_GETTER("meetingroom.housenumber"));
	// 分机号
	API_DTO_FIELD_DEFAULT(String, extnumber, ZH_WORDS_GETTER("meetingroom.extnumber"));
	//会议室设备
	API_DTO_FIELD_DEFAULT(Vector<String>, device, ZH_WORDS_GETTER("meetingroom.device"));
	//会议室状态
	API_DTO_FIELD_DEFAULT(Boolean, status, ZH_WORDS_GETTER("meetingroom.status"));
	//// 保存
	//API_DTO_FIELD_DEFAULT(UInt64, save, ZH_WORDS_GETTER("meetingroom.save"));
	//// 关闭
	//API_DTO_FIELD_DEFAULT(String, close, ZH_WORDS_GETTER("meetingroom.close"));
	//// 删除
	//API_DTO_FIELD_DEFAULT(String, roomdelete, ZH_WORDS_GETTER("meetingroom.roomdelete"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MEETINGROOMDTO_H_
