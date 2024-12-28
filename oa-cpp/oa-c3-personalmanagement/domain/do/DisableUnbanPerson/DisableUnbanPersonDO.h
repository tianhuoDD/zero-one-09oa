#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _DISABLEUNBANPERSON_DO_
#define _DISABLEUNBANPERSON_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class DisableUnbanPersonDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);

	// 状态
	CC_SYNTHESIZE(uint64_t, state, State);
public:
	DisableUnbanPersonDO() {
		id = 0;
		state = 1;
	}
};

#endif // !_SAMPLE_DO_
