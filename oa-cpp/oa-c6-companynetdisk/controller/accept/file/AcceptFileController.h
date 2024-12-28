#pragma once
#ifndef _ACCEPTFILECONTROLLER_H_
#define _ACCEPTFILECONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/accept/file/AcceptFileListVO.h"
#include "domain/query/accept/file/AcceptFileListQuery.h"
#include "domain/dto/accept/file/AcceptFileListDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class AcceptFileController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{

	// 2 ����������������
	API_ACCESS_DECLARE(AcceptFileController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(querySample)
	{
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("tital.acceptfile"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AcceptFileListJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "xperson", ZH_WORDS_GETTER("accept.file.upload"), "xiaogang@314159@P", true);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/companynetdisk/query-filelist-filed", querySample, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(acceptfilequery, AcceptFileListQuery, queryParams);
		//��ȡ���ص�xid
		acceptfilequery->xid = authObject->getPayload().getId();
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execqueryUsersByXunique(acceptfilequery));
	}

private:
	AcceptFileListJsonVO::Wrapper execqueryUsersByXunique(const AcceptFileListQuery::Wrapper& query);

};


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _ACCEPTFILECONTROLLER_H_