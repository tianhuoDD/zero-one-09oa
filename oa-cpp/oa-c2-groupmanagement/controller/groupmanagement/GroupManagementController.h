#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/10/18 17:44:27

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
#ifndef _GROUPMANAGEMENTCONTROLLER_H_
#define _GROUPMANAGEMENTCONTROLLER_H_

#include <domain/dto/groupMember/add/AddGroupMemberDTO.h>
#include <domain/dto/groupMember/del/DelGroupMemberDTO.h>
#include <domain/dto/unitMember/del/DelUnitMemberDTO.h>
#include <domain/vo/groupMember/add/AddGroupMemberVO.h>
#include <domain/vo/unitMember/add/AddUnitMemberVO.h>

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/get/IDmemberVO.h"
#include "domain/dto/get/IDmemberDTO.h"
#include "domain/dto/put/AddPersonDTO.h"
#include "domain/vo/put/AddPersonVO.h"
#include "domain/query/get/IDmemberQuery.h"
#include "domain/dto/del/RemovePersonDTO.h"
//#include "domain/vo/del/RemovePersonVO.h"
//#include "domain/vo/get/IDmemberVO.h"
//#include "domain/dto/get/IDmemberDTO.h"
#include "domain/vo/get/GroupListVO.h"
#include "domain/dto/get/GroupListDTO.h"
#include "domain/query/get/GroupListQuery.h"

#include "domain/dto/put/AddPersonDTO.h"
#include "domain/vo/put/AddPersonVO.h"

#include "domain/dto/put/AddOrRemoveIdentityMembers/AddOrRemoveIdentityMembersDTO.h"
#include "domain/vo/get/GetGroupMembers/GetGroupMembersVO.h"
#include "domain/vo/get/GetOrganizationMembers/GetOrganizationMembersVO.h"




#include "domain/vo/get/GroupListVO.h"
#include "domain/dto/get/GroupListDTO.h"
#include "domain/query/get/GroupListQuery.h"
#include "domain/query/PageQuery.h"

#include "../../domain/vo/get/GetGroupInfo/GetGroupInfoVO.h"
#include "../../domain/vo/delete/DeleteGroup/DeleteGroupVO.h"


#include "domain/vo/group/GroupVO.h"
#include "domain/dto/group/GroupDTO.h"
#include "domain/query/user/UserQuery.h"


#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class GroupManagementController : public oatpp::web::server::api::ApiController
{
	//柠檬味汽水---------------------------------------------------------------------
	
	// 定义控制器访问入口
	API_ACCESS_DECLARE(GroupManagementController);
public: // 定义接口
	//查询身份成员
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryIDmember) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("organization.group.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(IDmemberPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xunitLevelName", ZH_WORDS_GETTER("organization.group.field.xunitLevelName"), ZH_WORDS_GETTER("organization.group.field.yname.qqcy"), false);
	}
	// 3.2 定义查询接口处理
	//ENDPOINT(API_M_GET, "/organization-group/id-member", queryIDmember, QUERY(String, xunique), API_HANDLER_AUTH_PARAME) {
	ENDPOINT(API_M_GET, "/organization-group/id-member", queryIDmember, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(idmemberQuery, IDmemberQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryIDmember(idmemberQuery, authObject->getPayload()));
	}

	//增加个人成员
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addPerson) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("organization.group.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AddPersonJsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/organization-group/add-person", addPerson, BODY_DTO(AddPersonDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddPerson(dto));
	}

	//删除个人成员
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removePerson) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("organization.group.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		//API_DEF_ADD_PATH_PARAMS(Vector<String>, "group_person", ZH_WORDS_GETTER("organization.group.field.group_person"), Vector<String>{}, true);
		API_DEF_ADD_PATH_PARAMS(String, "group_person", ZH_WORDS_GETTER("organization.group.field.group_person"), "1", true);
	}
	// 3.2 定义删除接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/organization-group/delete-person/{group_person}", removePerson, PATH(Vector<String>, group_person), execRemovePerson(group_person));

	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/organization-group/delete-person/{group_person}", removePerson, PATH(String, group_person), execRemovePerson(group_person));
	// //柠檬味汽水---------------------------------------------------------------------

	//fake   -----------------------------------------------------------------------------------------------------------------------



	//定义群组成员的新增处理接口（可以批量操作）
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("groupMember.add.put.summary"), addGroupMember, AddGroupMemberJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/groupMember/add", addGroupMember, BODY_DTO(AddGroupMemberReqDTO::Wrapper, dto), execAddGroupMember(dto, authObject->getPayload()));
	//定义群组成员的删除处理接口（可以批量操作）
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("groupMember.del.put.summary"), delGroupMember, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/groupMember/del", delGroupMember, BODY_DTO(DelGroupMemberDTO::Wrapper, dto), execDelGroupMember(dto));

	//定义组织成员的新增接口处理（可以批量操作）
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("unitMember.add.put.summary"), addUnitMember, AddUnitMemberJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/unitMember/add", addUnitMember, BODY_DTO(AddUnitMemberReqDTO::Wrapper, dto), execAddUnitMember(dto));
	//定义组织成员的删除接口处理（可以批量操作）
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("unitMember.del.put.summary"), delUnitMember, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/unitMember/del", delUnitMember, BODY_DTO(DelUnitMemberDTO::Wrapper, dto), execDelUnitMember(dto));



	

	//fake   -----------------------------------------------------------------------------------------------------------------------



	//就一年   没有天花板  ---------------------------------------------=======--------------------------------------------------------------

	//获取群组列表
	ENDPOINT_INFO(queryGroupList) {
		// general
		// 定义标题;
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("grouplist.get.summary"));
		//定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义分页查询参数描述
		API_DEF_ADD_RSP_JSON_WRAPPER(GroupListPageJsonVO);
		// 定义其他查询参数描述 
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("group.field.id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("group.field.name"), "string", false);
	}
	//定义群组查询接口
	ENDPOINT(API_M_GET, "/organization-group/id-grouplist", queryGroupList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {

		//解析参数
		API_HANDLER_QUERY_PARAM(condtion, GroupListQuery, params);
		//响应结果

		API_HANDLER_RESP_VO(execQueryGroupList(condtion));
	}

	//定义新增群组
	ENDPOINT_INFO(addGroup) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("grouplist.add.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GroupListPageJsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/organization-group/add-group", addGroup, BODY_DTO(GroupListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddGroup(dto));
	}

	//查询身份成员

	//就一年   没有天花板  ---------------------------------------------=======--------------------------------------------------------------


	//骑着蜗牛  ——---------------------——————————————————————————————————————————————-------------------------------------------------------------------------


	//骑着蜗牛飙车controller
		//增加身份成员
		// 3.1 定义新增接口描述
	ENDPOINT_INFO(addAddOrRemoveIdentityMembers) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/org/AddOrRemoveIdentityMembers", addAddOrRemoveIdentityMembers, BODY_DTO(AddOrRemoveIdentityMembersDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddAddOrRemoveIdentityMembers(dto));
	}

	//删除身份成员
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeAddOrRemoveIdentityMembers) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		//API_DEF_ADD_PATH_PARAMS(String, "groupxid", ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id"), "1", false);
		//API_DEF_ADD_PATH_PARAMS(String, "xidentityList", ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.xidentityList"), "2", false);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/org/AddOrRemoveIdentityMembers/{groupxid}", removeAddOrRemoveIdentityMembers, PATH(String, groupxid), execRemoveAddOrRemoveIdentityMembers(groupxid));


	//获取群组成员
		// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryGetGroupMembers) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.get.groupmembers"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetGroupMembersPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "groupxid", ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id"), "li", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/org/GetGroupMembers", queryGetGroupMembers, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, GetGroupMembersQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryGetGroupMembers(userQuery, authObject->getPayload()));
	}

	//获取组织成员
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryGetOrganizationMembers) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.get.organizationmembers"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetOrganizationMembersPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "groudxid", ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id"), "l", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/query/GetOrganizationMembers", queryGetOrganizationMembers, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, GetOrganizationMembersQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryGetOrganizationMembers(userQuery, authObject->getPayload()));
	}


	

	//骑着蜗牛  ——---------------------——————————————————————————————————————————————-------------------------------------------------------------------------



	//不变 -----------------------------------------------------------------------------------------------------------------------------------------------------


	//这是不变写的controller
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryGroupInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("groupManagement.groupInfo.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetGroupInfoJsonVO);
		// 定义查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("groupManagement.groupInfo.field.id"), "111dw212d", true);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/group/get-groupInfo", queryGroupInfo, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryGroupInfo(id));
	}

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(RemoveGroup) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("groupManagement.groupInfo.delete.summary"), StringJsonVO::Wrapper);
		// 定义其他路径参数说明
		//API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("groupManagement.groupInfo.id"), "111", true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/group/delete-group/{id}", RemoveGroup, PATH(String, id), execDeleteGroup(id));

	//不变 -----------------------------------------------------------------------------------------------------------------------------------------------------


	//maple ----------------------------------------------------------------------------------------------------------------------------------------------------------

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("group.put.summary"), modifyGroup, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/groupinfo", modifyGroup, BODY_DTO(GroupDTO::Wrapper, dto), executeModifyGroup(dto));


	//获取个人成员
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
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("role.field.name"), 1, false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/user", queryUser, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, UserQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryUser(userQuery, authObject->getPayload()));
	}


	//maple ----------------------------------------------------------------------------------------------------------------------------------------------------------


private: // 定义接口执行函数
	//查询身份成员
	IDmemberPageJsonVO::Wrapper execQueryIDmember(const IDmemberQuery::Wrapper& query, const PayloadDTO& payload);
	//新增个人成员
	AddPersonJsonVO::Wrapper execAddPerson(const AddPersonDTO::Wrapper& dto);
	//删除个人成员
	Uint64JsonVO::Wrapper execRemovePerson(const String& group_person);



	//添加群组成员
	//添加成功，就将查出的群组名称和群组全称给返回去
	AddGroupMemberJsonVO::Wrapper execAddGroupMember(const AddGroupMemberReqDTO::Wrapper& dto, const PayloadDTO& payload);
	//删除群组成员
	StringJsonVO::Wrapper execDelGroupMember(const DelGroupMemberDTO::Wrapper& dto);

	//添加组织成员
	//添加成功，就将查出的组织名称和组织全称给返回去
	AddUnitMemberJsonVO::Wrapper execAddUnitMember(const AddUnitMemberReqDTO::Wrapper& dto);
	//删除组织成员
	StringJsonVO::Wrapper execDelUnitMember(const DelUnitMemberDTO::Wrapper& dto);

	//查询群组列表
	GroupListPageJsonVO::Wrapper execQueryGroupList(const GroupListQuery::Wrapper& query);
	//新增群组成员
	Uint64JsonVO::Wrapper execAddGroup(const GroupListDTO::Wrapper& dto);
	//查询身份成员


		//骑着蜗牛飙车controller
		// 增加身份成员
	Uint64JsonVO::Wrapper execAddAddOrRemoveIdentityMembers(const AddOrRemoveIdentityMembersDTO::Wrapper& dto);
	// 删除身份成员
	Uint64JsonVO::Wrapper execRemoveAddOrRemoveIdentityMembers(const String& id);
	// 获取群组成员
	GetGroupMembersPageJsonVO::Wrapper execQueryGetGroupMembers(const GetGroupMembersQuery::Wrapper& query, const PayloadDTO& payload);
	// 获取组织成员
	GetOrganizationMembersPageJsonVO::Wrapper execQueryGetOrganizationMembers(const GetOrganizationMembersQuery::Wrapper& query, const PayloadDTO& payload);




	//执行获取群组信息
	GetGroupInfoJsonVO::Wrapper execQueryGroupInfo(const String& id);
	//执行删除群组
	StringJsonVO::Wrapper execDeleteGroup(const String& id);


	////修改群组信息
	Uint64JsonVO::Wrapper executeModifyGroup(const GroupDTO::Wrapper& dto);
	//获取个人成员
	UserPageJsonVO::Wrapper executeQueryUser(const UserQuery::Wrapper& query, const PayloadDTO& payload);








	

};

#include OATPP_CODEGEN_END(ApiController)

#endif 



/*
* 


//查询身份成员
	IDmemberPageJsonVO::Wrapper execQueryIDmember(const IDmemberQuery::Wrapper& query, const PayloadDTO& payload);
	//查询群组列表
	StringJsonVO::Wrapper execQueryGroupList(const PageQuery::Wrapper& condtion);


	//新增个人成员
	AddPersonJsonVO::Wrapper execAddPerson(const AddPersonDTO::Wrapper& dto);
	//删除个人成员
	Uint64JsonVO::Wrapper execRemovePerson(const String& group_person);
	//查询群组列表
	GroupListPageJsonVO::Wrapper execQueryGroupList(const GroupListQuery::Wrapper& query);
	//新增群组成员
	Uint64JsonVO::Wrapper execAddGroup(const GroupListDTO::Wrapper& dto);
	//查询身份成员


	//添加群组成员
	//添加成功，就将查出的群组名称和群组全称给返回去
	AddGroupMemberJsonVO::Wrapper execAddGroupMember(const AddGroupMemberReqDTO::Wrapper& dto,const PayloadDTO& payload);
	//删除群组成员
	StringJsonVO::Wrapper execDelGroupMember(const DelGroupMemberDTO::Wrapper& dto);

	//添加组织成员
	//添加成功，就将查出的组织名称和组织全称给返回去
	AddUnitMemberJsonVO::Wrapper execAddUnitMember(const AddUnitMemberReqDTO::Wrapper& dto);
	//删除组织成员
	StringJsonVO::Wrapper execDelUnitMember(const DelUnitMemberDTO::Wrapper& dto);

	//执行获取群组信息
	GetGroupInfoJsonVO::Wrapper execQueryGroupInfo(const String& id);
	//执行删除群组
	StringJsonVO::Wrapper execDeleteGroup(const String& id);

	//骑着蜗牛飙车controller
	// 增加身份成员
	Uint64JsonVO::Wrapper execAddAddOrRemoveIdentityMembers(const AddOrRemoveIdentityMembersDTO::Wrapper& dto);
	// 删除身份成员
	Uint64JsonVO::Wrapper execRemoveAddOrRemoveIdentityMembers(const String& id);
	// 获取群组成员
	GetGroupMembersPageJsonVO::Wrapper execQueryGetGroupMembers(const GetGroupMembersQuery::Wrapper& query, const PayloadDTO& payload);
	// 获取组织成员
	GetOrganizationMembersPageJsonVO::Wrapper execQueryGetOrganizationMembers(const GetOrganizationMembersQuery::Wrapper& query, const PayloadDTO& payload);








	//获取群组列表
	ENDPOINT_INFO(queryGroupList) {
		// general
		// 定义标题;
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("grouplist.get.summary"));
		//定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义分页查询参数描述
		API_DEF_ADD_RSP_JSON_WRAPPER(GroupListPageDTO);
		// 定义其他查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("group.field.id"), "1234", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("group.field.name"), "zhangsan", false);
	}
	//定义群组查询接口
	ENDPOINT(API_M_GET, "/organization-group/id-grouplist", queryGroupList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {

		//解析参数
		API_HANDLER_QUERY_PARAM(condtion, GroupListQuery, params);
		//响应结果

		API_HANDLER_RESP_VO(execQueryGroupList(condtion));
	}

	//定义新增群组
	ENDPOINT_INFO(addGroup) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("grouplist.add.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GroupListPageJsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/organization-group/add-group", addGroup, BODY_DTO(GroupListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddGroup(dto));
	}



	//定义群组成员的新增处理接口（可以批量操作）
	API_DEF_ENDPOINT_INFO_AUTH( ZH_WORDS_GETTER("groupMember.add.put.summary"), addGroupMember, AddGroupMemberJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/groupMember/add", addGroupMember, BODY_DTO(AddGroupMemberReqDTO::Wrapper, dto), execAddGroupMember(dto));
	//定义群组成员的删除处理接口（可以批量操作）
	API_DEF_ENDPOINT_INFO_AUTH( ZH_WORDS_GETTER("groupMember.del.put.summary"), delGroupMember, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/groupMember/del", delGroupMember, BODY_DTO(DelGroupMemberDTO::Wrapper, dto), execDelGroupMember(dto));

	//定义组织成员的新增接口处理（可以批量操作）
	API_DEF_ENDPOINT_INFO_AUTH( ZH_WORDS_GETTER("UnitMember.add.put.summary"), addUnitMember, AddUnitMemberJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/unitMember/add", addUnitMember, BODY_DTO(AddUnitMemberReqDTO::Wrapper, dto), execAddUnitMember(dto));
	//定义组织成员的删除接口处理（可以批量操作）
	API_DEF_ENDPOINT_INFO_AUTH( ZH_WORDS_GETTER("UnitMember.del.put.summary"), delUnitMember, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/unitMember/del", delUnitMember, BODY_DTO(DelUnitMemberDTO::Wrapper, dto), execDelUnitMember(dto));

	//查询身份成员
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryIDmember) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("organization.group.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(IDmemberPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xunitLevelName", ZH_WORDS_GETTER("organization.group.field.xunitLevelName"), ZH_WORDS_GETTER("organization.group.field.yname.qqcy"), false);
	}
	// 3.2 定义查询接口处理
	//ENDPOINT(API_M_GET, "/organization-group/id-member", queryIDmember, QUERY(String, xunique), API_HANDLER_AUTH_PARAME) {
	ENDPOINT(API_M_GET, "/organization-group/id-member", queryIDmember, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(idmemberQuery, IDmemberQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryIDmember(idmemberQuery, authObject->getPayload()));
	}

	//删除群组接口，使用int orderNumber
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(RemoveGroup) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("groupManagement.groupInfo.delete.summary"), Uint64JsonVO::Wrapper);
	//	 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "orderNumber", ZH_WORDS_GETTER("groupManagement.groupInfo.field.orderNumber"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/groupManagement/delete-group", RemoveGroup, PATH(UInt64, orderNumber), execDeleteGroup(orderNumber));

	//增加个人成员
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addPerson) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("organization.group.post.summary"));
	//	 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AddPersonJsonVO);
	}
//	 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/organization-group/add-person", addPerson, BODY_DTO(AddPersonDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
	//	 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddPerson(dto));
	}

//	删除个人成员
//	 3.1 定义删除接口描述
	ENDPOINT_INFO(removePerson) {
	//	 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("organization.group.delete.summary"), Uint64JsonVO::Wrapper);
	//	 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(Vector<String>, "group_person", ZH_WORDS_GETTER("organization.group.field.group_person"), Vector<String>{}, true);
		API_DEF_ADD_PATH_PARAMS(String, "group_person", ZH_WORDS_GETTER("organization.group.field.group_person"), "1", true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/organization-group/delete-person/{group_person}", removePerson, PATH(Vector<String>, group_person), execRemovePerson(group_person));
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/organization-group/delete-person/{group_person}", removePerson, PATH(String, group_person), execRemovePerson(group_person));


	////定义群组成员的新增处理接口（可以批量操作）
	//API_DEF_ENDPOINT_INFO_AUTH( ZH_WORDS_GETTER("groupMember.add.put.summary"), addGroupMember, AddGroupMemberJsonVO::Wrapper);
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/groupMember/add", addGroupMember, BODY_DTO(AddGroupMemberReqDTO::Wrapper, dto), execAddGroupMember(dto,authObject->getPayload()));
	////定义群组成员的删除处理接口（可以批量操作）
	//API_DEF_ENDPOINT_INFO_AUTH( ZH_WORDS_GETTER("groupMember.del.put.summary"), delGroupMember, StringJsonVO::Wrapper);
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/groupMember/del", delGroupMember, BODY_DTO(DelGroupMemberDTO::Wrapper, dto), execDelGroupMember(dto));

	////定义组织成员的新增接口处理（可以批量操作）
	//API_DEF_ENDPOINT_INFO_AUTH( ZH_WORDS_GETTER("unitMember.add.put.summary"), addUnitMember, AddUnitMemberJsonVO::Wrapper);
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/unitMember/add", addUnitMember, BODY_DTO(AddUnitMemberReqDTO::Wrapper, dto), execAddUnitMember(dto));
	////定义组织成员的删除接口处理（可以批量操作）
	//API_DEF_ENDPOINT_INFO_AUTH( ZH_WORDS_GETTER("unitMember.del.put.summary"), delUnitMember, StringJsonVO::Wrapper);
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/unitMember/del", delUnitMember, BODY_DTO(DelUnitMemberDTO::Wrapper, dto), execDelUnitMember(dto));

	//这是不变写的controller
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryGroupInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("groupManagement.groupInfo.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetGroupInfoJsonVO);
		// 定义查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("groupManagement.groupInfo.field.id"), "111dw212d", true);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/group/get-groupInfo", queryGroupInfo, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryGroupInfo(id));
	}

	//// 3.1 定义删除接口描述
	//ENDPOINT_INFO(RemoveGroup) {
	//	// 定义标题和返回类型以及授权支持
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("groupManagement.groupInfo.delete.summary"), StringJsonVO::Wrapper);
	//	// 定义其他路径参数说明
	//	//API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("groupManagement.groupInfo.id"), "111", true);
	//}
	//// 3.2 定义删除接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/group/delete-group/{id}", RemoveGroup, PATH(String, id), execDeleteGroup(id));




	//骑着蜗牛飙车controller
		//增加身份成员
		// 3.1 定义新增接口描述
	ENDPOINT_INFO(addAddOrRemoveIdentityMembers) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/org/AddOrRemoveIdentityMembers", addAddOrRemoveIdentityMembers, BODY_DTO(AddOrRemoveIdentityMembersDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddAddOrRemoveIdentityMembers(dto));
	}

	//删除身份成员
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeAddOrRemoveIdentityMembers) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		//API_DEF_ADD_PATH_PARAMS(String, "groupxid", ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id"), "1", false);
		//API_DEF_ADD_PATH_PARAMS(String, "xidentityList", ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.xidentityList"), "2", false);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/org/AddOrRemoveIdentityMembers/{groupxid}", removeAddOrRemoveIdentityMembers, PATH(String, groupxid),execRemoveAddOrRemoveIdentityMembers(groupxid));


	//获取群组成员
		// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryGetGroupMembers) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.get.groupmembers"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetGroupMembersPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "groupxid", ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id"), "li", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/org/GetGroupMembers", queryGetGroupMembers, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, GetGroupMembersQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryGetGroupMembers(userQuery, authObject->getPayload()));
	}

	//获取组织成员
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryGetOrganizationMembers) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.get.organizationmembers"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetOrganizationMembersPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "groudxid", ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id"), "l", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/query/GetOrganizationMembers", queryGetOrganizationMembers, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, GetOrganizationMembersQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryGetOrganizationMembers(userQuery, authObject->getPayload()));
	}
*/








/*
//定义新增群组
ENDPOINT_INFO(addGroup) {
	// 定义接口标题
	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("grouplist.add.summary"));
	// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
	API_DEF_ADD_AUTH();
	// 定义响应参数格式
	API_DEF_ADD_RSP_JSON_WRAPPER(GroupListPageJsonVO);
}
// 3.2 定义新增接口处理
ENDPOINT(API_M_POST, "/organization-group/add-group", addGroup, BODY_DTO(GroupListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
	// 呼叫执行函数响应结果
	API_HANDLER_RESP_VO(execAddGroup(dto));
}
*/

/*

//定义群组成员的新增处理接口（可以批量操作）
API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("groupMember.add.put.summary"), addGroupMember, AddGroupMemberJsonVO::Wrapper);
API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/groupMember/add", addGroupMember, BODY_DTO(AddGroupMemberReqDTO::Wrapper, dto), execAddGroupMember(dto));
//定义群组成员的删除处理接口（可以批量操作）
API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("groupMember.del.put.summary"), delGroupMember, StringJsonVO::Wrapper);
API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/groupMember/del", delGroupMember, BODY_DTO(DelGroupMemberDTO::Wrapper, dto), execDelGroupMember(dto));


//定义组织成员的新增接口处理（可以批量操作）
API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("UnitMember.add.put.summary"), addUnitMember, AddUnitMemberJsonVO::Wrapper);
API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/unitMember/add", addUnitMember, BODY_DTO(AddUnitMemberReqDTO::Wrapper, dto), execAddUnitMember(dto));
//定义组织成员的删除接口处理（可以批量操作）
API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("UnitMember.del.put.summary"), delUnitMember, StringJsonVO::Wrapper);
API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/unitMember/del", delUnitMember, BODY_DTO(DelUnitMemberDTO::Wrapper, dto), execDelUnitMember(dto));

// 3.1 定义查询接口描述
ENDPOINT_INFO(queryGroupInfo) {
	// 定义接口标题
	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("groupManagement.groupInfo.get.summary"));
	// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
	API_DEF_ADD_AUTH();
	// 定义响应参数格式
	//API_DEF_ADD_RSP_JSON_WRAPPER(GetGroupInfoJsonVO);
	// 定义查询参数描述
	API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("groupManagement.groupInfo.field.id"), "111dw212d", true);
}
// 3.2 定义查询接口处理
ENDPOINT(API_M_GET, "/groupManagement/get-groupInfo", queryGroupInfo, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
	// 呼叫执行函数响应结果
	API_HANDLER_RESP_VO(execQueryGroupInfo(id));
}

//删除群组接口，使用int orderNumber
// 3.1 定义删除接口描述
ENDPOINT_INFO(RemoveGroup) {
	// 定义标题和返回类型以及授权支持
	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("groupManagement.groupInfo.delete.summary"), Uint64JsonVO::Wrapper);
	// 定义其他路径参数说明
	API_DEF_ADD_PATH_PARAMS(UInt64, "orderNumber", ZH_WORDS_GETTER("groupManagement.groupInfo.field.orderNumber"), 1, true);
}
// 3.2 定义删除接口处理
API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/groupManagement/delete-group", RemoveGroup, PATH(UInt64, orderNumber), execDeleteGroup(orderNumber));


//新增群组成员
//StringJsonVO::Wrapper execAddGroup(const GroupListDTO::Wrapper& dto);
//查询身份成员
//查询身份成员
//IDmemberJsonVO::Wrapper execQueryIDmember(const String& xunique, const PayloadDTO& payload);

////添加群组成员
////添加成功，就将查出的群组名称和群组全称给返回去
//AddGroupMemberJsonVO::Wrapper execAddGroupMember(const AddGroupMemberReqDTO::Wrapper& dto);
////删除群组成员
//StringJsonVO::Wrapper execDelGroupMember(const DelGroupMemberDTO::Wrapper& dto);


//添加组织成员
//添加成功，就将查出的组织名称和组织全称给返回去
//AddUnitMemberJsonVO::Wrapper execAddUnitMember(const AddUnitMemberReqDTO::Wrapper& dto);
//删除组织成员
//StringJsonVO::Wrapper execDelUnitMember(const DelUnitMemberDTO::Wrapper& dto);

//执行获取群组信息
//GetGroupInfoJsonVO::Wrapper execQueryGroupInfo(const String& id);
//执行删除群组
//Uint64JsonVO::Wrapper execDeleteGroup(const UInt64& orderNumber);


	*/

	//查询身份成员
	/*
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryIDmember) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("organization.group.get.summary"));
		//API_DEF_ADD_TITLE("this is the first obj");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(IDmemberJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xunique", ZH_WORDS_GETTER("organization.group.field.xunique"), "1", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/organization-group/id-member", queryIDmember, QUERY(String, xunique), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		//API_HANDLER_QUERY_PARAM(userQuery, SampleQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryIDmember(xunique, authObject->getPayload()));
	}
	*/

	/*
	////获取群组列表
//ENDPOINT_INFO(queryGroupList) {
//	// general
//	// 定义标题;
//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("grouplist.get.summary"));
//	//定义默认授权参数

	////获取群组列表
	//ENDPOINT_INFO(queryGroupList) {
	//	// general
	//	// 定义标题;
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("grouplist.get.summary"));
	//	//定义默认授权参数
	//	API_DEF_ADD_AUTH();
	//	// 定义分页查询参数描述
	//	API_DEF_ADD_RSP_JSON_WRAPPER(GroupListPageDTO);
	//	// 定义其他查询参数描述
	//	API_DEF_ADD_PAGE_PARAMS();
	//	API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("group.field.id"), "1234", true);
	//	API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("group.field.name"), "zhangsan", false);
	//}
	////定义群组查询接口
	//ENDPOINT(API_M_GET, "/organization-group/id-grouplist", queryGroupList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
	////定义新增群组
	//ENDPOINT_INFO(addGroup) {
	//	// 定义接口标题
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("grouplist.add.summary"));
	//	// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
	//	API_DEF_ADD_AUTH();
	//	// 定义响应参数格式
	//	API_DEF_ADD_RSP_JSON_WRAPPER(GroupListPageJsonVO);
	//}
	//// 3.2 定义新增接口处理
	//ENDPOINT(API_M_POST, "/organization-group/add-group", addGroup, BODY_DTO(GroupListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
	//	// 呼叫执行函数响应结果
	//	API_HANDLER_RESP_VO(execAddGroup(dto));
	//}

	//疑似 就一年的（没有天花板）

	////查询身份成员
	//// 3.1 定义查询接口描述
	//ENDPOINT_INFO(queryIDmember) {
	//	// 定义接口标题
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("organization.group.get.summary"));
	//	//API_DEF_ADD_TITLE("this is the first obj");
	//	// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
	//	API_DEF_ADD_AUTH();
	//	// 定义分页查询参数描述
	//	API_DEF_ADD_RSP_JSON_WRAPPER(GroupListPageJsonVO);
	//	// 定义其他查询参数描述
	//	API_DEF_ADD_PAGE_PARAMS();
	//	API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("group.field.id"), "", false);
	//	API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("group.field.name"), "string", false);
	//}
	////定义群组查询接口
	//ENDPOINT(API_M_GET, "/organization-group/id-grouplist", queryGroupList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {

	//	//解析参数
	//	API_HANDLER_QUERY_PARAM(condtion, GroupListQuery, params);
	//	//响应结果

	//	API_HANDLER_RESP_VO(execQueryGroupList(condtion));
	//}

	//疑似 就一年的（没有天花板）

		//	//解析参数
	//	API_HANDLER_QUERY_PARAM(condtion, GroupListQuery, params);
	//	//响应结果

	//	API_HANDLER_RESP_VO(execQueryGroupList(condtion));
	//}


	*/
	//注意下这里的注释
//#endif // !_ORGANIZATIONGROUPCONTROLLER_H_#pragma once
