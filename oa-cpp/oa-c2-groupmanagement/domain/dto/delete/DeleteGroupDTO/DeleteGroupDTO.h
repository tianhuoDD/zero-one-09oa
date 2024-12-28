#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#ifndef _GROUPLIST_MAPPER_
#define _GROUPLIST_MAPPER_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DeleGroupDTO : public oatpp::DTO
{
	DTO_INIT(DeleGroupDTO, DTO);
	//Ⱥ��Ψһ��ʶ
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("groupManagement.groupInfo.field.id"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_MAPPER_