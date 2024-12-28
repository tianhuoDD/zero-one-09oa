#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/23 23:46:26

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
#ifndef _LIST_PERSONAL_IDENTITYJSONVO_
#define _LIST_PERSONAL_IDENTITYJSONVO_

#include "../../GlobalInclude.h"
#include "../../dto/list/list_personal_identityDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class list_personal_identityJsonVO : public JsonVO<list_personal_identityDTO::Wrapper> {
	DTO_INIT(list_personal_identityJsonVO, JsonVO<list_personal_identityDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class listPageJsonVO : public JsonVO<listPageDTO::Wrapper> {
	DTO_INIT(listPageJsonVO, JsonVO<listPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_LIST_PERSONAL_IDENTITYJSONVO_
