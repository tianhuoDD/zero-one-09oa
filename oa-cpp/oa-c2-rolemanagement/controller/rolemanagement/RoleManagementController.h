#pragma once

#ifndef _ROLEMANAGEMENTCONTROLLER_H_
#define _ROLEMANAGEMENTCONTROLLER_H_

#include "stdafx.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include "oatpp/core/data/mapping/type/Object.hpp"
#include <iostream>
#include <sstream>
#include "domain/do/get/roleresource/RoleResourceDO.h"
#include "service/TreeRoleResourceInfoMapper.h"
#include "tree/TreeUtil.h"
#include "service/rolemanagement/RoleManagementService/put/addrole/AddroleService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "service/rolemanagement/RoleManagementService/get/queryrole/QueryRoleService.h"
#include "service/rolemanagement/RoleManagementService.h"
#include "domain/vo/BaseJsonVO.h"	
#include "domain/GlobalInclude.h"
#include "domain/dto/rolemanagement/RoleManagementDTO/put/addrole/AddroleDTO.h"
#include "domain/vo/put/Addrole/AddroleVO.h"
#include "domain/query/get/queryrole/QueryRoleQuery.h"
#include "domain/dto/rolemanagement/RoleManagementDTO/get/queryrole/QueryRoleDTO.h"
#include "domain/vo/get/queryrole/QueryRoleVO.h"
#include "domain/dto/rolemanagement/RoleManagementDTO/get/GetroleDTO.h"
#include "domain/vo/get/GetroleVO.h"
#include "domain/dto/put/groupmember/GroupMemberDTO.h"
#include "domain/vo/get/roleresource/RoleResourceVO.h"
//#include "domain/dto/post/roleresource/RoleResourceInfoDTO.h"
#include "domain/dto/post/roleresource/RoleResourceListDTO.h"
#include "domain/dto/put/updaterole/UpdateRoleDTO.h"
//#include "domain/dto/put/updaterole/UpdateRoleDTO.h"
#include "domain/query/get/PersonListQuery/PersonListQuery.h"
//#include "domain/dto/get/personlist/PersonListDTO.h"
#include "domain/vo/get/personlist/PersonListVO.h"
#include"domain/dto/rolemanagement/RoleManagementDTO/put/personmember/PersonMemberDTO.h"
#include"domain/vo/get/getpersonmember/GetPersonMemberVO.h"
#include "domain/query/get/getpersonmember/GetPersonMemberQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class RoleManagementController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(RoleManagementController);
public:
	//xiaodeng-----
	
	//删除群组成员
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("role.put.adddelgroupmember.summary"), delgroupmember, Uint64JsonVO::Wrapper);
	// 
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/role/del-groupmember", delgroupmember, BODY_DTO(GroupMemberDTO::Wrapper, idList), execDelGroupMember(idList));

	// 3.1 增加群组成员
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("role.put.adddelgroupmember.summary"), addgroupmember, Uint64JsonVO::Wrapper);
	// 
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/role/add-groupmember", addgroupmember, BODY_DTO(GroupMemberDTO::Wrapper, idList), execAddGroupMember(idList));

	// 获取角色资源
	ENDPOINT_INFO(obtainRoleResource) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("role.get.roleResource.summary"), RoleResourceJsonVO::Wrapper);
	}
	// 
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/role/obtain-role-resource", obtainRoleResource, QUERY(String, id), execObtainRoleResource(id, authObject->getPayload()));

	// 3.1 定义修改角色资源接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("role.put.modifyAssignmentResource.summary"), modifyroleresource, Uint64JsonVO::Wrapper);
	// 3.2 定义修改角色资源接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/role/modify-role-resource", modifyroleresource, BODY_DTO(RoleResourceListDTO::Wrapper, roleResource), execModifyRoleResource(roleResource));
	// 3.1 定义新增接口描述
	//xiaodeng---- -

	ENDPOINT_INFO(addRole) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("addrole.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// 定义其他参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("addrole.put.name"), "name", true);
		API_DEF_ADD_QUERY_PARAMS(String, "unique", ZH_WORDS_GETTER("addrole.put.unique"), "unique", true);
		API_DEF_ADD_QUERY_PARAMS(String, "description", ZH_WORDS_GETTER("addrole.put.desc"), "desc", true);
	}
	// 3.2 定义新增接口处理 , API_HANDLER_AUTH_PARAME
	ENDPOINT(API_M_POST, "/role/add-role", addRole, BODY_DTO(AddroleDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddRole(dto));
	}
/// ////////////////获取角色信息与删除角色//////////////////
    // 获取角色信息
    ENDPOINT_INFO(queryGetrole) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("addroleDTO.information"));
        // 定义默认授权参数（可选定义）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(GetroleJsonVO);
        // 定义查询参数描述
        API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("addroleDTO.field.key"), "", true);
    }

    // 定义查询接口处理
    ENDPOINT(API_M_GET, "/role/query_roleinfo", queryGetrole, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(executQueryGetRole(id));
    }



    // 删除角色
    // 3.1 定义删除接口描述
    ENDPOINT_INFO(removeSample) {
        // 定义标题和返回类型以及授权支持
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("addroleDTO.del"), String);
        // 定义其他路径参数说明
        API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("addroleDTO.field.key"), "", true);
    }

    // 3.2 定义删除接口处理
	ENDPOINT(API_M_DEL, "/role/del-role", removeSample, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execRemoveRole(id));
	}



/// ////////////////获取角色信息与删除角色//////////////////

	//修改role lhg
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("modifyrole.summary"), modifyRole, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/role/modify-role", modifyRole, BODY_DTO(UpdateRoleDTO::Wrapper, dto), execModifyRole(dto));

	//获取角色的personlist(分页) lhg
	ENDPOINT_INFO(queryPersonList) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("querypersonlist.summary"), PersonListPageJsonVO::Wrapper);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "xunique", ZH_WORDS_GETTER("querypersonlist.unique"), "xxxx", true);
	}
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/role/query-person-list", queryPersonList, PersonListQuery, execQueryPersonList(query, authObject->getPayload()));

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryRolelist) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("rolelist.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(QueryRolePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "key", ZH_WORDS_GETTER("rolelist.field.words"), "key", false);	
	}
	// 3.2 定义查询接口处理 , API_HANDLER_AUTH_PARAME
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/role/query-role-name", queryRolelist, QUERIES(QueryParams, queryParams),API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, QueryRoleQuery, queryParams);
		// 呼叫执行函数响应结果 authObject->getPayload()
		API_HANDLER_RESP_VO(execQueryRolelist(userQuery));
	}

	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------



	//定义添加接口描述
	ENDPOINT_INFO(addMember) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("PersonMember.put.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//定义新增接口处理
	ENDPOINT(API_M_PUT, "/role/add-person-member", addMember, BODY_DTO(PersonMemberDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddMember(dto));
	}
	//删除群组成员
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("PersonMember.delete.summary"), delpersonmember, Uint64JsonVO::Wrapper);
	// 
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/role/del-person-member", delpersonmember, BODY_DTO(PersonMemberDTO::Wrapper, xpersonList), execDelPersonMember(xpersonList));

	// 定义查询接口描述
	ENDPOINT_INFO(queryPersonMember) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("PersonMember.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetPersonMemberPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "ROLE_XID", ZH_WORDS_GETTER("PersonMember.field.ROLE_XID"), "role_xid", true);
		
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/role/query-person-member", queryPersonMember, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, GetPersonMemberQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execGetPersonMember(userQuery, authObject->getPayload()));
	}
private:
	//执行增删群组成员
	Uint64JsonVO::Wrapper execAddGroupMember(const GroupMemberDTO::Wrapper& idList);
	Uint64JsonVO::Wrapper execDelGroupMember(const GroupMemberDTO::Wrapper& idList);
	RoleResourceJsonVO::Wrapper execObtainRoleResource(const String roleId, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execModifyRoleResource(const RoleResourceListDTO::Wrapper& roleResource);
	//lhg
	Uint64JsonVO::Wrapper execModifyRole(const UpdateRoleDTO::Wrapper& dto);
	//lhg
	PersonListPageJsonVO::Wrapper execQueryPersonList(const PersonListQuery::Wrapper& query, const PayloadDTO& payload);
	StringJsonVO::Wrapper execAddDelGroupMember(const GroupMemberDTO::Wrapper& idList);
	//执行增加角色
	Uint64JsonVO::Wrapper execAddRole(const AddroleDTO::Wrapper& dto);
	// 分页查询角色名称	, const PayloadDTO& payload
	QueryRolePageJsonVO::Wrapper execQueryRolelist(const QueryRoleQuery::Wrapper& query);

    //获取角色信息
    GetroleJsonVO::Wrapper executQueryGetRole(const String& id);

   //删除角色
    StringJsonVO::Wrapper execRemoveRole(const String& id);




	// 增加个人成员
	Uint64JsonVO::Wrapper execAddMember(const PersonMemberDTO::Wrapper& dto);

	// 删除成员
	Uint64JsonVO::Wrapper execDelPersonMember(const PersonMemberDTO::Wrapper& xpersonList);
	
	// 演示分页查询数据
	GetPersonMemberPageJsonVO::Wrapper execGetPersonMember(const GetPersonMemberQuery::Wrapper& query, const PayloadDTO& payload);
};


#include OATPP_CODEGEN_END(ApiController)

#endif // !_ROLEMANAGEMENTCONTROLLER_H_
