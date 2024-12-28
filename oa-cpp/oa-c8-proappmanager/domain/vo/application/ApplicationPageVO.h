/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/19 23:04:12

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
#ifndef _APPLICATIONPAGEVO_H_
#define _APPLICATIONPAGEVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/application/ApplicationDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ApplicationJsonVO : public JsonVO<ApplicationDTO::Wrapper> {
	DTO_INIT(ApplicationJsonVO, JsonVO<ApplicationDTO::Wrapper>);
};


class ApplicationPageJsonVO : public JsonVO<ApplicationPageDTO::Wrapper> {
	DTO_INIT(ApplicationPageJsonVO, JsonVO<ApplicationPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_APPLICATIONPAGEVO_H_