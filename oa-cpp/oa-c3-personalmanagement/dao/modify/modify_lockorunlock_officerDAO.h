#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/31 19:05:23

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
#ifndef _MODIFY_LOCKORUNLOCK_OFFICERDAO_
#define _MODIFY_LOCKORUNLOCK_OFFICERDAO_

#include "BaseDAO.h"

#include "domain/do/org_personDo/org_personDO.h"

class modify_lockorunlock_officerDAO : public BaseDAO
{
public:
	int update(const org_personDO& uObj);
};

#endif // !_MODIFY_LOCKORUNLOCK_OFFICERDAO_
