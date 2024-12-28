#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/20 16:26:49

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
#ifndef _ROOMINFODTO_H_
#define _ROOMINFODTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class RoomInfoDTO : public oatpp::DTO
{
	DTO_INIT(RoomInfoDTO, DTO);

	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("room.setting.building.xid"));
API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("room.setting.building.xname"));
API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("room.setting.building.xaddress"));
API_DTO_FIELD_DEFAULT(String, xpinyin, ZH_WORDS_GETTER("room.building.xpinyin"));
API_DTO_FIELD_DEFAULT(String, xpinyinintial, ZH_WORDS_GETTER("room.building.xpinyinintial"));

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ROOMINFODTO_H_
