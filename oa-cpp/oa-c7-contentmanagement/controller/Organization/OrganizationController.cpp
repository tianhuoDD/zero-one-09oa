

#include "stdafx.h"
#include "OrganizationController.h"
#include "../../service/OrganizationService.h"
#include "../../domain/vo/Organization/OrganizationMemberVO.h"

OrganizationNamePageJsonVO::Wrapper OrganizationController::execcuteQueryOrganizationInfo(const OrgQuery::Wrapper&query)
{
	//// 定义一个Service
	OrganizationService service;
	//// 查询数据
	auto result = service.queryOrg(query);
	//// 响应结果
	auto jvo = OrganizationNamePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

OrganizationMemberPageJsonVO::Wrapper OrganizationController::execcuteQueryOrganizationMember(const OrgQuery::Wrapper&query)
{
	// 定义一个Service
	OrganizationService service;
	//// 查询数据
	auto result = service.queryOrgMem(query);
	//// 响应结果

	auto jvo = OrganizationMemberPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}