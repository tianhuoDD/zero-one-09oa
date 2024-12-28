#pragma once
 /*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/18 17:35:06

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
#ifndef _IDMEMBERVO_H_
#define _IDMEMBERVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/get/IDmemberDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象(分页)
 */
class IDmemberPageJsonVO : public JsonVO<IDmemberPageDTO::Wrapper> {
	DTO_INIT(IDmemberPageJsonVO, JsonVO<IDmemberPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_IDMEMBERVO_H_