#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _ATTRIB_QUERY_
#define _ATTRIB_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class AttribQuery : public PageQuery
{
	DTO_INIT(AttribQuery, PageQuery);
	//编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// 属性
	DTO_FIELD(String, shuxing);
	DTO_FIELD_INFO(shuxing) {
		info->description = ZH_WORDS_GETTER("sample.field.shuxing");
	}
	// 值
	DTO_FIELD(Int32, value);
	DTO_FIELD_INFO(value) {
		info->description = ZH_WORDS_GETTER("sample.field.value");
	}
	// 描述
	DTO_FIELD(String, miaoshu);
	DTO_FIELD_INFO(miaoshu) {
		info->description = ZH_WORDS_GETTER("sample.field.shuxing");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_