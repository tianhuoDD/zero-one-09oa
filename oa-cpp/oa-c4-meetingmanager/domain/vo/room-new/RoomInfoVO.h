#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/20 16:43:43

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
#ifndef _ROOMINFOVO_H_
#define _ROOMINFOVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/room-new/RoomInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class RoomInfoVO : public oatpp::DTO
{
	DTO_INIT(RoomInfoDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, id, "room.setting.building.xid");
	API_DTO_FIELD_DEFAULT(String, name, "room.setting.building.xname");
};



/**
 * Room信息显示JsonVO，用于响应给客户端的Json对象
 */
class RoomInfoJsonVO : public JsonVO<RoomInfoDTO::Wrapper> {

	DTO_INIT(RoomInfoJsonVO, JsonVO<RoomInfoDTO::Wrapper>);
};

class RoomBuidingJsonVo : public JsonVO<RoomInfoVO::Wrapper> {
	DTO_INIT(RoomBuidingJsonVo, JsonVO<RoomInfoVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ROOMINFOVO_H_
