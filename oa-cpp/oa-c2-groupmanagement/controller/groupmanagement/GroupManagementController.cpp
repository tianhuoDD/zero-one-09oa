/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 23�� ������ 17:28:51 CST
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
	 //����һ��Service
	IDmemberQueryService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
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
	// ���巵�����ݶ���
	auto jvo = AddPersonJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (dto->GROUP_XID.getValue("").size() == 0 || dto->xpersonList.getValue("").size() == 0)
	{
		jvo->init({}, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	AddPersonService service;
	// ִ����������
	auto return_dto = service.saveData(dto);
	if (return_dto->GROUP_XID.getValue("").size() && return_dto->xpersonList.getValue("").size()) {
		jvo->success(return_dto);
	}
	else
	{
		jvo->fail(return_dto);
	}
	//��Ӧ���
	return jvo;

}

GroupListPageJsonVO::Wrapper GroupManagementController::execQueryGroupList(const GroupListQuery::Wrapper& query)
{
	// ����һ��Service
	GroupListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = GroupListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


//������ţ쭳�
Uint64JsonVO::Wrapper GroupManagementController::execAddAddOrRemoveIdentityMembers(const AddOrRemoveIdentityMembersDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
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
	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper GroupManagementController::execRemoveAddOrRemoveIdentityMembers(const String& groupxid)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����һ��Service
	rolemanagementService service;
	// ִ������ɾ��
	if (service.removeData(groupxid)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(11);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper GroupManagementController::execAddGroup(const GroupListDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->id || !dto->name )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if ( dto->name->empty() || dto->id->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	GroupListService service;
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
	// ����һ��Service
	GetGroupInfoService service;
	
	// ��ѯ����
	string stdStr = id->c_str();	// ��oatpp::Stringת��Ϊstd::string
	auto result = service.getGroupInfoById(stdStr);	//����service�ĺ���ֱ�ӷ���vo
	// ������Ӧ���
	auto jvo = GetGroupInfoJsonVO::createShared();	//�����VO����jvo��dto������vo����
	jvo->success(result);	

	return jvo;
}

//StringJsonVO::Wrapper GroupManagementController::execRemovePerson(const String& xunique)
//У���ǰ�˴����������ݣ�������ӿ�
StringJsonVO::Wrapper GroupManagementController::execDeleteGroup(const String& id)
{

	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// �ǿղ���У��
	if (id->empty())
	{
		jvo->init("", RS_PARAMS_INVALID);	//��ʼ��Ϊ�գ��ϴ������쳣
		return jvo;
	}
	//����һ��service
	DeleteGroupService service;
	//ִ��ɾ������
	if (service.removeData(id->c_str())) {
		jvo->success(id);
		cout << "�ɹ��ˣ�" << endl;
		cout << "id:" << id->c_str() << endl;
	}
	else
	{
		cout << "ʧ���ˣ�" << endl;
		cout << "id:" << id->c_str() << endl;
		jvo->fail(id);
	}
	//������Ӧ���
	return jvo;
}

GetGroupMembersPageJsonVO::Wrapper GroupManagementController::execQueryGetGroupMembers(const GetGroupMembersQuery::Wrapper& query, const PayloadDTO& payload)
{

	// ����һ��Service
	rolemanagementService service;
	// ��ѯ����
	auto result = service.listAllG(query);
	// ��Ӧ���
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
	// ����һ��Service
	rolemanagementService service;
	// ��ѯ����
	auto result = service.listAllO(query);
	// ��Ӧ���
	auto jvo = GetOrganizationMembersPageJsonVO::createShared();
	jvo->success(query);
	return jvo;

}

Uint64JsonVO::Wrapper GroupManagementController::execRemovePerson(const String& group_person)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (group_person.getValue("").size()==0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	RemovePersonService service;
	// ִ������ɾ��
	UInt64 res = service.removeData(group_person);
	if (res) {
		jvo->success(res);
	}
	else
	{
		jvo->fail(!res);
	}
	// ��Ӧ���
	return jvo;
}


Uint64JsonVO::Wrapper GroupManagementController::executeModifyGroup(const GroupDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ModifyGroupInfoService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// ��Ӧ���
	return jvo;
}

UserPageJsonVO::Wrapper GroupManagementController::executeQueryUser(const UserQuery::Wrapper& query, const PayloadDTO& payload)
{	// ����һ��Service
	UserService service;
	//// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = UserPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
