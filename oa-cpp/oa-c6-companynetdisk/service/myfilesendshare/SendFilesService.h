#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _SENDFILES_SERVICE_
#define _SENDFILES_SERVICE_
#include <list>
#include "../../domain/dto/myfiles/SendFilesDTO.h"
#include "../../domain/dto/myfile/FilelogDTO.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class SendFilesService
{
public:
	// 保存数据
	uint64_t saveData(const SendFilesDTO::Wrapper& dto);
	uint64_t insertSendLog(const FileLogDTO::Wrapper& ddto);
};

#endif // !_SENDFILES_SERVICE_

