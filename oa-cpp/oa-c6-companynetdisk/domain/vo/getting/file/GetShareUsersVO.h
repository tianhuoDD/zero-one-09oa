#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/18 14:46:10

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
#ifndef _GETSHAREUSERSVO_H_
#define _GETSHAREUSERSVO_H_

#include "../../../GlobalInclude.h"
#include  "../../../dto/getting/file/GetShareUsersDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����û��б��ҳ��ʾ
 */
class GetShareUsersPageJsonVO : public JsonVO<GetShareUsersPageDTO::Wrapper>
{
	DTO_INIT(GetShareUsersPageJsonVO, JsonVO<GetShareUsersPageDTO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GETSHAREUSERSVO_H_
