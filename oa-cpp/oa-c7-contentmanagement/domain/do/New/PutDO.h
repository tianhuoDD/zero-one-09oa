#pragma once
#pragma once
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
#ifndef _PUT_DO_
#define _PUT_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class PutDO
{
	// 编号

	   // 姓名
	 
	   CC_SYNTHESIZE(string, xappicon, Xappicon);
	   CC_SYNTHESIZE(string, xallPeopleViem, XallPeopleViem);
	   CC_SYNTHESIZE(string, xallPeoplePublish, XallPeoplePublish);
	   CC_SYNTHESIZE(string, xcreatorPerson, XcreatorPerson);


public:
	PutDO() {
		xappicon = "";
		xallPeopleViem = "";
		xallPeoplePublish = "";
		xcreatorPerson = "";

	}
};

#endif // !_SAMPLE_DO_
