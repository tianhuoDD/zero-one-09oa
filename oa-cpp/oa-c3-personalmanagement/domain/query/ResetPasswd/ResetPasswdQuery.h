#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/10/20 20:07:19

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
#ifndef _RESETPASSWDQUERY_H_
#define _RESETPASSWDQUERY_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 通过个人id重置人员密码
 */
class ResetPasswdQuery : public oatpp::DTO
{
	DTO_INIT(ResetPasswdQuery, DTO)

	// 个人id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description =
			ZH_WORDS_GETTER("personal-management.reset-passwd.field.id");
	}

	// 密文
	DTO_FIELD(String, passwd);
	DTO_FIELD_INFO(passwd) {
		info->description =
			ZH_WORDS_GETTER("personal-management.reset-passwd.field.passwd");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RESETPASSWDQUERY_H_
