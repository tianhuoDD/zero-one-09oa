#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2024/10/19 21:44:34

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
#ifndef _SYSTEM_INFORMATION_VO_
#define _SYSTEM_INFORMATION_VO_

#include "../GlobalInclude.h"
#include "../dto/SystemInformationDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * δ����Ϣ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SystemInformationJsonVO : public JsonVO<SystemInformationDTO::Wrapper> {
	DTO_INIT(SystemInformationJsonVO, JsonVO<SystemInformationDTO::Wrapper>);
};




#include OATPP_CODEGEN_END(DTO)

#endif // !_SYSTEM_INFORMATION_VO_