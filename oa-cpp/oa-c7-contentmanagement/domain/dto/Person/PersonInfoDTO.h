#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Rif
 @Date: 2024/10/19 11:25:10

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
#ifndef _PERSONINFODTO_H_
#define _PERSONINFODTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PersonInfoDTO: public oatpp::DTO
{
	DTO_INIT(PersonInfoDTO, DTO);

	API_DTO_FIELD(String, xname, ZH_WORDS_GETTER("person.query-person.name"), true ,"Rif");
	API_DTO_FIELD(String, xid, ZH_WORDS_GETTER("person.query-person.id"), true ,"007");
	
	//DTO_FIELD(String, name);
	//DTO_FIELD_INFO(name) {
	//	info->description = "Person Info";
	//}
	//DTO_FIELD(String, id);
	//DTO_FIELD_INFO(id) {
	//	info->description = ZH_WORDS_GETTER("sample.field.age");
	//}
};


/**
 * 示例分页传输对象，使用PersonInfoDTO
 */
class PersonInfoPageDTO : public PageDTO<PersonInfoDTO::Wrapper> 
{
	DTO_INIT(PersonInfoPageDTO, PageDTO<PersonInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif    // !_PERSONINFODTO_H_
