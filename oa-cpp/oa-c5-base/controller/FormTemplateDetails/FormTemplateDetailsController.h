#pragma once

#ifndef _FORMTEMPLATEDETAILSCONTROLLER_H_
#define _FORMTEMPLATEDETAILSCONTROLLER_H_

#include "oatpp-swagger/Types.hpp"
#include "domain/dto/FormTemplateDetailsDTO.h"
#include "domain/vo/FormTemplateDetailsVO.h"
#include "domain/dto/PageDTO.h"
#include "domain/query/FormTemplateQuery.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController)

class FormTemplateDetailsController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(FormTemplateDetailsController);

public:
	//������
	//��ȡ������ӿ�����
	ENDPOINT_INFO(queryFormInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("formTemplate.get.summary"));
		//// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FormTemplateDetailsJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("form.field.xid"), "1234", true);
	}
	// �����ȡ������ӿڴ���
	ENDPOINT(API_M_GET, "/base/query-info", queryFormInfo, QUERY(String, xid)) //API_HANDLER_AUTH_PARAME
	{
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryFormInfo(xid));
	}

private:
	// ִ�л�ȡ�����麯��
	FormTemplateDetailsJsonVO::Wrapper execQueryFormInfo(const String& xid);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // _FORMTEMPLATEDETAILSCONTROLLER_H_
