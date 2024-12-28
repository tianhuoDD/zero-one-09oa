#pragma once
#ifndef _ATTRIBAPICLIENT_H_
#define _ATTRIBAPICLIENT_H_

// 1 �������ͷ�ļ�
#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * ��дʾ��ApiClient����ʾ��������ʽ����
 */
class Attrib_modify_ApiClient : public oatpp::web::client::ApiClient // 2 �̳������
{
	// 3 ����ApiClient������ʹ�ú�---��ʼ
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 ��ʼ������
	API_CLIENT_INIT(Attrib_modify_ApiClient);

	// 5 ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�

	// ͨ��ID��ѯ
	API_CALL(API_M_GET, "/Attrib/query-one", queryById, API_HANDLER_AUTN_HEADER, QUERY(UInt64, id));
	// ��������ѯ
	API_CALL(API_M_GET, "/Attrib/query-all", queryAll, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, QUERY(String, name));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 ȡ��ApiClient������ʹ�ú�---����
};

#endif // !_SAMPLEAPICLIENT_H_