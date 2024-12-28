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
	//����������������
	API_ACCESS_DECLARE(RoleManagementController);
public:
	//xiaodeng-----
	
	//ɾ��Ⱥ���Ա
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("role.put.adddelgroupmember.summary"), delgroupmember, Uint64JsonVO::Wrapper);
	// 
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/role/del-groupmember", delgroupmember, BODY_DTO(GroupMemberDTO::Wrapper, idList), execDelGroupMember(idList));

	// 3.1 ����Ⱥ���Ա
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("role.put.adddelgroupmember.summary"), addgroupmember, Uint64JsonVO::Wrapper);
	// 
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/role/add-groupmember", addgroupmember, BODY_DTO(GroupMemberDTO::Wrapper, idList), execAddGroupMember(idList));

	// ��ȡ��ɫ��Դ
	ENDPOINT_INFO(obtainRoleResource) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("role.get.roleResource.summary"), RoleResourceJsonVO::Wrapper);
	}
	// 
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/role/obtain-role-resource", obtainRoleResource, QUERY(String, id), execObtainRoleResource(id, authObject->getPayload()));

	// 3.1 �����޸Ľ�ɫ��Դ�ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("role.put.modifyAssignmentResource.summary"), modifyroleresource, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľ�ɫ��Դ�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/role/modify-role-resource", modifyroleresource, BODY_DTO(RoleResourceListDTO::Wrapper, roleResource), execModifyRoleResource(roleResource));
	// 3.1 ���������ӿ�����
	//xiaodeng---- -

	ENDPOINT_INFO(addRole) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("addrole.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// ����������������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("addrole.put.name"), "name", true);
		API_DEF_ADD_QUERY_PARAMS(String, "unique", ZH_WORDS_GETTER("addrole.put.unique"), "unique", true);
		API_DEF_ADD_QUERY_PARAMS(String, "description", ZH_WORDS_GETTER("addrole.put.desc"), "desc", true);
	}
	// 3.2 ���������ӿڴ��� , API_HANDLER_AUTH_PARAME
	ENDPOINT(API_M_POST, "/role/add-role", addRole, BODY_DTO(AddroleDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddRole(dto));
	}
/// ////////////////��ȡ��ɫ��Ϣ��ɾ����ɫ//////////////////
    // ��ȡ��ɫ��Ϣ
    ENDPOINT_INFO(queryGetrole) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("addroleDTO.information"));
        // ����Ĭ����Ȩ��������ѡ���壩
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(GetroleJsonVO);
        // �����ѯ��������
        API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("addroleDTO.field.key"), "", true);
    }

    // �����ѯ�ӿڴ���
    ENDPOINT(API_M_GET, "/role/query_roleinfo", queryGetrole, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(executQueryGetRole(id));
    }



    // ɾ����ɫ
    // 3.1 ����ɾ���ӿ�����
    ENDPOINT_INFO(removeSample) {
        // �������ͷ��������Լ���Ȩ֧��
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("addroleDTO.del"), String);
        // ��������·������˵��
        API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("addroleDTO.field.key"), "", true);
    }

    // 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/role/del-role", removeSample, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execRemoveRole(id));
	}



/// ////////////////��ȡ��ɫ��Ϣ��ɾ����ɫ//////////////////

	//�޸�role lhg
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("modifyrole.summary"), modifyRole, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/role/modify-role", modifyRole, BODY_DTO(UpdateRoleDTO::Wrapper, dto), execModifyRole(dto));

	//��ȡ��ɫ��personlist(��ҳ) lhg
	ENDPOINT_INFO(queryPersonList) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("querypersonlist.summary"), PersonListPageJsonVO::Wrapper);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "xunique", ZH_WORDS_GETTER("querypersonlist.unique"), "xxxx", true);
	}
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/role/query-person-list", queryPersonList, PersonListQuery, execQueryPersonList(query, authObject->getPayload()));

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryRolelist) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("rolelist.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(QueryRolePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������������
		API_DEF_ADD_QUERY_PARAMS(String, "key", ZH_WORDS_GETTER("rolelist.field.words"), "key", false);	
	}
	// 3.2 �����ѯ�ӿڴ��� , API_HANDLER_AUTH_PARAME
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/role/query-role-name", queryRolelist, QUERIES(QueryParams, queryParams),API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, QueryRoleQuery, queryParams);
		// ����ִ�к�����Ӧ��� authObject->getPayload()
		API_HANDLER_RESP_VO(execQueryRolelist(userQuery));
	}

	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------



	//������ӽӿ�����
	ENDPOINT_INFO(addMember) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("PersonMember.put.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//���������ӿڴ���
	ENDPOINT(API_M_PUT, "/role/add-person-member", addMember, BODY_DTO(PersonMemberDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddMember(dto));
	}
	//ɾ��Ⱥ���Ա
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("PersonMember.delete.summary"), delpersonmember, Uint64JsonVO::Wrapper);
	// 
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/role/del-person-member", delpersonmember, BODY_DTO(PersonMemberDTO::Wrapper, xpersonList), execDelPersonMember(xpersonList));

	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryPersonMember) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("PersonMember.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetPersonMemberPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "ROLE_XID", ZH_WORDS_GETTER("PersonMember.field.ROLE_XID"), "role_xid", true);
		
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/role/query-person-member", queryPersonMember, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, GetPersonMemberQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execGetPersonMember(userQuery, authObject->getPayload()));
	}
private:
	//ִ����ɾȺ���Ա
	Uint64JsonVO::Wrapper execAddGroupMember(const GroupMemberDTO::Wrapper& idList);
	Uint64JsonVO::Wrapper execDelGroupMember(const GroupMemberDTO::Wrapper& idList);
	RoleResourceJsonVO::Wrapper execObtainRoleResource(const String roleId, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execModifyRoleResource(const RoleResourceListDTO::Wrapper& roleResource);
	//lhg
	Uint64JsonVO::Wrapper execModifyRole(const UpdateRoleDTO::Wrapper& dto);
	//lhg
	PersonListPageJsonVO::Wrapper execQueryPersonList(const PersonListQuery::Wrapper& query, const PayloadDTO& payload);
	StringJsonVO::Wrapper execAddDelGroupMember(const GroupMemberDTO::Wrapper& idList);
	//ִ�����ӽ�ɫ
	Uint64JsonVO::Wrapper execAddRole(const AddroleDTO::Wrapper& dto);
	// ��ҳ��ѯ��ɫ����	, const PayloadDTO& payload
	QueryRolePageJsonVO::Wrapper execQueryRolelist(const QueryRoleQuery::Wrapper& query);

    //��ȡ��ɫ��Ϣ
    GetroleJsonVO::Wrapper executQueryGetRole(const String& id);

   //ɾ����ɫ
    StringJsonVO::Wrapper execRemoveRole(const String& id);




	// ���Ӹ��˳�Ա
	Uint64JsonVO::Wrapper execAddMember(const PersonMemberDTO::Wrapper& dto);

	// ɾ����Ա
	Uint64JsonVO::Wrapper execDelPersonMember(const PersonMemberDTO::Wrapper& xpersonList);
	
	// ��ʾ��ҳ��ѯ����
	GetPersonMemberPageJsonVO::Wrapper execGetPersonMember(const GetPersonMemberQuery::Wrapper& query, const PayloadDTO& payload);
};


#include OATPP_CODEGEN_END(ApiController)

#endif // !_ROLEMANAGEMENTCONTROLLER_H_
