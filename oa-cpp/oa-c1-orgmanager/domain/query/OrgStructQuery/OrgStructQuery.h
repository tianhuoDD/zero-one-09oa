#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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

#ifndef _ORGSTRUCTQUERY_H_
#define _ORGSTRUCTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//��ѯ����
class OrgStructQuery : public PageQuery
{
	DTO_INIT(OrgStructQuery, PageQuery);
};


/**
 * ��ҳ��ѯ����
 */
class OrgStructPageQuery : public PageQuery
{
	DTO_INIT(OrgStructPageQuery, PageQuery);
	DTO_FIELD(String, xunique);

	DTO_FIELD(String, xdistinguishedName);
	DTO_FIELD(String, xemployee);
	DTO_FIELD(String, xmail);
	DTO_FIELD(String, xmobile);

};

 /*
	 ���ܣ� ��Ա��ҳ��ѯ����
	 �̳�: PageQuery
	 ����: ��Ϊ�̳��� PageQuery ���� ������ҳ��ѯ��PageInde and PageSize 
	 TODO:����Ĳ�����ǰ�˴���Ĳ���
 */
class OrgStaffPageQuery : public PageQuery
{
	DTO_INIT(OrgStaffPageQuery, PageQuery);

	DTO_FIELD(String, xdistinguishedName); // ��������(������ΪΨһ����)

	DTO_FIELD(String, Pinyin);

	DTO_FIELD(String, xmobile); // �绰����

	DTO_FIELD(String, xstatus); // �绰����
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ORGSTRUCTQUERY_H_