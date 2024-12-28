#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/23 23:54:38

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
#ifndef _LIST_PERSONAL_IDENTITYDTO_
#define _LIST_PERSONAL_IDENTITYDTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class list_personal_identityDTO : public oatpp::DTO 
{
	DTO_INIT(list_personal_identityDTO, DTO);
	//身份名称
	DTO_FIELD(String, xname);
	DTO_FIELD_INFO(xname) {
		info->description = ZH_WORDS_GETTER("sample.field.xname");
	}
	//所在组织
	DTO_FIELD(String, xunitName);
	DTO_FIELD_INFO(xunitName) {
		info->description = ZH_WORDS_GETTER("sample.field.xunitName");
	}
	//唯一编码
	DTO_FIELD(String, xid);
	DTO_FIELD_INFO(xid) {
		info->description = ZH_WORDS_GETTER("sample.field.xid");
	}
	//担任职务
	DTO_FIELD(String, xdistinguishedName);
	DTO_FIELD_INFO(xdistinguishedName) {
		info->description = ZH_WORDS_GETTER("sample.field.xdistinguishedName");
	}
	//主身份
	DTO_FIELD(Boolean, xmajor);
	DTO_FIELD_INFO(xmajor) {
		info->description = ZH_WORDS_GETTER("sample.field.xmajor");
	}
};
//分页传输
class listPageDTO : public PageDTO<list_personal_identityDTO::Wrapper>
{
	DTO_INIT(listPageDTO, PageDTO<list_personal_identityDTO::Wrapper>);

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_LIST_PERSONAL_IDENTITYDTO_
