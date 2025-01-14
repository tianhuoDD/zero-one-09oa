#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/10/20 17:53:51

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
#ifndef _PASSWDEXPIREDTIMEDTO_H_
#define _PASSWDEXPIREDTIMEDTO_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PasswdExpiredTimeDTO : public oatpp::DTO
{
	DTO_INIT(PasswdExpiredTimeDTO, DTO)

	// 人员id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = 
			ZH_WORDS_GETTER("personalmanagement.passwd-expired-time.field.id");
	}

	// 日期
	DTO_FIELD(String, date);
	DTO_FIELD_INFO(date) {
		info->description = 
			ZH_WORDS_GETTER("personalmanagement.passwd-expired-time.field.date");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PASSWDEXPIREDTIMEDTO_H_