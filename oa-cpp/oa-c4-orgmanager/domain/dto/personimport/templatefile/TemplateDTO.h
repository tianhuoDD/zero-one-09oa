#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/18 15:01:29

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
#ifndef _TEMPLATEDTO_H_
#define _TEMPLATEDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * import模板表的传输数据对象
 */
class TemplateDTO : public oatpp::DTO
{
	DTO_INIT(TemplateDTO, DTO);
	// 模板表src
	API_DTO_FIELD(String, url, ZH_WORDS_GETTER("file.field.template-url"), true, {});
	// 模板表文字描述
	API_DTO_FIELD_DEFAULT(String, alt, ZH_WORDS_GETTER("file.field.template-alt"));
	// 模板表链接地址
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("file.field.template-href"));
public:
	TemplateDTO() {}
	TemplateDTO(String url, String alt = "", String href = "") 
	{
		this->url = url;
		this->alt = alt;
		this->href = href;
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TEMPLATEDTO_H_