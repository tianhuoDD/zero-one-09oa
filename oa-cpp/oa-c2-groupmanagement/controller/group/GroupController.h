#pragma once
#ifndef _GROUP_CONTROLLER_
#define _GROUP_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/group/GroupDTO.h"
#include "domain/vo/group/GroupVO.h"
#include "domain/query/user/UserQuery.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class GroupController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(GroupController);
	// 3 定义接口
public:
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("group.put.summary"), modifyGroup, StringJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/group", modifyGroup, BODY_DTO(GroupDTO::Wrapper, dto), executeModifyGroup(dto));

	ENDPOINT_INFO(queryUser) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("role.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(UserPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(Int32, "id", ZH_WORDS_GETTER("role.field.id"), 1, true);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/role-info", queryUser, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryUser(id));
	}
private:
	// 3.3 演示修改数据
	StringJsonVO::Wrapper executeModifyGroup(const GroupDTO::Wrapper& dto);

	UserPageJsonVO::Wrapper executeQueryUser(const String& id);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _GROUP_CONTROLLER_