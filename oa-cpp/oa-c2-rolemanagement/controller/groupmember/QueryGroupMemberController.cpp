#include"stdafx.h"
#include"QueryGroupMemberController.h"
#include"../../service/GroupMember/GroupMemberServer.h"

GetGroupMemberPageJsonVO::Wrapper QueryGroupMemberController::execQueryGroupMember(const GroupMemberQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	GroupMemberService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = GetGroupMemberPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
