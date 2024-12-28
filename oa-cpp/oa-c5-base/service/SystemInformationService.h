#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2024/10/19 17:07:08

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
#ifndef _SYSTEM_INFORMATION_SERVICE_
#define _SYSTEM_INFORMATION_SERVICE_
#include <list>
#include "domain/vo/SystemInformationVO.h"
#include "domain/dto/SystemInformationDTO.h"
#include"dao/SystemInformationDAO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class SystemInformationService
{
public:
	// 数据
	SystemInformationDTO::Wrapper listAll(const std::string&);
};

#endif // !_SYSTEM_INFORMATION_SERVICE_

