#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/23 23:09:12

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
#ifndef _MODIFY_PERSONAL_IDENTITYSERVICE_
#define _MODIFY_PERSONAL_IDENTITYSERVICE_
#include <list>
#include "../../domain/dto/modify/modify_personal_identityDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class modify_personal_identityService
{
public:

	// 修改数据
	bool updateData(const modify_personal_identityDTO::Wrapper& dto);

};

#endif // !_MODIFY_PERSONAL_identitySERVICE_

