#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/24 00:44:23

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
#ifndef _MODIFY_LOCKORUNLOCK_OFFICERCONTROLLER_
#define _MODIFY_LOCKORUNLOCK_OFFICERCONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/modify/modify_lockorunlock_officerDTO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)


class modify_lockorunlock_officerController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(modify_lockorunlock_officerController);

public:
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("sample.modify.summary"), modify_lock_stat, StringJsonVO::Wrapper);

	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "personal-management/modify-lockorunlock-officer", modify_lock_stat, BODY_DTO(modify_lockorunlock_officerDTO::Wrapper, dto), execModify_lockorunlock_officer(dto));

private:
	StringJsonVO::Wrapper execModify_lockorunlock_officer(const modify_lockorunlock_officerDTO::Wrapper& dto);
};




#include OATPP_CODEGEN_BEGIN(ApiController)

#endif // !_MODIFY_LOCKORUNLOCK_OFFICERCONTROLLER_
