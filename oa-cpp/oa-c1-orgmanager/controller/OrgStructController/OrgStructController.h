#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _ORG_STRUCT_CONTROLLER_
#define _ORG_STRUCT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/GlobalInclude.h"
#include "../../domain/vo/OrgStructVO/OrgStructVO.h"
#include "../../domain/query/OrgStructQuery/OrgStructQuery.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*	����: ��֯�ܹ������� 
 * 
 *  ����: 1. ��ȡ��֯��Ա(��ҳ)
 *		 2. ��ȡ��Ա�����б�
 *		 3. �����֯
 *		 4. ɾ����֯
 *		 5. �޸���֯��Ա
 *		 6. ��ѯ��֯��Ա
 */
class OrgStructController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(OrgStructController);

public:
	//�ӿڶ���------------------------------------------------------------------------------
	//��ѯ��֯���г�Ա��Ϣ
	ENDPOINT_INFO(queryOrgStruct) {
		// general
		info->summary = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgMembers.orgmembers");
		info->addResponse<OrgStructPageJsonVO::Wrapper>(Status::CODE_200, "application/json");

		// params specific
		info->queryParams.add<UInt64>("pageIndex").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgMembers.pageIndex");
		info->queryParams.add<UInt64>("pageSize").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgMembers.pageSize");
		//�����ѯ����֯
		info->queryParams.add<String>("xunique").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgMembers.xunique");

	}

	//��Ӧ�ӿ�------------------------------------------------------------------------------
	//��Ӧ��֯���г�Ա��Ϣ
	ENDPOINT("GET", "/c1-org/orgmanagment/queryOrgStruct", queryOrgStruct, QUERIES(QueryParams, params)) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(condtion, OrgStructPageQuery, params);
		//��Ӧ���
		return createDtoResponse(Status::CODE_200, executeQueryOrgStruct(condtion));
	};

	//�����ĵ�������ȡ��Ա�����б�
	//�ӿڶ���------------------------------------------------------------------------------
	//��ȡ��Ա�����б�
	ENDPOINT_INFO(queryOrgStaff) {
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();

		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("queryOrgStaff.orgmembers.members"));
		//API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Attrib_add.title.add"));

		info->addResponse<OrgStructPageJsonVO::Wrapper>(Status::CODE_200, "application/json");

		// ����ӿ�
		info->queryParams.add<UInt64>("pageIndex").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgStaff.orgmembers.pageIndex");

		info->queryParams.add<UInt64>("pageSize").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgStaff.orgmembers.pageSize");
		//����ƴ����ѯ(��ĸ��д)
		info->queryParams.add<String>("Pinyin").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgStaff.orgmembers.Pinyin");

		info->queryParams.add<String>("xdistinguishedName").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgStaff.orgmembers.xdistinguishedName");

		info->queryParams.add<String>("xstatus").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgStaff.orgmembers.xstatus");
	}

	//�ӿ���Ӧ-----------------------------------------------------------------------------------------------------------
	//��Ӧ��Ա�б�
	ENDPOINT("POST", "/c1-org/orgmanagment/Staff", queryOrgStaff, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(condtion, OrgStaffPageQuery, params);
		//��Ӧ���
		return createDtoResponse(Status::CODE_200, executeQueryOrgStaff(condtion));
	};

private:
	//queryOrgStruct���ʺ�ִ�к���
	OrgStructPageJsonVO::Wrapper executeQueryOrgStruct(const OrgStructPageQuery::Wrapper& condtion);
	//queryPeople���ʺ�ִ�к���
	OrgStaffPageJsonVO::Wrapper executeQueryOrgStaff(const OrgStaffPageQuery::Wrapper& condtion);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_ 