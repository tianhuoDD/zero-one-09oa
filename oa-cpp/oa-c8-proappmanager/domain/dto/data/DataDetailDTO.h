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
#ifndef _DATADETAIL_DTO_
#define _DATADETAIL_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 数据配置详情传输对象
 */
class DataDetailDTO : public oatpp::DTO
{
	DTO_INIT(DataDetailDTO, DTO);

	// 详细信息

	API_DTO_FIELD_DEFAULT(String, data, ZH_WORDS_GETTER("config.detail.field.data"));

	// 应用唯一标识符
	API_DTO_FIELD_DEFAULT(String, appid, ZH_WORDS_GETTER("config.detail.field.appid"));

	// 数据唯一标识符
	API_DTO_FIELD_DEFAULT(String, dataid, ZH_WORDS_GETTER("config.detail.field.dataid"));

	// 应用程序
	//API_DTO_FIELD_DEFAULT(String, application, ZH_WORDS_GETTER("config.detail.field.application"));

	// 配置项名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("config.detail.field.name"));

	// 别名
	API_DTO_FIELD_DEFAULT(String, alias, ZH_WORDS_GETTER("config.detail.field.alias"));

	// 描述信息
	API_DTO_FIELD_DEFAULT(String, description, ZH_WORDS_GETTER("config.detail.field.description"));

	// 创建时间
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("config.detail.field.creatTime"));

	// 更新时间
	API_DTO_FIELD_DEFAULT(String, updateTime, ZH_WORDS_GETTER("config.detail.field.updateTime"));
};
class DataDetailPageDTO : public PageDTO<DataDetailDTO::Wrapper> {
	DTO_INIT(DataDetailPageDTO, PageDTO<DataDetailDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_DATADETAIL_DTO_
