#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wangye
 @Date: 2024/10/24 23:36:29

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
#ifndef _MENUINFO_QUERY_
#define _MENUINFO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  * �ο�arch-demoд�ģ�ͬʱMenuInfoQuery.h����Ƿ�ҳ��ѯ���߼�������Ҫ�Ժ�����
 */
class MenuInfoQuery : public PageQuery
{
	DTO_INIT(MenuInfoQuery, PageQuery);
	// ����
	DTO_FIELD(String, menu_name);
	DTO_FIELD_INFO(menu_name) {
		info->description = ZH_WORDS_GETTER("menuinfo.field.orgname");
	}
	// Ψһ���
	DTO_FIELD(String, menu_id);
	DTO_FIELD_INFO(menu_id) {
		info->description = ZH_WORDS_GETTER("menuinfo.field.id");
	}
	//// ���
	//DTO_FIELD(String, orgabbreviation);
	//DTO_FIELD_INFO(orgabbreviation) {
	//	info->description = ZH_WORDS_GETTER("menuinfo.field.orgabbreviation");
	//}
	//// ����ֵ
	//DTO_FIELD(UInt64, sortingvalue);
	//DTO_FIELD_INFO(sortingvalue) {
	//	info->description = ZH_WORDS_GETTER("menuinfo.field.sortingvalue");
	//}
	//// ͼ��λ��
	//DTO_FIELD(String, orgicon);
	//DTO_FIELD_INFO(orgicon) {
	//	info->description = ZH_WORDS_GETTER("menuinfo.field.orgicon");
	//}
	//// ��֯����
	//DTO_FIELD(String, orgdescription);
	//DTO_FIELD_INFO(orgdescription) {
	//	info->description = ZH_WORDS_GETTER("menuinfo.field.orgdescription");
	//}
	// ��֯���
	DTO_FIELD(UInt64, menu_type);
	DTO_FIELD_INFO(menu_type) {
		info->description = ZH_WORDS_GETTER("menuinfo.field.orgcategory");
	}
	// �ϼ���֯
	DTO_FIELD(String, parent_id);
	DTO_FIELD_INFO(parent_id) {
		info->description = ZH_WORDS_GETTER("menuinfo.field.orgup");
	}
	//// ��������
	//DTO_FIELD(String, manager);
	//DTO_FIELD_INFO(manager) {
	//	info->description = ZH_WORDS_GETTER("menuinfo.field.manager");
	//}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MENUINFO_QUERY_