#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: upup
 @Date: 2024/10/23 1:05:55

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
#ifndef _MODIFY_PERSONAL_IDENTITYDAO_
#define _MODIFY_PERSONAL_IDENTITYDAO_
#include "BaseDAO.h"
#include "../../domain/do/modify/org_identitypersonDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class modify_personal_identityDAO : public BaseDAO
{
public:
	// �޸�����
	int update(const org_identitypersonDO& uObj);
};
#endif 

