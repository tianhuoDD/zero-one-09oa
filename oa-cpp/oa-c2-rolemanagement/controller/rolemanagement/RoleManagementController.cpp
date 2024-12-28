#include "stdafx.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include "domain/do/get/roleresource/RoleResourceDO.h"
//#include "domain/do/RoleResourceDO.h"
//#include "domain/dto/role-resource/RoleResourceInfoDTO.h"
#include "service/TreeRoleResourceInfoMapper.h"
#include "tree/TreeUtil.h"
//#include "RoleManagementController.h"
#include "RoleManagementController.h"
#include "../../service/rolemanagement/RoleManagementService/put/addrole/AddroleService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/rolemanagement/RoleManagementService/get/queryrole/QueryRoleService.h"
#include "./service/rolemanagement/RoleManagementService.h"
#include"service/rolemanagement/RoleManagementService/put/PersonMember/PersonMemberService.h"
#include"service/rolemanagement/RoleManagementService/get/getpersonmember/GetPersonMemberService.h"
#include"../../service/DelRole/DelRoleService.h"
#include"../../service/get/GetRoleService.h"
#include "../ApiDeclarativeServicesHelper.h"

#include "RoleManagementController.h"


//
//Uint64JsonVO::Wrapper RoleManagementController::execModifyRole(const UpdateRoleDTO::Wrapper& dto)
//{
//	auto jvo = Uint64JsonVO::createShared();
//	RoleManagementService service;
//	if(service.updateData(dto))
//	{
//		jvo->success(1);
//	}
//	else {
//		jvo->fail(-1);
//	}
//	return jvo;
//}


StringJsonVO::Wrapper RoleManagementController::execAddDelGroupMember(const GroupMemberDTO::Wrapper& idList)
{
	return StringJsonVO::Wrapper();
}

Uint64JsonVO::Wrapper RoleManagementController::execModifyRole(const UpdateRoleDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	RoleManagementService service;
	cout << dto->xname.getValue("123");
	if (service.updateData(dto))
	{
		jvo->success(1);
	}
	else {
		jvo->fail(2);
	}
	return jvo;
}

PersonListPageJsonVO::Wrapper RoleManagementController::execQueryPersonList(const PersonListQuery::Wrapper& query, const PayloadDTO& payload) {
	// 定义一个Service
	RoleManagementService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = PersonListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	return PersonListPageJsonVO::Wrapper();
}




//xiaodeng---------------------------
Uint64JsonVO::Wrapper RoleManagementController::execAddGroupMember(const GroupMemberDTO::Wrapper& idList) {

	auto jvo = Uint64JsonVO::createShared();

	if (!idList->idList || !idList->roleId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (idList->roleId->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	RoleManagementService service;
	uint64_t count = service.saveGroupMember(idList);
	//uint64_t count = 0;
	if (count > 0)
	{
		jvo->success(UInt64(count));
	}
	else
	{
		jvo->fail(UInt64(count));
	}

	return jvo;

}
Uint64JsonVO::Wrapper RoleManagementController::execDelGroupMember(const GroupMemberDTO::Wrapper& idList)
{
	auto jvo = Uint64JsonVO::createShared();

	if (!idList->idList || !idList->roleId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (idList->idList->empty() || idList->roleId->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	RoleManagementService service;
	uint64_t count =service.removeGroupMember(idList);
	if (count > 0)
	{
		jvo->success(UInt64(count));
	}
	else
	{
		jvo->fail(UInt64(count));
	}

	return jvo;
}
RoleResourceJsonVO::Wrapper RoleManagementController::execObtainRoleResource(const String roleId, const PayloadDTO& payload)
{
	// 定义一个JsonVO对象
	auto vo = RoleResourceJsonVO::createShared();

	if (roleId->empty())
	{
		vo->setStatus(RS_FAIL);
		vo->data = nullptr;
	}
	RoleManagementService service;
	service.listRoleMenu(roleId,vo);
	return vo;
}
Uint64JsonVO::Wrapper RoleManagementController::execModifyRoleResource(const RoleResourceListDTO::Wrapper& roleResource)
{
	auto jvo = Uint64JsonVO::createShared();

	if (!roleResource->idList || !roleResource->roleId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (roleResource->roleId->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	RoleManagementService service;
	uint64_t count = service.updateRoleResource(roleResource);
	//uint64_t count = 0;
	if (count > 0)
	{
		jvo->success(UInt64(count));
	}
	else
	{
		jvo->fail(UInt64(count));
	}

	return jvo;
}

//xiaodeng---------------------------




Uint64JsonVO::Wrapper RoleManagementController::execAddRole(const AddroleDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->name || !dto->description  || !dto->unique)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	AddroleService service;
	// 执行数据新增
	uint64_t id = service.addRole(dto);
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

// , const PayloadDTO& payload
QueryRolePageJsonVO::Wrapper RoleManagementController::execQueryRolelist(const QueryRoleQuery::Wrapper& query)
{
	// 定义一个Service
	QueryRoleService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = QueryRolePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}



//执行获取角色信息
GetroleJsonVO::Wrapper RoleManagementController::executQueryGetRole(const String& id)
{
    // 定义一个Service
    GetRoleService service;
    // 查询数据
    string stdStr = id->c_str();	// 将oatpp::String转换为std::string
    auto result = service.GetRoleById(stdStr);	//调用service的函数直接返回vo
    // 响应结果
    auto jvo = GetroleJsonVO::createShared();	//会根据VO返回jvo的dto或者是vo对象
    jvo->success(result);
    return jvo;
}

Uint64JsonVO::Wrapper RoleManagementController::execDelPersonMember(const PersonMemberDTO::Wrapper& xpersonList)
{
	auto jvo = Uint64JsonVO::createShared();
	
	if (!xpersonList->xpersonList || !xpersonList->role_xid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (xpersonList->xpersonList->empty() || xpersonList->role_xid->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	PersonMemberService service;
	uint64_t count = service.removePersonMember(xpersonList);
	if (count > 0)
	{
		jvo->success(UInt64(count));
	}
	else
	{
		jvo->fail(UInt64(count));
	}

	return jvo;
}


StringJsonVO::Wrapper RoleManagementController::execRemoveRole(const String& id)
{
    // 定义返回数据对象
    auto jvo = StringJsonVO::createShared();
    // 参数校验
// 参数校验
    if (!id || id->empty())
    {
        jvo->init("-1", RS_PARAMS_INVALID);
        return jvo;
    }
    // 定义一个Service
    DelRoleService service;
    // 执行数据删除

    if (service.removeData(id)) {
        jvo->success(id);
    }
    else
    {
        jvo->fail(id);
    }
    // 响应结果
    return jvo;
}


Uint64JsonVO::Wrapper RoleManagementController::execAddMember(const PersonMemberDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->role_xid || !dto->xpersonList)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	PersonMemberService service;
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

GetPersonMemberPageJsonVO::Wrapper RoleManagementController::execGetPersonMember(const GetPersonMemberQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	GetPersonMemberService service;
	
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = GetPersonMemberPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}
