#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: HY
 @Date: 2024/10/25 16:09:51

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
#ifndef _CHANGEPERSONPROFILEQUERY_H_
#define _CHANGEPERSONPROFILEQUERY_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 通过个人id更换人员头像
 */
class ChangePersonProfileQuery : public oatpp::DTO
{
	DTO_INIT(ChangePersonProfileQuery, DTO)

	// 用户ID
	DTO_FIELD(String, userId);
	DTO_FIELD_INFO(userId) {
		info->description = ZH_WORDS_GETTER("changeprofile.user.field.id");
	}
	// 头像URL
	API_DTO_FIELD_DEFAULT(String, url, ZH_WORDS_GETTER("changeprofile.user.field.avatarUrl"));

};

#include OATPP_CODEGEN_END(DTO)

#endif 