#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/21 17:39:56

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
#ifndef _ADDDATACONFIGDTO_H_
#define _ADDDATACONFIGDTO_H_

#include "../../GlobalInclude.h"

/**
 * 数据配置对象
 */
#include OATPP_CODEGEN_BEGIN(DTO)

class AddDataConfigDTO : public oatpp::DTO
{
	DTO_INIT(AddDataConfigDTO, DTO);
	// 名称
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("data-config.field.xname"), true, "my dictionary");
	// 别名
	API_DTO_FIELD(String, xalias, ZH_WORDS_GETTER("data-config.field.xalias"), true, "our dictionary");
	// 描述
	API_DTO_FIELD(String, xdescription, ZH_WORDS_GETTER("data-config.field.xdescription"), false, "This is my favorite dictionary");
	// xappid
	API_DTO_FIELD(String, xappId, ZH_WORDS_GETTER("data-config.field.xappId"), true, "123456");
	// 所有项目（json数据格式）
	API_DTO_FIELD(String, allitems, ZH_WORDS_GETTER("data-config.field.allitems"), false, "{\"NewItem1\": [\"New Element Value\",\"New Element Value\"] ,\"NewItem\" : \"New Item Value\"}");

};

class ModifyDataConfigDTO : public oatpp::DTO
{
	DTO_INIT(ModifyDataConfigDTO, DTO);
	// 字典唯一标识
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("data-config.field.xid"), false, "40b75ee6-3348-405d-a854-be99e7e9ab13");
	// 名称
	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("data-config.field.xname"), true, "my dictionary");
	// 别名
	API_DTO_FIELD(String, xalias, ZH_WORDS_GETTER("data-config.field.xalias"), true, "our dictionary");
	// 描述
	API_DTO_FIELD(String, xdescription, ZH_WORDS_GETTER("data-config.field.xdescription"), false, "This is my favorite dictionary");
	// 所有项目（json数据格式）
	API_DTO_FIELD(String, allitems, ZH_WORDS_GETTER("data-config.field.allitems"), false, "{\"NewItem1\": [\"New Element Value\",\"New Element Value\"] ,\"NewItem\" : \"New Item Value\"}");


};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDDATACONFIGDTO_H_

