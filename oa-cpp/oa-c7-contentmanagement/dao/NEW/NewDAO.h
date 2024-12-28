#pragma once
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
#ifndef _NEW_DAO_
#define _NEW_DAO_
#include "BaseDAO.h"
#include "../../domain/do/New/NewDO.h"
#include "../../domain/dto/New/NewDTO.h"
#include "../../domain/vo/New/NewVO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class NewDAO : public BaseDAO
{
public:
	// ͳ����������
	
	list<NewDO> selectById(string id);

};
#endif // !_SAMPLE_DAO_
