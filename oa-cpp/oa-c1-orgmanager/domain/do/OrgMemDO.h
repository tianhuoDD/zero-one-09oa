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
#ifndef _ORGMEM_DO_
#define _ORGMEM_DO_
#include "../do/DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class OrgMemDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
public:
	OrgMemDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
	}
};

#endif // !_SAMPLE_DO_