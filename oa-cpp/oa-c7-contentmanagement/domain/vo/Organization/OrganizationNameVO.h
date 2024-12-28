#pragma once 
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Rif
 @Date: 2024/10/19 11:49:34

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
#ifndef _ORGANIZATIONNAMEVO_H_
#define _ORGANIZATIONNAMEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Organization/OrganizationNameDTO.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class OrganizationNameVO : public oatpp::DTO
{
	DTO_INIT(OrganizationNameVO, DTO);
	
	//DTO_FIELD(String, name);
	//DTO_FIELD_INFO(name) {
	//	info->description = "Organization Name";
	//}

	DTO_FIELD(List<Object<OrganizationNameDTO>>, list);
	//API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("organization.query-organization.name"), true ,"01 School");
	//API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("organization.query-organization.id"), true ,"002");
	//API_DTO_FIELD(String, pid, ZH_WORDS_GETTER("organization.query-organization.pid"), true ,"001");

	//DTO_FIELD(String, id);
	//DTO_FIELD_INFO(id) {
	//	info->description = ZH_WORDS_GETTER("sample.field.age");
	//}
};

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class OrganizationNamePageJsonVO: public JsonVO<OrganizationNamePageDTO::Wrapper> {
	DTO_INIT(OrganizationNamePageJsonVO, JsonVO<OrganizationNamePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORGANIZATIONNAMEVO_H_