#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _ORGMEM_DTO_
#define _ORGMEM_DTO_
#include "../GlobalInclude.h"
#include<list>
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class OrgMemDTO : public oatpp::DTO
{

	DTO_INIT(OrgMemDTO, DTO);
	// 编号
	DTO_FIELD(String,orgID);
	DTO_FIELD(List<String>, ids);
	DTO_FIELD_INFO(ids) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	
};


/**
 * 示例分页传输对象
 */


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_