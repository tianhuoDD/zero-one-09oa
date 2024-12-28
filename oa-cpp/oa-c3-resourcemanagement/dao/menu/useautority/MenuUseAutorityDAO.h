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
#ifndef _MENUUSEAUTORITY_DAO_
#define _MENUUSEAUTORITY_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/org_role_menulistDO/org_role_menulistDO.h"
#include "../../../domain/query/mymenu/useautority/MenuUseAutorityQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class MenuUseAutorityDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const MenuUseAutorityQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<Org_role_menulistDO> selectWithPage(const MenuUseAutorityQuery::Wrapper& query);

	//// ͨ��������ѯ����
	//list<MenuUseAutorityDO> selectByName(const string& name);
	//// ��������
	//uint64_t insert(const MenuUseAutorityDO& iObj);
	//// �޸�����
	//int update(const MenuUseAutorityDO& uObj);
	//// ͨ��IDɾ������
	//int deleteById(uint64_t aid);
};
#endif // !_SAMPLE_DAO_