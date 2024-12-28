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
#ifndef _ADMINPWD_SERVICE_
#define _ADMINPWD_SERVICE_
#include <list>
#include "domain/vo/password/admin/AdminPwdVO.h"
#include "domain/dto/password/admin/AdminPwdDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class adminPwdService
{
public:

	// �޸�����
	bool updateData(const AdminPwdDTO::Wrapper& dto);


};

#endif // !_ADMINPWD_SERVICE_

