#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: กฃบร
 @Date: 2024/10/31 16:38:52

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
#ifndef _PASSWDEXPIREDTIMESERVICE_H_
#define _PASSWDEXPIREDTIMESERVICE_H_

#include "stdafx.h"
#include "ApiHelper.h"
#include "domain/do/org_personDo/org_personDO.h"
#include "domain/query/PasswdExpiredTime/PasswdExpiredTimeQuery.h"
#include "domain/dto/PasswdExpiredTime/PasswdExpiredTimeDTO.h"

class PasswdExpiredTimeService {
public:
	std::string setPasswdExpiredTime(const PasswdExpiredTimeQuery::Wrapper& query);
};


#endif // !_PASSWDEXPIREDTIMESERVICE_H_