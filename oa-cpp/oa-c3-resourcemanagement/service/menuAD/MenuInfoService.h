#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wangye
 @Date: 2024/10/24 15:13:11

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
#ifndef _MENUINFO_SERVICE_
#define _MENUINFO_SERVICE_
#include <list>
#include "domain/vo/menuinfo/MenuInfoVO.h"
#include "domain/query/menuinfo/MenuInfoQuery.h"
#include "domain/dto/menuinfo/MenuInfoDTO.h"

/**
 *  * �ο�arch-demoд�ģ�����36�е����ݸ�ʽ���������⣬ͬʱMenuInfoService.h����Ƿ�ҳ��ѯ���߼�������Ҫ�Ժ�����
 */
class MenuInfoService
{
public:
	// ��ҳ��ѯ��������
	MenuInfoPageDTO::Wrapper listAll(const MenuInfoQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const MenuInfoDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const MenuInfoDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t menu_id);
	// ��ѯ����
	MenuInfoDTO::Wrapper queryData(const string& menu_id);
};

#endif // !_MENUINFO_SERVICE_

