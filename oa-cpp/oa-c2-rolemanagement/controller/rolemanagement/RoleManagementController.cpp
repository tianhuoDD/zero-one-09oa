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
	// ����һ��Service
	RoleManagementService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
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
	// ����һ��JsonVO����
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
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->name || !dto->description  || !dto->unique)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	AddroleService service;
	// ִ����������
	uint64_t id = service.addRole(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

// , const PayloadDTO& payload
QueryRolePageJsonVO::Wrapper RoleManagementController::execQueryRolelist(const QueryRoleQuery::Wrapper& query)
{
	// ����һ��Service
	QueryRoleService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = QueryRolePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}



//ִ�л�ȡ��ɫ��Ϣ
GetroleJsonVO::Wrapper RoleManagementController::executQueryGetRole(const String& id)
{
    // ����һ��Service
    GetRoleService service;
    // ��ѯ����
    string stdStr = id->c_str();	// ��oatpp::Stringת��Ϊstd::string
    auto result = service.GetRoleById(stdStr);	//����service�ĺ���ֱ�ӷ���vo
    // ��Ӧ���
    auto jvo = GetroleJsonVO::createShared();	//�����VO����jvo��dto������vo����
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
    // ���巵�����ݶ���
    auto jvo = StringJsonVO::createShared();
    // ����У��
// ����У��
    if (!id || id->empty())
    {
        jvo->init("-1", RS_PARAMS_INVALID);
        return jvo;
    }
    // ����һ��Service
    DelRoleService service;
    // ִ������ɾ��

    if (service.removeData(id)) {
        jvo->success(id);
    }
    else
    {
        jvo->fail(id);
    }
    // ��Ӧ���
    return jvo;
}


Uint64JsonVO::Wrapper RoleManagementController::execAddMember(const PersonMemberDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->role_xid || !dto->xpersonList)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	PersonMemberService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

GetPersonMemberPageJsonVO::Wrapper RoleManagementController::execGetPersonMember(const GetPersonMemberQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	GetPersonMemberService service;
	
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = GetPersonMemberPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}
