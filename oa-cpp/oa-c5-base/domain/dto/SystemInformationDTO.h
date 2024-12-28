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
#ifndef _SYSTEM_INFORMATION_DTO_H_
#define _SYSTEM_INFORMATION_DTO_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SystemInformationDTO : public oatpp::DTO
{
	DTO_INIT(SystemInformationDTO, DTO);

	DTO_FIELD(String, systeminformaton);
	//DTO_FIELD_INFO(systeminformaton) {
	//	info->description = ZH_WORDS_GETTER("Information.field.createTime");
	//}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SYSTEM_INFORMATION_DTO_H_