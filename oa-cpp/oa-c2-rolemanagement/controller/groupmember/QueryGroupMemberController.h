#pragma once
#ifndef _QUERYGROUPMEMBER_CONTROLLER_
#define _QUERYGROUPMEMBER_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include"domain/vo/GroupMember/GetGroupMemberVO.h"
#include"domain/dto/GroupMember/GetGroupMemberDTO.h"
#include "domain/query/GroupMember/GroupMemberQuery.h"
//����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class QueryGroupMemberController : public oatpp::web::server::api::ApiController //�̳п�����
{
	//����������������
	API_ACCESS_DECLARE(QueryGroupMemberController);
	//����ӿ�
public:
	//�����ѯ�ӿ�����
	ENDPOINT_INFO(queryGroupMember) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("queryGroupMember.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetGroupMemberPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "groupname", ZH_WORDS_GETTER("queryGroupMember.field.name"), "zero-one", true);
		API_DEF_ADD_QUERY_PARAMS(String, "groupnameA", ZH_WORDS_GETTER("queryGroupMember.field.sex"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "groupdes", ZH_WORDS_GETTER("queryGroupMember.field.sex"), "", false);
	}
	//�����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/queryGroupMember", queryGroupMember, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, GroupMemberQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryGroupMember(userQuery, authObject->getPayload()));
	}
private:
	//��ҳ��ѯ����
	GetGroupMemberPageJsonVO::Wrapper execQueryGroupMember(const GroupMemberQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _QUERYGROUPMEMBER_CONTROLLER_