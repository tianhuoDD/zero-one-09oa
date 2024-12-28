#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _ACRE_DAO_
#define _ACRE_DAO_
#include "BaseDAO.h"
//#include "../../domain/do/sample/SampleDO.h"
//#include "../../domain/query/sample/SampleQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class AcReDAO : public BaseDAO
{
public:

	// ��������
	uint64_t insertAccept(const string& meetingId, const string& userId);
	uint64_t insertRefuse(const string& meetingId, const string& userId);

private:
	uint64_t countAccept(const string& meetingId);
	uint64_t countRefuse(const string& meetingId);

};
#endif // !_ACRE_DAO_
