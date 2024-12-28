#pragma once
#ifndef _QUERYGROUPMEMBER_CONTROLLER_
#define _QUERYGROUPMEMBER_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include"domain/vo/GroupMember/GetGroupMemberVO.h"
#include"domain/dto/GroupMember/GetGroupMemberDTO.h"
#include "domain/query/GroupMember/GroupMemberQuery.h"
//定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class QueryGroupMemberController : public oatpp::web::server::api::ApiController //继承控制器
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(QueryGroupMemberController);
	//定义接口
public:
	//定义查询接口描述
	ENDPOINT_INFO(queryGroupMember) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("queryGroupMember.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetGroupMemberPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "groupname", ZH_WORDS_GETTER("queryGroupMember.field.name"), "zero-one", true);
		API_DEF_ADD_QUERY_PARAMS(String, "groupnameA", ZH_WORDS_GETTER("queryGroupMember.field.sex"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "groupdes", ZH_WORDS_GETTER("queryGroupMember.field.sex"), "", false);
	}
	//定义查询接口处理
	ENDPOINT(API_M_GET, "/queryGroupMember", queryGroupMember, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, GroupMemberQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryGroupMember(userQuery, authObject->getPayload()));
	}
private:
	//分页查询数据
	GetGroupMemberPageJsonVO::Wrapper execQueryGroupMember(const GroupMemberQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _QUERYGROUPMEMBER_CONTROLLER_