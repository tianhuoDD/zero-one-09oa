#pragma once
#ifndef _DATACONFIGLISTCONTROLLER_H_
#define _DATACONFIGLISTCONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/data/DataDetailVO.h"
#include "domain/vo/data/DataListVO.h"
#include "domain/dto/data/DataOperatorDTO.h"
#include "domain/vo/data/DataOperatorVO.h"
#include "domain/query/data/DataListQuery.h"
#include "domain/query/data/DataDetailQuery.h"
#include "service/data/DataOpService.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class DataController : public oatpp::web::server::api::ApiController {
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(DataController);

public://����ӿ�

	//�������ݽӿ�����
	ENDPOINT_INFO(AddDataConfiguration) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("oprator.add.summray"));
		//����Ȩ�޷���
		API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		//����������Ӧһ���ַ�����
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}

	ENDPOINT(API_M_POST, "/process-app-manager/data/add", AddDataConfiguration, BODY_DTO(AddDataDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddDataConfiguration(dto));
	}


	ENDPOINT_INFO(ModifyDataConfiguration) {
		//�޸����ݽӿ�����
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("oprator.modify.summray"));
		//����Ȩ�޷���
		API_DEF_ADD_AUTH();
		//������Ӧ������ʽ 
		//������Ӧһ���ַ���
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	
	ENDPOINT(API_M_PUT, "/process-app-manager/data/modify", ModifyDataConfiguration, BODY_DTO(DataOperatorDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME)
	{
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execModifyDataConfiguration(dto));
	}

	ENDPOINT_INFO(DeleteDataConfiguration) {
		//ɾ�����ݽӿ�����
		//�˴�����Ψһ��ʶɾ��
		//ɾ���ӿ�����
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("oprator.delete.summray"), StringJsonVO::Wrapper);
		//����Ȩ�����
		API_DEF_ADD_AUTH();
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("dataconfiguration.datamessage.id"), "", true);
	}
	

	ENDPOINT(API_M_DEL, "/process-app-manager/data/remove/{id}", DeleteDataConfiguration, PATH(String, id), API_HANDLER_AUTH_PARAME)
	{
		//String itemid = dto->itemid;
		API_HANDLER_RESP_VO(execDeleteDataConfiguration(id));
	}


	//��ȡ���������б�ӿ�
	//��ѯ�ӿ�����
	ENDPOINT_INFO(queryDataConfigList) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("config.list.get.summary"), DataListPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "appid", ZH_WORDS_GETTER("config.list.get.summary"), "", true);
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/process-app-manager/data/query-list", queryDataConfigList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(query, DataListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryDataConfigList(query, authObject->getPayload()));
	}

	// ��ȡ������������ӿ�
	// 4.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryDataConfigDetail) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("config.detail.get.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DataDetailJsonVO);
		//API_DEF_ADD_QUERY_PARAMS(String, "appid", ZH_WORDS_GETTER("config.detail.field.appid"), "13d212", true);
		API_DEF_ADD_QUERY_PARAMS(String, "dataid", ZH_WORDS_GETTER("config.detail.field.dataid"), "83496759-2037-440d-8e4f-27ede60f85bd", true);
	}
	// 4.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/process-app-manager/data/query-detail", queryDataConfigDetail, QUERY(String, dataid), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryDataConfigDetail(dataid, authObject->getPayload()));
	}


private://����ӿ�ִ�к���

	//���������ĵ���ִ�к��� ��Ҫ������� һ��dto
	StringJsonVO::Wrapper execAddDataConfiguration(const AddDataDTO::Wrapper& dto);

	//�޸������ĵ���ִ�к��� ��Ҫ������� һ��dto
	StringJsonVO::Wrapper execModifyDataConfiguration(const DataOperatorDTO::Wrapper& dto);

	//ɾ�������ĵ���ִ�к��� ��Ҫ������� һ��String
	StringJsonVO::Wrapper execDeleteDataConfiguration(const String& id);

	//ִ�л�ȡ���������б�
	DataListPageJsonVO::Wrapper execQueryDataConfigList(const DataListQuery::Wrapper& query, const PayloadDTO& payload);

	// ִ�л�ȡ������������
	DataDetailJsonVO::Wrapper execQueryDataConfigDetail(const std::string& dataid, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _DATACONFIGLISTCONTROLLER_H_
