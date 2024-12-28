#include"stdafx.h"
#include"QueryGroupMemberController.h"
#include"../../service/GroupMember/GroupMemberServer.h"

GetGroupMemberPageJsonVO::Wrapper QueryGroupMemberController::execQueryGroupMember(const GroupMemberQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	GroupMemberService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = GetGroupMemberPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
