#pragma once

#ifndef _FORMTEMPLATECATEGORYCONTROLLER_H_
#define _FORMTEMPLATECATEGORYCONTROLLER_H_

#include "oatpp-swagger/Types.hpp"
#include "domain/dto/FormTemplateCategoryDTO.h"
#include "domain/vo/FormTemplateCategoryVO.h"
#include "domain/dto/PageDTO.h"
#include "domain/query/FormTemplateQuery.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController)
class FormTemplateCategoryController :public oatpp::web::server::api::ApiController
{
public:// ����ӿ�
	// ����������������
	API_ACCESS_DECLARE(FormTemplateCategoryController);//�궨�� ΪFormController ����ӹ��캯���� createShared ����

	//�����ͼ�����
	//��ȡ�����ͼ������ӿ�����
	ENDPOINT_INFO(queryFormCategory) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("formTemplate.category.get.summary"));
		//// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FormTemplateCategoryJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "xapplication", ZH_WORDS_GETTER("formTemplate.field.xapplication"), "111", true);//����Ӧ��
	}
	// �����ȡ���б�ӿڴ���
	ENDPOINT(API_M_GET, "/base/query-category", queryFormCategory, QUERY(String, xid)) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryFormCategory(xid));
	}
private: // ����ӿ�ִ�к���
	// ִ�л�ȡ�����ͼ���������
	FormTemplateCategoryJsonVO::Wrapper execQueryFormCategory(const String& xid);

};


#include OATPP_CODEGEN_END(ApiController)

#endif