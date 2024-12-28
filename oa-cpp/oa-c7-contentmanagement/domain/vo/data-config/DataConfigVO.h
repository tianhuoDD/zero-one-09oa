#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/21 19:38:29

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
#ifndef _ADDDATACONFIGVO_H_
#define _ADDDATACONFIGVO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DataConfigVO : public oatpp::DTO
{
	DTO_INIT(DataConfigVO, DTO);
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

/**
 * 数据配置JsonVO，用于响应给客户端的Json对象
 */
class DataConfigJsonVO : public JsonVO<DataConfigVO::Wrapper> {
	DTO_INIT(DataConfigJsonVO, JsonVO<DataConfigVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDDATACONFIGVO_H_
