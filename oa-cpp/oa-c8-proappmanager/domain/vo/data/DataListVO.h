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
#ifndef _DATALISTVO_H_
#define _DATALISTVO_H_
#include "../../GlobalInclude.h"
#include "domain/dto/data/DataListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DataListJsonVO : public JsonVO<DataListDTO::Wrapper> {
	DTO_INIT(DataListJsonVO, JsonVO<DataListDTO::Wrapper>);
};

class DataListPageJsonVO : public JsonVO<DataListPageDTO::Wrapper> {
	DTO_INIT(DataListPageJsonVO, JsonVO<DataListPageDTO::Wrapper>);
};

///**
// * 数据配置列表显示对象
// */
//class DataListVO : public oatpp::DTO
//{
//	DTO_INIT(DataListVO, DTO);
//
//	// 配置项名称
//	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("config.detail.field.name"));
//
//	// 别名
//	API_DTO_FIELD_DEFAULT(String, alias, ZH_WORDS_GETTER("config.detail.field.alias"));
//
//	// 更新时间
//	API_DTO_FIELD_DEFAULT(String, updateTime, ZH_WORDS_GETTER("config.detail.field.updateTime"));
//};
///**
// * 数据配置列表显示JsonVO，用于响应给客户端的Json对象
// */
//class DataListJsonVO : public JsonVO<DataListVO::Wrapper> {
//	DTO_INIT(DataListJsonVO, JsonVO<DataListVO::Wrapper>);
//};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DATALISTVO_H_