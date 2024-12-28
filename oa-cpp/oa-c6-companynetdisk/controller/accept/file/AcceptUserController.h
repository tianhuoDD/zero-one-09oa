#pragma once
#ifndef _ACCEPTUSERCONTROLLER_H_
#define _ACCEPTUSERCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/accept/file/AcceptUserListVO.h"
#include "domain/query/accept/file/AcceptUserListQuery.h"
#include "domain/dto/accept/file/AcceptUserListDTO.h"




// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class AcceptUserController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{

	// 2 ����������������
	API_ACCESS_DECLARE(AcceptUserController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(querySample) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("tital.acceptuser"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AcceptUserListJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		//// ����������ѯ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "Userid", ZH_WORDS_GETTER("accept.user.id"), "123", true);
	}
	// 3.2 �����ѯ�ӿڴ��� /companynetdisk/query-filelist-filed
	ENDPOINT(API_M_GET, "/companynetdisk/query-userlist-filed", querySample, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(acceptuserquery, AcceptUserListQuery, queryParams);
		//�Ӹ��ػ�ȡ��¼�û���id
		acceptuserquery->xid = authObject->getPayload().getId();
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execqueryUsersByXunique(acceptuserquery));
	}

private:
	AcceptUserListJsonVO::Wrapper execqueryUsersByXunique(const AcceptUserListQuery::Wrapper& query);

};


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SHAREUSERSCONTROLLER_