/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/26 23:07:12

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
#ifndef _APPLICATIONNAMEDTO_H_
#define _APPLICATIONNAMEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ApplicationNameDTO : public oatpp::DTO
{
	DTO_INIT(ApplicationNameDTO, DTO);
	
	// Ӧ������
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("application.field.name");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_APPLICATIONNAMEDTO_H_