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
	//����ζ��ˮ---------------------------------------------------------------------
	
	// ����������������
	API_ACCESS_DECLARE(GroupManagementController);
public: // ����ӿ�
	//��ѯ��ݳ�Ա
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryIDmember) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("organization.group.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(IDmemberPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "xunitLevelName", ZH_WORDS_GETTER("organization.group.field.xunitLevelName"), ZH_WORDS_GETTER("organization.group.field.yname.qqcy"), false);
	}
	// 3.2 �����ѯ�ӿڴ���
	//ENDPOINT(API_M_GET, "/organization-group/id-member", queryIDmember, QUERY(String, xunique), API_HANDLER_AUTH_PARAME) {
	ENDPOINT(API_M_GET, "/organization-group/id-member", queryIDmember, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(idmemberQuery, IDmemberQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryIDmember(idmemberQuery, authObject->getPayload()));
	}

	//���Ӹ��˳�Ա
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addPerson) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("organization.group.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AddPersonJsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/organization-group/add-person", addPerson, BODY_DTO(AddPersonDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddPerson(dto));
	}

	//ɾ�����˳�Ա
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removePerson) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("organization.group.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		//API_DEF_ADD_PATH_PARAMS(Vector<String>, "group_person", ZH_WORDS_GETTER("organization.group.field.group_person"), Vector<String>{}, true);
		API_DEF_ADD_PATH_PARAMS(String, "group_person", ZH_WORDS_GETTER("organization.group.field.group_person"), "1", true);
	}
	// 3.2 ����ɾ���ӿڴ���
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/organization-group/delete-person/{group_person}", removePerson, PATH(Vector<String>, group_person), execRemovePerson(group_person));

	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/organization-group/delete-person/{group_person}", removePerson, PATH(String, group_person), execRemovePerson(group_person));
	// //����ζ��ˮ---------------------------------------------------------------------

	//fake   -----------------------------------------------------------------------------------------------------------------------



	//����Ⱥ���Ա����������ӿڣ���������������
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("groupMember.add.put.summary"), addGroupMember, AddGroupMemberJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/groupMember/add", addGroupMember, BODY_DTO(AddGroupMemberReqDTO::Wrapper, dto), execAddGroupMember(dto, authObject->getPayload()));
	//����Ⱥ���Ա��ɾ������ӿڣ���������������
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("groupMember.del.put.summary"), delGroupMember, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/groupMember/del", delGroupMember, BODY_DTO(DelGroupMemberDTO::Wrapper, dto), execDelGroupMember(dto));

	//������֯��Ա�������ӿڴ�����������������
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("unitMember.add.put.summary"), addUnitMember, AddUnitMemberJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/unitMember/add", addUnitMember, BODY_DTO(AddUnitMemberReqDTO::Wrapper, dto), execAddUnitMember(dto));
	//������֯��Ա��ɾ���ӿڴ�����������������
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("unitMember.del.put.summary"), delUnitMember, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/unitMember/del", delUnitMember, BODY_DTO(DelUnitMemberDTO::Wrapper, dto), execDelUnitMember(dto));



	

	//fake   -----------------------------------------------------------------------------------------------------------------------



	//��һ��   û���컨��  ---------------------------------------------=======--------------------------------------------------------------

	//��ȡȺ���б�
	ENDPOINT_INFO(queryGroupList) {
		// general
		// �������;
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("grouplist.get.summary"));
		//����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// �����ҳ��ѯ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(GroupListPageJsonVO);
		// ����������ѯ�������� 
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("group.field.id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("group.field.name"), "string", false);
	}
	//����Ⱥ���ѯ�ӿ�
	ENDPOINT(API_M_GET, "/organization-group/id-grouplist", queryGroupList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {

		//��������
		API_HANDLER_QUERY_PARAM(condtion, GroupListQuery, params);
		//��Ӧ���

		API_HANDLER_RESP_VO(execQueryGroupList(condtion));
	}

	//��������Ⱥ��
	ENDPOINT_INFO(addGroup) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("grouplist.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GroupListPageJsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/organization-group/add-group", addGroup, BODY_DTO(GroupListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddGroup(dto));
	}

	//��ѯ��ݳ�Ա

	//��һ��   û���컨��  ---------------------------------------------=======--------------------------------------------------------------


	//������ţ  ����---------------------��������������������������������������������������������������������������������������������-------------------------------------------------------------------------


	//������ţ쭳�controller
		//������ݳ�Ա
		// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addAddOrRemoveIdentityMembers) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/org/AddOrRemoveIdentityMembers", addAddOrRemoveIdentityMembers, BODY_DTO(AddOrRemoveIdentityMembersDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddAddOrRemoveIdentityMembers(dto));
	}

	//ɾ����ݳ�Ա
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeAddOrRemoveIdentityMembers) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		//API_DEF_ADD_PATH_PARAMS(String, "groupxid", ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id"), "1", false);
		//API_DEF_ADD_PATH_PARAMS(String, "xidentityList", ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.xidentityList"), "2", false);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/org/AddOrRemoveIdentityMembers/{groupxid}", removeAddOrRemoveIdentityMembers, PATH(String, groupxid), execRemoveAddOrRemoveIdentityMembers(groupxid));


	//��ȡȺ���Ա
		// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryGetGroupMembers) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.get.groupmembers"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetGroupMembersPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "groupxid", ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id"), "li", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/org/GetGroupMembers", queryGetGroupMembers, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, GetGroupMembersQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryGetGroupMembers(userQuery, authObject->getPayload()));
	}

	//��ȡ��֯��Ա
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryGetOrganizationMembers) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.get.organizationmembers"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetOrganizationMembersPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "groudxid", ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id"), "l", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/query/GetOrganizationMembers", queryGetOrganizationMembers, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, GetOrganizationMembersQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryGetOrganizationMembers(userQuery, authObject->getPayload()));
	}


	

	//������ţ  ����---------------------��������������������������������������������������������������������������������������������-------------------------------------------------------------------------



	//���� -----------------------------------------------------------------------------------------------------------------------------------------------------


	//���ǲ���д��controller
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryGroupInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("groupManagement.groupInfo.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetGroupInfoJsonVO);
		// �����ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("groupManagement.groupInfo.field.id"), "111dw212d", true);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/group/get-groupInfo", queryGroupInfo, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryGroupInfo(id));
	}

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(RemoveGroup) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("groupManagement.groupInfo.delete.summary"), StringJsonVO::Wrapper);
		// ��������·������˵��
		//API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("groupManagement.groupInfo.id"), "111", true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/group/delete-group/{id}", RemoveGroup, PATH(String, id), execDeleteGroup(id));

	//���� -----------------------------------------------------------------------------------------------------------------------------------------------------


	//maple ----------------------------------------------------------------------------------------------------------------------------------------------------------

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("group.put.summary"), modifyGroup, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/groupinfo", modifyGroup, BODY_DTO(GroupDTO::Wrapper, dto), executeModifyGroup(dto));


	//��ȡ���˳�Ա
	ENDPOINT_INFO(queryUser) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("role.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(UserPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("role.field.name"), 1, false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/user", queryUser, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, UserQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeQueryUser(userQuery, authObject->getPayload()));
	}


	//maple ----------------------------------------------------------------------------------------------------------------------------------------------------------


private: // ����ӿ�ִ�к���
	//��ѯ��ݳ�Ա
	IDmemberPageJsonVO::Wrapper execQueryIDmember(const IDmemberQuery::Wrapper& query, const PayloadDTO& payload);
	//�������˳�Ա
	AddPersonJsonVO::Wrapper execAddPerson(const AddPersonDTO::Wrapper& dto);
	//ɾ�����˳�Ա
	Uint64JsonVO::Wrapper execRemovePerson(const String& group_person);



	//���Ⱥ���Ա
	//��ӳɹ����ͽ������Ⱥ�����ƺ�Ⱥ��ȫ�Ƹ�����ȥ
	AddGroupMemberJsonVO::Wrapper execAddGroupMember(const AddGroupMemberReqDTO::Wrapper& dto, const PayloadDTO& payload);
	//ɾ��Ⱥ���Ա
	StringJsonVO::Wrapper execDelGroupMember(const DelGroupMemberDTO::Wrapper& dto);

	//�����֯��Ա
	//��ӳɹ����ͽ��������֯���ƺ���֯ȫ�Ƹ�����ȥ
	AddUnitMemberJsonVO::Wrapper execAddUnitMember(const AddUnitMemberReqDTO::Wrapper& dto);
	//ɾ����֯��Ա
	StringJsonVO::Wrapper execDelUnitMember(const DelUnitMemberDTO::Wrapper& dto);

	//��ѯȺ���б�
	GroupListPageJsonVO::Wrapper execQueryGroupList(const GroupListQuery::Wrapper& query);
	//����Ⱥ���Ա
	Uint64JsonVO::Wrapper execAddGroup(const GroupListDTO::Wrapper& dto);
	//��ѯ��ݳ�Ա


		//������ţ쭳�controller
		// ������ݳ�Ա
	Uint64JsonVO::Wrapper execAddAddOrRemoveIdentityMembers(const AddOrRemoveIdentityMembersDTO::Wrapper& dto);
	// ɾ����ݳ�Ա
	Uint64JsonVO::Wrapper execRemoveAddOrRemoveIdentityMembers(const String& id);
	// ��ȡȺ���Ա
	GetGroupMembersPageJsonVO::Wrapper execQueryGetGroupMembers(const GetGroupMembersQuery::Wrapper& query, const PayloadDTO& payload);
	// ��ȡ��֯��Ա
	GetOrganizationMembersPageJsonVO::Wrapper execQueryGetOrganizationMembers(const GetOrganizationMembersQuery::Wrapper& query, const PayloadDTO& payload);




	//ִ�л�ȡȺ����Ϣ
	GetGroupInfoJsonVO::Wrapper execQueryGroupInfo(const String& id);
	//ִ��ɾ��Ⱥ��
	StringJsonVO::Wrapper execDeleteGroup(const String& id);


	////�޸�Ⱥ����Ϣ
	Uint64JsonVO::Wrapper executeModifyGroup(const GroupDTO::Wrapper& dto);
	//��ȡ���˳�Ա
	UserPageJsonVO::Wrapper executeQueryUser(const UserQuery::Wrapper& query, const PayloadDTO& payload);








	

};

#include OATPP_CODEGEN_END(ApiController)

#endif 



/*
* 


//��ѯ��ݳ�Ա
	IDmemberPageJsonVO::Wrapper execQueryIDmember(const IDmemberQuery::Wrapper& query, const PayloadDTO& payload);
	//��ѯȺ���б�
	StringJsonVO::Wrapper execQueryGroupList(const PageQuery::Wrapper& condtion);


	//�������˳�Ա
	AddPersonJsonVO::Wrapper execAddPerson(const AddPersonDTO::Wrapper& dto);
	//ɾ�����˳�Ա
	Uint64JsonVO::Wrapper execRemovePerson(const String& group_person);
	//��ѯȺ���б�
	GroupListPageJsonVO::Wrapper execQueryGroupList(const GroupListQuery::Wrapper& query);
	//����Ⱥ���Ա
	Uint64JsonVO::Wrapper execAddGroup(const GroupListDTO::Wrapper& dto);
	//��ѯ��ݳ�Ա


	//���Ⱥ���Ա
	//��ӳɹ����ͽ������Ⱥ�����ƺ�Ⱥ��ȫ�Ƹ�����ȥ
	AddGroupMemberJsonVO::Wrapper execAddGroupMember(const AddGroupMemberReqDTO::Wrapper& dto,const PayloadDTO& payload);
	//ɾ��Ⱥ���Ա
	StringJsonVO::Wrapper execDelGroupMember(const DelGroupMemberDTO::Wrapper& dto);

	//�����֯��Ա
	//��ӳɹ����ͽ��������֯���ƺ���֯ȫ�Ƹ�����ȥ
	AddUnitMemberJsonVO::Wrapper execAddUnitMember(const AddUnitMemberReqDTO::Wrapper& dto);
	//ɾ����֯��Ա
	StringJsonVO::Wrapper execDelUnitMember(const DelUnitMemberDTO::Wrapper& dto);

	//ִ�л�ȡȺ����Ϣ
	GetGroupInfoJsonVO::Wrapper execQueryGroupInfo(const String& id);
	//ִ��ɾ��Ⱥ��
	StringJsonVO::Wrapper execDeleteGroup(const String& id);

	//������ţ쭳�controller
	// ������ݳ�Ա
	Uint64JsonVO::Wrapper execAddAddOrRemoveIdentityMembers(const AddOrRemoveIdentityMembersDTO::Wrapper& dto);
	// ɾ����ݳ�Ա
	Uint64JsonVO::Wrapper execRemoveAddOrRemoveIdentityMembers(const String& id);
	// ��ȡȺ���Ա
	GetGroupMembersPageJsonVO::Wrapper execQueryGetGroupMembers(const GetGroupMembersQuery::Wrapper& query, const PayloadDTO& payload);
	// ��ȡ��֯��Ա
	GetOrganizationMembersPageJsonVO::Wrapper execQueryGetOrganizationMembers(const GetOrganizationMembersQuery::Wrapper& query, const PayloadDTO& payload);








	//��ȡȺ���б�
	ENDPOINT_INFO(queryGroupList) {
		// general
		// �������;
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("grouplist.get.summary"));
		//����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// �����ҳ��ѯ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(GroupListPageDTO);
		// ����������ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("group.field.id"), "1234", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("group.field.name"), "zhangsan", false);
	}
	//����Ⱥ���ѯ�ӿ�
	ENDPOINT(API_M_GET, "/organization-group/id-grouplist", queryGroupList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {

		//��������
		API_HANDLER_QUERY_PARAM(condtion, GroupListQuery, params);
		//��Ӧ���

		API_HANDLER_RESP_VO(execQueryGroupList(condtion));
	}

	//��������Ⱥ��
	ENDPOINT_INFO(addGroup) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("grouplist.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GroupListPageJsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/organization-group/add-group", addGroup, BODY_DTO(GroupListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddGroup(dto));
	}



	//����Ⱥ���Ա����������ӿڣ���������������
	API_DEF_ENDPOINT_INFO_AUTH( ZH_WORDS_GETTER("groupMember.add.put.summary"), addGroupMember, AddGroupMemberJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/groupMember/add", addGroupMember, BODY_DTO(AddGroupMemberReqDTO::Wrapper, dto), execAddGroupMember(dto));
	//����Ⱥ���Ա��ɾ������ӿڣ���������������
	API_DEF_ENDPOINT_INFO_AUTH( ZH_WORDS_GETTER("groupMember.del.put.summary"), delGroupMember, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/groupMember/del", delGroupMember, BODY_DTO(DelGroupMemberDTO::Wrapper, dto), execDelGroupMember(dto));

	//������֯��Ա�������ӿڴ�����������������
	API_DEF_ENDPOINT_INFO_AUTH( ZH_WORDS_GETTER("UnitMember.add.put.summary"), addUnitMember, AddUnitMemberJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/unitMember/add", addUnitMember, BODY_DTO(AddUnitMemberReqDTO::Wrapper, dto), execAddUnitMember(dto));
	//������֯��Ա��ɾ���ӿڴ�����������������
	API_DEF_ENDPOINT_INFO_AUTH( ZH_WORDS_GETTER("UnitMember.del.put.summary"), delUnitMember, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/unitMember/del", delUnitMember, BODY_DTO(DelUnitMemberDTO::Wrapper, dto), execDelUnitMember(dto));

	//��ѯ��ݳ�Ա
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryIDmember) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("organization.group.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(IDmemberPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "xunitLevelName", ZH_WORDS_GETTER("organization.group.field.xunitLevelName"), ZH_WORDS_GETTER("organization.group.field.yname.qqcy"), false);
	}
	// 3.2 �����ѯ�ӿڴ���
	//ENDPOINT(API_M_GET, "/organization-group/id-member", queryIDmember, QUERY(String, xunique), API_HANDLER_AUTH_PARAME) {
	ENDPOINT(API_M_GET, "/organization-group/id-member", queryIDmember, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(idmemberQuery, IDmemberQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryIDmember(idmemberQuery, authObject->getPayload()));
	}

	//ɾ��Ⱥ��ӿڣ�ʹ��int orderNumber
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(RemoveGroup) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("groupManagement.groupInfo.delete.summary"), Uint64JsonVO::Wrapper);
	//	 ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "orderNumber", ZH_WORDS_GETTER("groupManagement.groupInfo.field.orderNumber"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/groupManagement/delete-group", RemoveGroup, PATH(UInt64, orderNumber), execDeleteGroup(orderNumber));

	//���Ӹ��˳�Ա
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addPerson) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("organization.group.post.summary"));
	//	 ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AddPersonJsonVO);
	}
//	 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/organization-group/add-person", addPerson, BODY_DTO(AddPersonDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
	//	 ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddPerson(dto));
	}

//	ɾ�����˳�Ա
//	 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removePerson) {
	//	 �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("organization.group.delete.summary"), Uint64JsonVO::Wrapper);
	//	 ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(Vector<String>, "group_person", ZH_WORDS_GETTER("organization.group.field.group_person"), Vector<String>{}, true);
		API_DEF_ADD_PATH_PARAMS(String, "group_person", ZH_WORDS_GETTER("organization.group.field.group_person"), "1", true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/organization-group/delete-person/{group_person}", removePerson, PATH(Vector<String>, group_person), execRemovePerson(group_person));
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/organization-group/delete-person/{group_person}", removePerson, PATH(String, group_person), execRemovePerson(group_person));


	////����Ⱥ���Ա����������ӿڣ���������������
	//API_DEF_ENDPOINT_INFO_AUTH( ZH_WORDS_GETTER("groupMember.add.put.summary"), addGroupMember, AddGroupMemberJsonVO::Wrapper);
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/groupMember/add", addGroupMember, BODY_DTO(AddGroupMemberReqDTO::Wrapper, dto), execAddGroupMember(dto,authObject->getPayload()));
	////����Ⱥ���Ա��ɾ������ӿڣ���������������
	//API_DEF_ENDPOINT_INFO_AUTH( ZH_WORDS_GETTER("groupMember.del.put.summary"), delGroupMember, StringJsonVO::Wrapper);
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/groupMember/del", delGroupMember, BODY_DTO(DelGroupMemberDTO::Wrapper, dto), execDelGroupMember(dto));

	////������֯��Ա�������ӿڴ�����������������
	//API_DEF_ENDPOINT_INFO_AUTH( ZH_WORDS_GETTER("unitMember.add.put.summary"), addUnitMember, AddUnitMemberJsonVO::Wrapper);
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/unitMember/add", addUnitMember, BODY_DTO(AddUnitMemberReqDTO::Wrapper, dto), execAddUnitMember(dto));
	////������֯��Ա��ɾ���ӿڴ�����������������
	//API_DEF_ENDPOINT_INFO_AUTH( ZH_WORDS_GETTER("unitMember.del.put.summary"), delUnitMember, StringJsonVO::Wrapper);
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/unitMember/del", delUnitMember, BODY_DTO(DelUnitMemberDTO::Wrapper, dto), execDelUnitMember(dto));

	//���ǲ���д��controller
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryGroupInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("groupManagement.groupInfo.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetGroupInfoJsonVO);
		// �����ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("groupManagement.groupInfo.field.id"), "111dw212d", true);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/group/get-groupInfo", queryGroupInfo, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryGroupInfo(id));
	}

	//// 3.1 ����ɾ���ӿ�����
	//ENDPOINT_INFO(RemoveGroup) {
	//	// �������ͷ��������Լ���Ȩ֧��
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("groupManagement.groupInfo.delete.summary"), StringJsonVO::Wrapper);
	//	// ��������·������˵��
	//	//API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("groupManagement.groupInfo.id"), "111", true);
	//}
	//// 3.2 ����ɾ���ӿڴ���
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/group/delete-group/{id}", RemoveGroup, PATH(String, id), execDeleteGroup(id));




	//������ţ쭳�controller
		//������ݳ�Ա
		// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addAddOrRemoveIdentityMembers) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/org/AddOrRemoveIdentityMembers", addAddOrRemoveIdentityMembers, BODY_DTO(AddOrRemoveIdentityMembersDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddAddOrRemoveIdentityMembers(dto));
	}

	//ɾ����ݳ�Ա
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeAddOrRemoveIdentityMembers) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		//API_DEF_ADD_PATH_PARAMS(String, "groupxid", ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id"), "1", false);
		//API_DEF_ADD_PATH_PARAMS(String, "xidentityList", ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.xidentityList"), "2", false);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/org/AddOrRemoveIdentityMembers/{groupxid}", removeAddOrRemoveIdentityMembers, PATH(String, groupxid),execRemoveAddOrRemoveIdentityMembers(groupxid));


	//��ȡȺ���Ա
		// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryGetGroupMembers) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.get.groupmembers"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetGroupMembersPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "groupxid", ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id"), "li", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/org/GetGroupMembers", queryGetGroupMembers, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, GetGroupMembersQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryGetGroupMembers(userQuery, authObject->getPayload()));
	}

	//��ȡ��֯��Ա
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryGetOrganizationMembers) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.get.organizationmembers"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetOrganizationMembersPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "groudxid", ZH_WORDS_GETTER("AddOrRemoveIdentityMembers.field.id"), "l", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/query/GetOrganizationMembers", queryGetOrganizationMembers, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, GetOrganizationMembersQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryGetOrganizationMembers(userQuery, authObject->getPayload()));
	}
*/








/*
//��������Ⱥ��
ENDPOINT_INFO(addGroup) {
	// ����ӿڱ���
	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("grouplist.add.summary"));
	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	API_DEF_ADD_AUTH();
	// ������Ӧ������ʽ
	API_DEF_ADD_RSP_JSON_WRAPPER(GroupListPageJsonVO);
}
// 3.2 ���������ӿڴ���
ENDPOINT(API_M_POST, "/organization-group/add-group", addGroup, BODY_DTO(GroupListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
	// ����ִ�к�����Ӧ���
	API_HANDLER_RESP_VO(execAddGroup(dto));
}
*/

/*

//����Ⱥ���Ա����������ӿڣ���������������
API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("groupMember.add.put.summary"), addGroupMember, AddGroupMemberJsonVO::Wrapper);
API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/groupMember/add", addGroupMember, BODY_DTO(AddGroupMemberReqDTO::Wrapper, dto), execAddGroupMember(dto));
//����Ⱥ���Ա��ɾ������ӿڣ���������������
API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("groupMember.del.put.summary"), delGroupMember, StringJsonVO::Wrapper);
API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/groupMember/del", delGroupMember, BODY_DTO(DelGroupMemberDTO::Wrapper, dto), execDelGroupMember(dto));


//������֯��Ա�������ӿڴ�����������������
API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("UnitMember.add.put.summary"), addUnitMember, AddUnitMemberJsonVO::Wrapper);
API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/unitMember/add", addUnitMember, BODY_DTO(AddUnitMemberReqDTO::Wrapper, dto), execAddUnitMember(dto));
//������֯��Ա��ɾ���ӿڴ�����������������
API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("UnitMember.del.put.summary"), delUnitMember, StringJsonVO::Wrapper);
API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/unitMember/del", delUnitMember, BODY_DTO(DelUnitMemberDTO::Wrapper, dto), execDelUnitMember(dto));

// 3.1 �����ѯ�ӿ�����
ENDPOINT_INFO(queryGroupInfo) {
	// ����ӿڱ���
	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("groupManagement.groupInfo.get.summary"));
	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	API_DEF_ADD_AUTH();
	// ������Ӧ������ʽ
	//API_DEF_ADD_RSP_JSON_WRAPPER(GetGroupInfoJsonVO);
	// �����ѯ��������
	API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("groupManagement.groupInfo.field.id"), "111dw212d", true);
}
// 3.2 �����ѯ�ӿڴ���
ENDPOINT(API_M_GET, "/groupManagement/get-groupInfo", queryGroupInfo, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
	// ����ִ�к�����Ӧ���
	API_HANDLER_RESP_VO(execQueryGroupInfo(id));
}

//ɾ��Ⱥ��ӿڣ�ʹ��int orderNumber
// 3.1 ����ɾ���ӿ�����
ENDPOINT_INFO(RemoveGroup) {
	// �������ͷ��������Լ���Ȩ֧��
	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("groupManagement.groupInfo.delete.summary"), Uint64JsonVO::Wrapper);
	// ��������·������˵��
	API_DEF_ADD_PATH_PARAMS(UInt64, "orderNumber", ZH_WORDS_GETTER("groupManagement.groupInfo.field.orderNumber"), 1, true);
}
// 3.2 ����ɾ���ӿڴ���
API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/groupManagement/delete-group", RemoveGroup, PATH(UInt64, orderNumber), execDeleteGroup(orderNumber));


//����Ⱥ���Ա
//StringJsonVO::Wrapper execAddGroup(const GroupListDTO::Wrapper& dto);
//��ѯ��ݳ�Ա
//��ѯ��ݳ�Ա
//IDmemberJsonVO::Wrapper execQueryIDmember(const String& xunique, const PayloadDTO& payload);

////���Ⱥ���Ա
////��ӳɹ����ͽ������Ⱥ�����ƺ�Ⱥ��ȫ�Ƹ�����ȥ
//AddGroupMemberJsonVO::Wrapper execAddGroupMember(const AddGroupMemberReqDTO::Wrapper& dto);
////ɾ��Ⱥ���Ա
//StringJsonVO::Wrapper execDelGroupMember(const DelGroupMemberDTO::Wrapper& dto);


//�����֯��Ա
//��ӳɹ����ͽ��������֯���ƺ���֯ȫ�Ƹ�����ȥ
//AddUnitMemberJsonVO::Wrapper execAddUnitMember(const AddUnitMemberReqDTO::Wrapper& dto);
//ɾ����֯��Ա
//StringJsonVO::Wrapper execDelUnitMember(const DelUnitMemberDTO::Wrapper& dto);

//ִ�л�ȡȺ����Ϣ
//GetGroupInfoJsonVO::Wrapper execQueryGroupInfo(const String& id);
//ִ��ɾ��Ⱥ��
//Uint64JsonVO::Wrapper execDeleteGroup(const UInt64& orderNumber);


	*/

	//��ѯ��ݳ�Ա
	/*
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryIDmember) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("organization.group.get.summary"));
		//API_DEF_ADD_TITLE("this is the first obj");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(IDmemberJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "xunique", ZH_WORDS_GETTER("organization.group.field.xunique"), "1", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/organization-group/id-member", queryIDmember, QUERY(String, xunique), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		//API_HANDLER_QUERY_PARAM(userQuery, SampleQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryIDmember(xunique, authObject->getPayload()));
	}
	*/

	/*
	////��ȡȺ���б�
//ENDPOINT_INFO(queryGroupList) {
//	// general
//	// �������;
//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("grouplist.get.summary"));
//	//����Ĭ����Ȩ����

	////��ȡȺ���б�
	//ENDPOINT_INFO(queryGroupList) {
	//	// general
	//	// �������;
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("grouplist.get.summary"));
	//	//����Ĭ����Ȩ����
	//	API_DEF_ADD_AUTH();
	//	// �����ҳ��ѯ��������
	//	API_DEF_ADD_RSP_JSON_WRAPPER(GroupListPageDTO);
	//	// ����������ѯ��������
	//	API_DEF_ADD_PAGE_PARAMS();
	//	API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("group.field.id"), "1234", true);
	//	API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("group.field.name"), "zhangsan", false);
	//}
	////����Ⱥ���ѯ�ӿ�
	//ENDPOINT(API_M_GET, "/organization-group/id-grouplist", queryGroupList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
	////��������Ⱥ��
	//ENDPOINT_INFO(addGroup) {
	//	// ����ӿڱ���
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("grouplist.add.summary"));
	//	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	//	API_DEF_ADD_AUTH();
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(GroupListPageJsonVO);
	//}
	//// 3.2 ���������ӿڴ���
	//ENDPOINT(API_M_POST, "/organization-group/add-group", addGroup, BODY_DTO(GroupListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
	//	// ����ִ�к�����Ӧ���
	//	API_HANDLER_RESP_VO(execAddGroup(dto));
	//}

	//���� ��һ��ģ�û���컨�壩

	////��ѯ��ݳ�Ա
	//// 3.1 �����ѯ�ӿ�����
	//ENDPOINT_INFO(queryIDmember) {
	//	// ����ӿڱ���
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("organization.group.get.summary"));
	//	//API_DEF_ADD_TITLE("this is the first obj");
	//	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	//	API_DEF_ADD_AUTH();
	//	// �����ҳ��ѯ��������
	//	API_DEF_ADD_RSP_JSON_WRAPPER(GroupListPageJsonVO);
	//	// ����������ѯ��������
	//	API_DEF_ADD_PAGE_PARAMS();
	//	API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("group.field.id"), "", false);
	//	API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("group.field.name"), "string", false);
	//}
	////����Ⱥ���ѯ�ӿ�
	//ENDPOINT(API_M_GET, "/organization-group/id-grouplist", queryGroupList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {

	//	//��������
	//	API_HANDLER_QUERY_PARAM(condtion, GroupListQuery, params);
	//	//��Ӧ���

	//	API_HANDLER_RESP_VO(execQueryGroupList(condtion));
	//}

	//���� ��һ��ģ�û���컨�壩

		//	//��������
	//	API_HANDLER_QUERY_PARAM(condtion, GroupListQuery, params);
	//	//��Ӧ���

	//	API_HANDLER_RESP_VO(execQueryGroupList(condtion));
	//}


	*/
	//ע���������ע��
//#endif // !_ORGANIZATIONGROUPCONTROLLER_H_#pragma once
