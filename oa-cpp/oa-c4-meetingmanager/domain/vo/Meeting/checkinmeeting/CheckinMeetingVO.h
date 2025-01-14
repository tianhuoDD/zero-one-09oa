#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: siri
 @Date: 2024/10/20 20:20:02

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
#ifndef _CHECKINMEETINGVO_H_
#define _CHECKINMEETINGVO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个签到结果显示JsonVO对象，用于响应给客户端
 */
class CheckinMeetingJsonVO : JsonVO<CheckinMeetingDTO::Wrapper>
{
	DTO_INIT(CheckinMeetingJsonVO, JsonVO<CheckinMeetingDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CHECKINMEETINGVO_H_