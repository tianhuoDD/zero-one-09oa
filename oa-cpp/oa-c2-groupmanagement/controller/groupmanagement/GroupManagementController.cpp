/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 23日 星期三 17:28:51 CST
*/
#include "stdafx.h"
#include "GroupManagementController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "service/QueryUserService.h"
#include "service/ModifyGroupInfoService.h"
#include "service/QueryUserService.h"
#include "service/ModifyGroupInfoService.h"

#include "../../service/groupmanagement/GroupListService.h"
#include "../../service/rolemanagement/rolemanagementService.h"
//#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/groupmanagement/GroupManagementService/IDmemberQueryService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/groupmanagement/GroupManagementService/AddPersonService.h"
#include "../../service/groupmanagement/GroupManagementService/RemovePersonService.h"

#include "../../service/get/GetGroupInfoService/GetGroupInfoService.h"
#include "../../service/delete/DeleteGroupService/DeleteGroupService.h"
#include "service/groupmanagement/GroupManagementService.h"




//StringJsonVO::Wrapper GroupManagementController::execQueryGroupList(const PageQuery::Wrapper& condtion)
//{
//	return StringJsonVO::Wrapper();
//}

//StringJsonVO::Wrapper GroupManagementController::execAddGroup(const GroupListDTO::Wrapper& dto)
//{
//	return StringJsonVO::Wrapper();
//}
//


//IDmemberJsonVO::Wrapper GroupManagementController::execQueryIDmember(const String& xunique, const PayloadDTO& payload)
//{
//	return {};
//}

IDmemberPageJsonVO::Wrapper GroupManagementController::execQueryIDmember(const IDmemberQuery::Wrapper& query, const PayloadDTO& payload)
{
	 //定义一个Service
	IDmemberQueryService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = IDmemberPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

//StringJsonVO::Wrapper GroupManagementController::execRemovePerson(const String& xunique)
//{
//	return {};
//}


//IDmemberJsonVO::Wrapper GroupManagementController::execQueryIDmember(const String& xunique, const PayloadDTO& payload)

AddPersonJsonVO::Wrapper GroupManagementController::execAddPerson(const AddPersonDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = AddPersonJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (dto->GROUP_XID.getValue("").size() == 0 || dto->xpersonList.getValue("").size() == 0)
	{
		jvo->init({}, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	AddPersonService service;
	// 执行数据新增
	auto return_dto = service.saveData(dto);
	if (return_dto->GROUP_XID.getValue("").size() && return_dto->xpersonList.getValue("").size()) {
		jvo->success(return_dto);
	}
	else
	{
		jvo->fail(return_dto);
	}
	//响应结果
	return jvo;

}

GroupListPageJsonVO::Wrapper GroupManagementController::execQueryGroupList(const GroupListQuery::Wrapper& query)
{
	// 定义一个Service
	GroupListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = GroupListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


//骑着蜗牛飙车
Uint64JsonVO::Wrapper GroupManagementController::execAddAddOrRemoveIdentityMembers(const AddOrRemoveIdentityMembersDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	rolemanagementService service;
	uint64_t id = service.saveData(dto);
	if (!dto->groupxid || !dto->xidentityList);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}

Uint64JsonVO::Wrapper GroupManagementController::execRemoveAddOrRemoveIdentityMembers(const String& groupxid)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 定义一个Service
	rolemanagementService service;
	// 执行数据删除
	if (service.removeData(groupxid)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(11);
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper GroupManagementController::execAddGroup(const GroupListDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->id || !dto->name )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if ( dto->name->empty() || dto->id->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	GroupListService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}


AddGroupMemberJsonVO::Wrapper GroupManagementController::execAddGroupMember(const AddGroupMemberReqDTO::Wrapper &dto, const PayloadDTO &payload) {
	auto jvo = AddGroupMemberJsonVO::createShared();
	if( dto->groupList->empty() || dto->gruopId->empty() ) {
		jvo->init(nullptr, RS_FAIL);
		return jvo;
	}
	GroupManagementService service;
	auto ret = service.addGroupMember(dto);
	if( ret != nullptr ) {
		return ret;
	}

	jvo->fail(nullptr);
	return jvo;
}

StringJsonVO::Wrapper GroupManagementController::execDelGroupMember(const DelGroupMemberDTO::Wrapper &dto) {
	auto jvo = StringJsonVO::createShared();

	if( dto->groupList->empty() || dto->gruopId->empty() ) {
		jvo->init("fail", RS_FAIL);
		return jvo;
	}
	GroupManagementService service;
	if( service.delGroupMember(dto) ) {
		jvo->success("success");
	}else {
		jvo->fail("fail");
	}

	return jvo;
}

AddUnitMemberJsonVO::Wrapper GroupManagementController::execAddUnitMember(const AddUnitMemberReqDTO::Wrapper &dto) {
	auto jvo = AddUnitMemberJsonVO::createShared();
	if( dto->unitList->empty() || dto->gruopId->empty() ) {
		jvo->init(nullptr, RS_FAIL);
		return jvo;
	}
	GroupManagementService service;
	auto ret = service.addUnitMember(dto);
	if( ret != nullptr ) {
		return ret;
	}

	jvo->fail(nullptr);
	return jvo;
}

StringJsonVO::Wrapper GroupManagementController::execDelUnitMember(const DelUnitMemberDTO::Wrapper &dto) {
	auto jvo = StringJsonVO::createShared();

	if( dto->unitList->empty() || dto->gruopId->empty() ) {
		jvo->init("fail", RS_FAIL);
		return jvo;
	}
	GroupManagementService service;
	if( service.delUnitMember(dto) ) {
		jvo->success("success");
	}else {
		jvo->fail("fail");
	}

	return jvo;
}



GetGroupInfoJsonVO::Wrapper GroupManagementController::execQueryGroupInfo(const String& id)
{
	// 定义一个Service
	GetGroupInfoService service;
	
	// 查询数据
	string stdStr = id->c_str();	// 将oatpp::String转换为std::string
	auto result = service.getGroupInfoById(stdStr);	//调用service的函数直接返回vo
	// 返回响应结果
	auto jvo = GetGroupInfoJsonVO::createShared();	//会根据VO返回jvo的dto或者是vo对象
	jvo->success(result);	

	return jvo;
}

//StringJsonVO::Wrapper GroupManagementController::execRemovePerson(const String& xunique)
//校验从前端传过来的数据，我这个接口
StringJsonVO::Wrapper GroupManagementController::execDeleteGroup(const String& id)
{

	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 非空参数校验
	if (id->empty())
	{
		jvo->init("", RS_PARAMS_INVALID);	//初始化为空，上传参数异常
		return jvo;
	}
	//定义一个service
	DeleteGroupService service;
	//执行删除操作
	if (service.removeData(id->c_str())) {
		jvo->success(id);
		cout << "成功了！" << endl;
		cout << "id:" << id->c_str() << endl;
	}
	else
	{
		cout << "失败了！" << endl;
		cout << "id:" << id->c_str() << endl;
		jvo->fail(id);
	}
	//返回响应结果
	return jvo;
}

GetGroupMembersPageJsonVO::Wrapper GroupManagementController::execQueryGetGroupMembers(const GetGroupMembersQuery::Wrapper& query, const PayloadDTO& payload)
{

	// 定义一个Service
	rolemanagementService service;
	// 查询数据
	auto result = service.listAllG(query);
	// 响应结果
	auto jvo = GetGroupMembersPageJsonVO::createShared();
	jvo->success(query);
	return jvo;

}

//Uint64JsonVO::Wrapper GroupManagementController::execDeleteGroup(const UInt64& orderNumber)
//{
//	return {};
//}


GetOrganizationMembersPageJsonVO::Wrapper GroupManagementController::execQueryGetOrganizationMembers(const GetOrganizationMembersQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	rolemanagementService service;
	// 查询数据
	auto result = service.listAllO(query);
	// 响应结果
	auto jvo = GetOrganizationMembersPageJsonVO::createShared();
	jvo->success(query);
	return jvo;

}

Uint64JsonVO::Wrapper GroupManagementController::execRemovePerson(const String& group_person)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (group_person.getValue("").size()==0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	RemovePersonService service;
	// 执行数据删除
	UInt64 res = service.removeData(group_person);
	if (res) {
		jvo->success(res);
	}
	else
	{
		jvo->fail(!res);
	}
	// 响应结果
	return jvo;
}


Uint64JsonVO::Wrapper GroupManagementController::executeModifyGroup(const GroupDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ModifyGroupInfoService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
}

UserPageJsonVO::Wrapper GroupManagementController::executeQueryUser(const UserQuery::Wrapper& query, const PayloadDTO& payload)
{	// 定义一个Service
	UserService service;
	//// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = UserPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
