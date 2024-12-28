#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wangye
 @Date: 2024/10/25 14:23:49

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
#ifndef _MENUINFO_DAO_
#define _MENUINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/menuinfo/MenuInfoDO.h"
#include "../../domain/query/menuinfo/MenuInfoQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class MenuInfoDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const MenuInfoQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<MenuInfoDO> selectWithPage(const MenuInfoQuery::Wrapper& query);
	// ͨ�����Ʋ�ѯ����
	list<MenuInfoDO> selectByName(const string& menu_name);
	 //*ͨ��menu_id��ѯ����,�Լ�д�Ĳ�һ���õ���
	list<MenuInfoDO> selectById(const string& menu_id);
	// ��������
	uint64_t insert(const MenuInfoDO& iObj);
	// �޸�����
	int update(const MenuInfoDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t menu_id);
};
#endif // !_MENUINFO_DAO_
