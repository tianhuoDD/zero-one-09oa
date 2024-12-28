#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: HY
 @Date: 2024/10/25 16:25:15

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
#ifndef _CHANGEPERSONPROFILEDTO_H_
#define _CHANGEPERSONPROFILEQUERY_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 向下层传递人员id和头像
 */
class ChangePersonProfileDTO : public oatpp::DTO
{
	DTO_INIT(ChangePersonProfileDTO, DTO)

    // 用户ID
    DTO_FIELD(String, xid);
    DTO_FIELD_INFO(xid) {
        info->description = ZH_WORDS_GETTER("changeprofile.user.field.id"); 
    }

    // 头像URL
    API_DTO_FIELD_DEFAULT(String, xicon, ZH_WORDS_GETTER("changeprofile.user.field.xiconUrl"));
    API_DTO_FIELD_DEFAULT(String, xiconLdpi, ZH_WORDS_GETTER("changeprofile.user.field.xiconLdpiUrl"));
    API_DTO_FIELD_DEFAULT(String, xiconMdpi, ZH_WORDS_GETTER("changeprofile.user.field.xiconMdpiUrl"));
};

#include OATPP_CODEGEN_END(DTO)

#endif 