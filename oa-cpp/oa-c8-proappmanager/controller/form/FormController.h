#pragma once
#ifndef _FORMCONTROLLER_H
#define _FORMCONTROLLER_H

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/form/FormListDTO.h"

#include "domain/vo/form/FormCategoryVO.h"
#include "domain/vo/form/FormListVO.h"
#include "domain/vo/form/FormInfoVO.h"
#include "domain/query/form/FormListQuery.h"
#include "domain/dto/form/OperateFormDTO.h"

#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class FormController :public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(FormController);//�궨�� ΪFormController ����ӹ��캯���� createShared ����

public:// ����ӿ�

	//������
	//��ȡ������ӿ�����
	ENDPOINT_INFO(queryFormInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("form.info.get.summary"));
		//// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FormInfoJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("form.field.xid"), "1234", true);
	}
	// �����ȡ������ӿڴ���
	ENDPOINT(API_M_GET, "/process-app-manager/form/query-info", queryFormInfo, QUERY(String, xid), API_HANDLER_AUTH_PARAME) //API_HANDLER_AUTH_PARAME
	{

		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryFormInfo(xid));
	}


	//���б�
	//��ȡ���б�ӿ�����
	ENDPOINT_INFO(queryFormList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("form.list.get.summary"));
		//// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		 //������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FormListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "xcategory", ZH_WORDS_GETTER("form.field.xcategory"),"111", false);//��������
		API_DEF_ADD_QUERY_PARAMS(String, "xapplication", ZH_WORDS_GETTER("form.field.xapplication"),"111", true);//����Ӧ��
	}
	// �����ȡ���б�ӿڴ���
	ENDPOINT(API_M_GET, "/process-app-manager/form/query-list", queryFormList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(Query, FormListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryFormList(Query));
	}

	//�����ͼ�����
	//��ȡ�����ͼ������ӿ�����
	ENDPOINT_INFO(queryFormCategory) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("form.category.get.summary"));
		//// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FormCategoryJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "xapplication", ZH_WORDS_GETTER("form.field.xapplication"), "111", true);//����Ӧ��
	}
	// �����ȡ���б�ӿڴ���
	ENDPOINT(API_M_GET, "/process-app-manager/form/query-category", queryFormCategory, QUERY(String, xapplication), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryFormCategory(xapplication));
	}

	// ������
	ENDPOINT_INFO(addForm) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("form.add.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ���崴�����б�ӿڴ���
	ENDPOINT(API_M_POST, "/process-app-manager/form/add", addForm, BODY_DTO(OperateFormDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddForm(dto, authObject->getPayload()));
	}

	// �޸ı�
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("form.modify.get.summary"), modifyForm, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/process-app-manager/form/modify", modifyForm, BODY_DTO(OperateFormDTO::Wrapper, dto), execModifyForm(dto, authObject->getPayload()));
	
	// ɾ����
	ENDPOINT_INFO(removeForm) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("form.delete.get.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("form.field.id"), "", true);
	}
	// ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/process-app-manager/form/remove/{id}", removeForm, PATH(String, id), execRemoveForm(id));

private: // ����ӿ�ִ�к���

	// ִ�л�ȡ�����麯��
	FormInfoJsonVO::Wrapper execQueryFormInfo(const String& xid);

	// ִ�л�ȡ���б���
	FormListPageJsonVO::Wrapper execQueryFormList(const FormListQuery::Wrapper& userQuery);

	// ִ�л�ȡ�����ͼ���������
	FormCategoryJsonVO::Wrapper execQueryFormCategory(const String& xapplication);

	// ��ӱ�
	StringJsonVO::Wrapper execAddForm(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload);
	// �޸ı�
	StringJsonVO::Wrapper execModifyForm(const OperateFormDTO::Wrapper& dto, const PayloadDTO& payload);
	// ɾ����
	StringJsonVO::Wrapper execRemoveForm(const String& id);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FORMCONTROLLER_H