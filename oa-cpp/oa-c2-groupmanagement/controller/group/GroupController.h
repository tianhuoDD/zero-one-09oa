#pragma once
#ifndef _GROUP_CONTROLLER_
#define _GROUP_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/group/GroupDTO.h"
#include "domain/vo/group/GroupVO.h"
#include "domain/query/user/UserQuery.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class GroupController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(GroupController);
	// 3 ����ӿ�
public:
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("group.put.summary"), modifyGroup, StringJsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/group", modifyGroup, BODY_DTO(GroupDTO::Wrapper, dto), executeModifyGroup(dto));

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
		API_DEF_ADD_QUERY_PARAMS(Int32, "id", ZH_WORDS_GETTER("role.field.id"), 1, true);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/role-info", queryUser, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeQueryUser(id));
	}
private:
	// 3.3 ��ʾ�޸�����
	StringJsonVO::Wrapper executeModifyGroup(const GroupDTO::Wrapper& dto);

	UserPageJsonVO::Wrapper executeQueryUser(const String& id);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _GROUP_CONTROLLER_