#pragma once

#ifndef _CALENDERGETCONTROLLER_H_
#define _CALENDERGETCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/calender/CalenderInfoDTO.h"
#include "domain/vo/calender/CalenderInfoVO.h"
#include "domain/dto/calender/CalenderListDTO.h"
#include "domain/vo/calender/CalenderListVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class CalenderGetController : public oatpp::web::server::api::ApiController {
	//	����������������
	API_ACCESS_DECLARE(CalenderGetController);

public:	//	����ӿ�


	/*
	//	��ȡ�����б� �ӿ�
	ENDPOINT_INFO(queryCalenderList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.get.summary_list"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CalenderListJsonVO);
		// �����ѯ��������(�û�Ψһid)
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("calender.user.xid"), "68", true);
	}
	//  ����ӿڴ���
	ENDPOINT(API_M_GET, "/schedule-calender/query-calenderlist", queryCalenderList, QUERY(String, xid), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ�ͣ���������һ����������Ҫ��������ע��
		//API_HANDLER_QUERY_PARAM(userQuery, SampleQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryCalenderList(xid));
	}
	*/


	//	��ȡ�����б� �ӿ�
	//	����ӿ�����
	ENDPOINT_INFO(queryCalenderList) {
		//	����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.get.summary_list"));
		//	����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//	������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CalenderListJsonVO);
		//	�����ѯ�����������û����кţ�
		//API_DEF_ADD_QUERY_PARAMS(String, "xdistinguishedName", ZH_WORDS_GETTER("calender.user.xdistinguishedName"), "1068", true);
	}

	//	����ӿڴ���
	ENDPOINT(API_M_GET, "/schedule/query-calenderlist-by-userid", queryCalenderList, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryCalenderList(authObject->getPayload()));
	}


	//	��ȡ�������� �ӿ�
	//  ����ӿ�����
	ENDPOINT_INFO(queryCalenderInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.get.summary_info"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CalenderInfoJsonVo);
		// �����ѯ��������(����Ψһid)
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("calender.field.xid"), "68", true);
	}
	//  ����ӿڴ���
	ENDPOINT(API_M_GET, "/schedule/query-calenderinfo-by-calenderid", queryCalenderInfo, QUERY(String, xid), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ�ͣ���������һ����������Ҫ��������ע��
		//API_HANDLER_QUERY_PARAM(userQuery, SampleQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryCalenderInfo(xid, authObject->getPayload()));
	}

private: //	����ӿ�ִ�к���

	//	���� ��ȡ�������� �ӿ�ִ�к�����������xid->����ID
	CalenderInfoJsonVo::Wrapper execQueryCalenderInfo(const String& xid, const PayloadDTO& payload);

	//	���� ��ȡ�����б� �ӿ�ִ�к�����������payload->������Ϣ
	//CalenderListJsonVO::Wrapper execQueryCalenderList(const PayloadDTO& payload);

	CalenderListJsonVO::Wrapper execQueryCalenderList(const PayloadDTO& payload);

};



#include OATPP_CODEGEN_END(ApiController)

#endif // !_CALENDERGETCONTROLLER_H_
