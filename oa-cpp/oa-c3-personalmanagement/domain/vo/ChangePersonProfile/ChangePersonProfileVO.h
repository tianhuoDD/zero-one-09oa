#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/26 23:47:08

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
#ifndef _CHANGEPERSONPROFILE_H_
#define _CHANGEPERSONPROFILE_H_

#include "../../GlobalInclude.h"
#include "../../dto/ChangePersonProfile/ChangePersonProfileDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���û���Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class ChangePersonProfileJsonVO : public JsonVO<ChangePersonProfileDTO::Wrapper>
{
	DTO_INIT(ChangePersonProfileJsonVO, JsonVO<ChangePersonProfileDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _USERVO_H_