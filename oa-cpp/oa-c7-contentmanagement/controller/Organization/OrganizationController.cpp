

#include "stdafx.h"
#include "OrganizationController.h"
#include "../../service/OrganizationService.h"
#include "../../domain/vo/Organization/OrganizationMemberVO.h"

OrganizationNamePageJsonVO::Wrapper OrganizationController::execcuteQueryOrganizationInfo(const OrgQuery::Wrapper&query)
{
	//// ����һ��Service
	OrganizationService service;
	//// ��ѯ����
	auto result = service.queryOrg(query);
	//// ��Ӧ���
	auto jvo = OrganizationNamePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

OrganizationMemberPageJsonVO::Wrapper OrganizationController::execcuteQueryOrganizationMember(const OrgQuery::Wrapper&query)
{
	// ����һ��Service
	OrganizationService service;
	//// ��ѯ����
	auto result = service.queryOrgMem(query);
	//// ��Ӧ���

	auto jvo = OrganizationMemberPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}