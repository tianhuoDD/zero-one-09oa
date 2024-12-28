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
#ifndef _ATTRIB_DTOS_
#define _ATTRIB_DTOS_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

#include<vector>
/**
 * 示例传输对象
 */
class Attrib_modify_DTO : public oatpp::DTO
{
	DTO_INIT(Attrib_modify_DTO, DTO);
	//编号
	DTO_FIELD(String, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// 修改前的属性
	DTO_FIELD(String, xdistinguishedName_pre);
	DTO_FIELD_INFO(xdistinguishedName_pre) {
		info->description = ZH_WORDS_GETTER("sample.field.shuxing");
	}
	// 修改后的属性
	DTO_FIELD(String, xdistinguishedName_last);
	DTO_FIELD_INFO(xdistinguishedName_last) {
		info->description = ZH_WORDS_GETTER("sample.field.shuxing");
	}
	// 值
	DTO_FIELD(Int32, xdistributeFactor);
	DTO_FIELD_INFO(xdistributeFactor) {
		info->description = ZH_WORDS_GETTER("sample.field.value");
	}
	//描述
	DTO_FIELD(String, xdescription);
	DTO_FIELD_INFO(xdescription) {
		info->description = ZH_WORDS_GETTER("sample.field.shuxing");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_