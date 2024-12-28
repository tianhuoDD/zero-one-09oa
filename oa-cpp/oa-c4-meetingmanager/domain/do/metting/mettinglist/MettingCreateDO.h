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
#ifndef _MettingList_DO_
#define _MettingList_DO_
#include "../../DoInclude.h"

/**
 * 示例数据库实体类
 */
class MettingListDO
{
	// name
	CC_SYNTHESIZE(string, name,			Names);
	// date
	CC_SYNTHESIZE(string, date,			Dates);
	// timestart
	CC_SYNTHESIZE(string, timestart,	Timestart);
	// timeend
	CC_SYNTHESIZE(string, timeend, Timeend);
	// title
	CC_SYNTHESIZE(string, title, Title);
	// room
	CC_SYNTHESIZE(string, mtroom, Mtroom);
public:
	MettingListDO() {
		name = "";
		date = "";
		timestart = "";
		timeend = "";
		title = "";
		mtroom = "";
	}
};

#endif // !_MettingList_DO_
