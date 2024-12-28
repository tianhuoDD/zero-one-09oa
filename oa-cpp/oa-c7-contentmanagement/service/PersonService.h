
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Rif
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
#ifndef _PERSON_SERVICE_
#define _PERSON_SERVICE_
#include <list>
#include "domain/vo/Person/PersonInfoVO.h"
#include "domain/dto/Person/PersonInfoDTO.h"
#include "dao/Person/PersonInfoDAO.h"
#include "domain/query/PersonQuery.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class PersonService
{
public:
	// ��ҳ��ѯ��������
	PersonInfoPageDTO::Wrapper queryPer(const PersonQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_

